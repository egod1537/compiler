<#
.SYNOPSIS
Formats Bison/Yacc rule layout and its embedded C portions.

.DESCRIPTION
Scans the input once, normalizes rule alternatives without reordering tokens,
and batches the prologue, semantic actions, and epilogue into one clang-format
process. The write is rejected if the source changes while formatting.
#>
[CmdletBinding()]
param(
    [Parameter(Position = 0)]
    [string]$Path = "c.y",

    [ValidateRange(1, 600)]
    [int]$TimeoutSeconds = 60,

    [switch]$DryRun,
    [switch]$Check
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

function Find-MatchingBrace {
    param(
        [string]$Source,
        [int]$OpenIndex,
        [int]$Limit
    )

    $depth = 0
    $state = "code"
    $escaped = $false

    for ($i = $OpenIndex; $i -lt $Limit; $i++) {
        $ch = $Source[$i]
        $next = if ($i + 1 -lt $Limit) { $Source[$i + 1] } else { [char]0 }

        switch ($state) {
            "line-comment" {
                if ($ch -eq "`n") { $state = "code" }
                continue
            }
            "block-comment" {
                if ($ch -eq '*' -and $next -eq '/') {
                    $state = "code"
                    $i++
                }
                continue
            }
            "string" {
                if ($escaped) {
                    $escaped = $false
                } elseif ($ch -eq '\') {
                    $escaped = $true
                } elseif ($ch -eq '"') {
                    $state = "code"
                }
                continue
            }
            "char" {
                if ($escaped) {
                    $escaped = $false
                } elseif ($ch -eq '\') {
                    $escaped = $true
                } elseif ($ch -eq "'") {
                    $state = "code"
                }
                continue
            }
        }

        if ($ch -eq '/' -and $next -eq '/') {
            $state = "line-comment"
            $i++
        } elseif ($ch -eq '/' -and $next -eq '*') {
            $state = "block-comment"
            $i++
        } elseif ($ch -eq '"') {
            $state = "string"
        } elseif ($ch -eq "'") {
            $state = "char"
        } elseif ($ch -eq '{') {
            $depth++
        } elseif ($ch -eq '}') {
            $depth--
            if ($depth -eq 0) { return $i }
        }
    }

    throw "Unmatched semantic-action brace at offset $OpenIndex"
}

function Get-ActionSegments {
    param(
        [string]$Source,
        [int]$Start,
        [int]$End
    )

    $segments = [System.Collections.Generic.List[object]]::new()
    $state = "code"
    $escaped = $false

    for ($i = $Start; $i -lt $End; $i++) {
        $ch = $Source[$i]
        $next = if ($i + 1 -lt $End) { $Source[$i + 1] } else { [char]0 }

        switch ($state) {
            "line-comment" {
                if ($ch -eq "`n") { $state = "code" }
                continue
            }
            "block-comment" {
                if ($ch -eq '*' -and $next -eq '/') {
                    $state = "code"
                    $i++
                }
                continue
            }
            "string" {
                if ($escaped) {
                    $escaped = $false
                } elseif ($ch -eq '\') {
                    $escaped = $true
                } elseif ($ch -eq '"') {
                    $state = "code"
                }
                continue
            }
            "char" {
                if ($escaped) {
                    $escaped = $false
                } elseif ($ch -eq '\') {
                    $escaped = $true
                } elseif ($ch -eq "'") {
                    $state = "code"
                }
                continue
            }
        }

        if ($ch -eq '/' -and $next -eq '/') {
            $state = "line-comment"
            $i++
        } elseif ($ch -eq '/' -and $next -eq '*') {
            $state = "block-comment"
            $i++
        } elseif ($ch -eq '"') {
            $state = "string"
        } elseif ($ch -eq "'") {
            $state = "char"
        } elseif ($ch -eq '{') {
            $close = Find-MatchingBrace -Source $Source -OpenIndex $i -Limit $End
            $lineStart = $Source.LastIndexOf("`n", $i)
            if ($lineStart -lt 0) { $lineStart = 0 } else { $lineStart++ }
            $prefix = $Source.Substring($lineStart, $i - $lineStart)
            $indent = [regex]::Match($prefix, '^\s*').Value
            $original = $Source.Substring($i, $close - $i + 1)

            $segments.Add([pscustomobject]@{
                    Kind       = "action"
                    Start      = $i
                    Length     = $close - $i + 1
                    Content    = $Source.Substring($i + 1, $close - $i - 1)
                    Indent     = $indent
                    SingleLine = -not ($original.Contains("`n"))
                })
            $i = $close
        }
    }

    return $segments
}

function Invoke-ClangFormat {
    param(
        [string]$InputText,
        [string]$AssumeFilename,
        [int]$Timeout
    )

    $clangFormat = Get-Command clang-format -ErrorAction Stop
    $startInfo = [System.Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $clangFormat.Source
    $escapedFilename = $AssumeFilename.Replace('"', '\"')
    $startInfo.Arguments = "--assume-filename=`"$escapedFilename`" --fallback-style=LLVM"
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardInput = $true
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    $startInfo.CreateNoWindow = $true

    $process = [System.Diagnostics.Process]::new()
    $process.StartInfo = $startInfo
    if (-not $process.Start()) { throw "Failed to start clang-format" }

    $stdoutTask = $process.StandardOutput.ReadToEndAsync()
    $stderrTask = $process.StandardError.ReadToEndAsync()
    $process.StandardInput.Write($InputText)
    $process.StandardInput.Close()

    if (-not $process.WaitForExit($Timeout * 1000)) {
        try { $process.Kill($true) } catch { $process.Kill() }
        throw "clang-format exceeded the ${Timeout}s timeout"
    }

    $stdout = $stdoutTask.GetAwaiter().GetResult()
    $stderr = $stderrTask.GetAwaiter().GetResult()
    if ($process.ExitCode -ne 0) {
        throw "clang-format failed with exit code $($process.ExitCode): $stderr"
    }

    return $stdout
}

function Get-MarkerContent {
    param(
        [string]$Formatted,
        [int]$Id
    )

    $begin = "// __YFMT_BEGIN_${Id}__"
    $end = "// __YFMT_END_${Id}__"
    $beginIndex = $Formatted.IndexOf($begin, [System.StringComparison]::Ordinal)
    $endIndex = $Formatted.IndexOf($end, [System.StringComparison]::Ordinal)
    if ($beginIndex -lt 0 -or $endIndex -lt 0 -or $endIndex -le $beginIndex) {
        throw "clang-format output lost fragment marker $Id"
    }

    $contentStart = $Formatted.IndexOf("`n", $beginIndex) + 1
    return $Formatted.Substring($contentStart, $endIndex - $contentStart).TrimEnd("`r", "`n")
}

function Format-GrammarAlternative {
    param(
        [System.Collections.Generic.List[string]]$Tokens,
        [string]$Marker,
        [hashtable]$Actions,
        [int]$ColumnLimit = 88
    )

    $lines = [System.Collections.Generic.List[string]]::new()
    $current = "    $Marker"
    $currentHasContent = $false

    foreach ($token in $Tokens) {
        if ($token -match '^__YFMT_ACTION_(\d+)__$') {
            $actionId = [int]$Matches[1]
            if (-not $Actions.ContainsKey($actionId)) {
                throw "Missing formatted semantic action $actionId"
            }

            $action = [string]$Actions[$actionId]
            $actionLines = $action -split "`r?`n"
            if ($actionLines.Count -eq 1) {
                $separator = if ($current.EndsWith(' ')) { '' } else { ' ' }
                $candidate = $current + $separator + $actionLines[0]
                if ($candidate.Length -le $ColumnLimit) {
                    $current = $candidate
                    $currentHasContent = $true
                } else {
                    if ($currentHasContent -or $lines.Count -eq 0) {
                        $lines.Add($current.TrimEnd())
                    }
                    $lines.Add('    ' + $actionLines[0])
                    $current = '      '
                    $currentHasContent = $false
                }
                continue
            }

            if ($currentHasContent -or $lines.Count -eq 0) {
                $lines.Add($current.TrimEnd())
            }
            foreach ($actionLine in $actionLines) {
                if ([string]::IsNullOrWhiteSpace($actionLine)) {
                    $lines.Add('')
                } else {
                    $lines.Add('    ' + $actionLine.TrimEnd())
                }
            }
            $current = '      '
            $currentHasContent = $false
            continue
        }

        $separator = if ($current.EndsWith(' ')) { '' } else { ' ' }
        $candidate = $current + $separator + $token
        if ($currentHasContent -and $candidate.Length -gt $ColumnLimit) {
            $lines.Add($current.TrimEnd())
            $current = '      ' + $token
        } else {
            $current = $candidate
        }
        $currentHasContent = $true
    }

    if ($currentHasContent) {
        $lines.Add($current.TrimEnd())
    } elseif ($lines.Count -eq 0) {
        $lines.Add("    $Marker")
    }

    return $lines
}

function Format-GrammarSection {
    param(
        [string]$Grammar,
        [hashtable]$Actions,
        [string]$Newline
    )

    $pattern = '(?s:/\*.*?\*/)|(?m://[^\r\n]*)|__YFMT_ACTION_\d+__|[:|;]|[^\s:|;]+'
    $tokens = [System.Collections.Generic.List[string]]::new()
    foreach ($match in [regex]::Matches($Grammar, $pattern)) {
        $tokens.Add($match.Value)
    }

    $output = [System.Collections.Generic.List[string]]::new()
    $index = 0
    while ($index -lt $tokens.Count) {
        while ($index -lt $tokens.Count -and
            ($tokens[$index].StartsWith('//') -or $tokens[$index].StartsWith('/*'))) {
            if ($output.Count -gt 0 -and $output[$output.Count - 1] -ne '') {
                $output.Add('')
            }
            foreach ($commentLine in ($tokens[$index].Trim() -split "`r?`n")) {
                $output.Add($commentLine.TrimEnd())
            }
            $index++
        }
        if ($index -ge $tokens.Count) { break }

        $ruleName = $tokens[$index]
        $index++
        if ($index -ge $tokens.Count -or $tokens[$index] -ne ':') {
            throw "Expected ':' after grammar rule '$ruleName'"
        }
        $index++

        $alternatives = [System.Collections.Generic.List[object]]::new()
        $alternative = [System.Collections.Generic.List[string]]::new()
        $terminated = $false
        while ($index -lt $tokens.Count) {
            $token = $tokens[$index]
            $index++
            if ($token -eq '|') {
                $alternatives.Add($alternative)
                $alternative = [System.Collections.Generic.List[string]]::new()
            } elseif ($token -eq ';') {
                $alternatives.Add($alternative)
                $terminated = $true
                break
            } else {
                $alternative.Add($token)
            }
        }
        if (-not $terminated) { throw "Grammar rule '$ruleName' is missing ';'" }

        if ($output.Count -gt 0 -and $output[$output.Count - 1] -ne '') {
            $output.Add('')
        }
        $output.Add($ruleName)
        for ($alternativeIndex = 0; $alternativeIndex -lt $alternatives.Count; $alternativeIndex++) {
            $marker = if ($alternativeIndex -eq 0) { ':' } else { '|' }
            foreach ($line in (Format-GrammarAlternative `
                    -Tokens $alternatives[$alternativeIndex] `
                    -Marker $marker `
                    -Actions $Actions)) {
                $output.Add($line)
            }
        }
        $output.Add('    ;')
    }

    while ($output.Count -gt 0 -and $output[$output.Count - 1] -eq '') {
        $output.RemoveAt($output.Count - 1)
    }
    return $Newline + ($output -join $Newline) + $Newline
}

$stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
$resolvedPath = if ([System.IO.Path]::IsPathFullyQualified($Path)) {
    [System.IO.Path]::GetFullPath($Path)
} else {
    [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $Path))
}
if ([System.IO.Path]::GetExtension($resolvedPath) -ne '.y') {
    throw "format-y only accepts Bison/Yacc .y files: $resolvedPath"
}

$source = [System.IO.File]::ReadAllText($resolvedPath)
$newline = if ($source.Contains("`r`n")) { "`r`n" } else { "`n" }
$prologueStart = $source.IndexOf('%{', [System.StringComparison]::Ordinal)
$prologueEnd = $source.IndexOf('%}', $prologueStart + 2, [System.StringComparison]::Ordinal)
$grammarStart = $source.IndexOf('%%', $prologueEnd + 2, [System.StringComparison]::Ordinal)
$grammarEnd = $source.IndexOf('%%', $grammarStart + 2, [System.StringComparison]::Ordinal)
if ($prologueStart -lt 0 -or $prologueEnd -lt 0 -or $grammarStart -lt 0 -or $grammarEnd -lt 0) {
    throw "Expected one %{...%} prologue and two %% section delimiters"
}

$segments = [System.Collections.Generic.List[object]]::new()
$segments.Add([pscustomobject]@{
        Kind       = "top"
        Start      = $prologueStart + 2
        Length     = $prologueEnd - ($prologueStart + 2)
        Content    = $source.Substring($prologueStart + 2, $prologueEnd - ($prologueStart + 2))
        Indent     = ""
        SingleLine = $false
    })

foreach ($segment in (Get-ActionSegments -Source $source -Start ($grammarStart + 2) -End $grammarEnd)) {
    $segments.Add($segment)
}

$segments.Add([pscustomobject]@{
        Kind       = "top"
        Start      = $grammarEnd + 2
        Length     = $source.Length - ($grammarEnd + 2)
        Content    = $source.Substring($grammarEnd + 2)
        Indent     = ""
        SingleLine = $false
    })

$synthetic = [System.Text.StringBuilder]::new()
for ($id = 0; $id -lt $segments.Count; $id++) {
    $segment = $segments[$id]
    [void]$synthetic.AppendLine("// __YFMT_BEGIN_${id}__")
    if ($segment.Kind -eq "action") {
        [void]$synthetic.AppendLine("void __yfmt_${id}(void) {")
        [void]$synthetic.AppendLine($segment.Content.Trim("`r", "`n"))
        [void]$synthetic.AppendLine("}")
    } else {
        [void]$synthetic.AppendLine($segment.Content.Trim("`r", "`n"))
    }
    [void]$synthetic.AppendLine("// __YFMT_END_${id}__")
}

$formattedSynthetic = Invoke-ClangFormat -InputText $synthetic.ToString() -AssumeFilename $resolvedPath -Timeout $TimeoutSeconds
$topReplacements = [System.Collections.Generic.List[object]]::new()
$formattedActions = @{}

for ($id = 0; $id -lt $segments.Count; $id++) {
    $segment = $segments[$id]
    $fragment = Get-MarkerContent -Formatted $formattedSynthetic -Id $id

    if ($segment.Kind -eq "action") {
        $open = $fragment.IndexOf('{')
        $close = $fragment.LastIndexOf('}')
        if ($open -lt 0 -or $close -le $open) { throw "Invalid formatted action $id" }
        $body = $fragment.Substring($open + 1, $close - $open - 1).Trim("`r", "`n")
        $bodyLines = $body -split "`r?`n"
        for ($lineIndex = 0; $lineIndex -lt $bodyLines.Count; $lineIndex++) {
            if ($bodyLines[$lineIndex].StartsWith('  ')) {
                $bodyLines[$lineIndex] = $bodyLines[$lineIndex].Substring(2)
            }
        }

        if ($segment.SingleLine -and $bodyLines.Count -eq 1) {
            $formattedActions[$id] = "{ $($bodyLines[0].Trim()) }"
        } else {
            $indentedBody = ($bodyLines | ForEach-Object {
                    if ([string]::IsNullOrWhiteSpace($_)) { "" } else { '  ' + $_.TrimEnd() }
                }) -join $newline
            $formattedActions[$id] = "{$newline$indentedBody$newline}"
        }
    } else {
        $replacement = $newline + ($fragment.Trim("`r", "`n") -replace "`r?`n", $newline) + $newline
        $topReplacements.Add([pscustomobject]@{
                Start  = $segment.Start
                Length = $segment.Length
                Text   = $replacement
            })
    }
}

$grammarContentStart = $grammarStart + 2
$grammar = $source.Substring($grammarContentStart, $grammarEnd - $grammarContentStart)
for ($id = $segments.Count - 1; $id -ge 0; $id--) {
    $segment = $segments[$id]
    if ($segment.Kind -ne 'action') { continue }
    $relativeStart = $segment.Start - $grammarContentStart
    $grammar = $grammar.Remove($relativeStart, $segment.Length).Insert(
        $relativeStart, " __YFMT_ACTION_${id}__ ")
}
$formattedGrammar = Format-GrammarSection -Grammar $grammar -Actions $formattedActions -Newline $newline

$replacements = [System.Collections.Generic.List[object]]::new()
foreach ($replacement in $topReplacements) { $replacements.Add($replacement) }
$replacements.Add([pscustomobject]@{
        Start  = $grammarContentStart
        Length = $grammarEnd - $grammarContentStart
        Text   = $formattedGrammar
    })

$result = $source
foreach ($replacement in ($replacements | Sort-Object Start -Descending)) {
    $result = $result.Remove($replacement.Start, $replacement.Length).Insert($replacement.Start, $replacement.Text)
}

$changed = $result -cne $source
if ($changed -and -not $DryRun -and -not $Check) {
    if ([System.IO.File]::ReadAllText($resolvedPath) -cne $source) {
        throw "$resolvedPath changed while formatting; refusing to overwrite newer edits"
    }
    $utf8NoBom = [System.Text.UTF8Encoding]::new($false)
    [System.IO.File]::WriteAllText($resolvedPath, $result, $utf8NoBom)
}

$stopwatch.Stop()
$mode = if ($DryRun) { "dry-run" } elseif ($Check) { "check" } else { "write" }
Write-Host ("format-y: mode={0} fragments={1} changed={2} elapsed_ms={3:N1} timeout_s={4}" -f `
        $mode, $segments.Count, $changed, $stopwatch.Elapsed.TotalMilliseconds, $TimeoutSeconds)

if ($Check -and $changed) { exit 1 }
