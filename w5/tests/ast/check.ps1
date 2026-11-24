Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
. (Join-Path $PSScriptRoot "checker.ps1")

$Root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot "..\.."))
$Diff = $false
$All = $false
$Number = $null
foreach ($argument in $args) {
    switch ($argument) {
        "--diff" { $Diff = $true }
        "--all" { $All = $true }
        default {
            if ($null -ne $Number) { Write-Error "unexpected argument: $argument" }
            $Number = $argument
        }
    }
}
if ($All -eq ($null -ne $Number)) {
    Write-Host "Usage: tests\ast\check.cmd TEST_NUMBER [--diff] | --all [--diff]"
    exit 2
}

function Get-CheckCases {
    $expectedDirectory = Join-Path $PSScriptRoot "expected"
    $sourceDirectory = Join-Path $PSScriptRoot "cases"
    if ($All) {
        return @(Get-ChildItem -LiteralPath $sourceDirectory -Filter "*.c" | Sort-Object Name | ForEach-Object {
            $txt = Join-Path $expectedDirectory ($_.BaseName + ".txt")
            [pscustomobject]@{
                Number=($_.BaseName -split '_')[0]; Stem=$_.BaseName; Source=$_.FullName;
                Txt=$(if (Test-Path -LiteralPath $txt -PathType Leaf) { $txt } else { $null })
            }
        })
    }
    if ($Number -notmatch '^\d+$') { throw "invalid AST test number: $Number" }
    $normalized = ([int]$Number).ToString("00")
    $matches = @(Get-ChildItem -LiteralPath $sourceDirectory -Filter "$normalized`_*.c")
    if ($matches.Count -eq 0) { return @([pscustomobject]@{Number=$normalized;Stem=$null;Source=$null;Txt=$null}) }
    return @($matches | Sort-Object Name | ForEach-Object {
        $txt = Join-Path $expectedDirectory ($_.BaseName + ".txt")
        [pscustomobject]@{
            Number=$normalized; Stem=$_.BaseName; Source=$_.FullName;
            Txt=$(if (Test-Path -LiteralPath $txt -PathType Leaf) { $txt } else { $null })
        }
    })
}

function Invoke-BuildStep {
    param([string]$Program, [string[]]$Arguments, [string]$Label)
    $savedPreference = $ErrorActionPreference
    $ErrorActionPreference = "Continue"
    try {
        $output = & $Program @Arguments 2>&1 | Out-String
        $exitCode = $LASTEXITCODE
    } finally { $ErrorActionPreference = $savedPreference }
    if ($exitCode -ne 0) { throw "$Label failed:`n$output" }
}

function Build-CurrentParser {
    param([string]$Directory)
    $parserC = Join-Path $Directory "y.tab.c"
    $parserH = Join-Path $Directory "y.tab.h"
    $lexerC = Join-Path $Directory "lex.yy.c"
    $executable = Join-Path $Directory "ast_tests.exe"
    Invoke-BuildStep "bison" @("-y","-d","--defines=$parserH","-o",$parserC,(Join-Path $Root "c.y")) "bison"
    Invoke-BuildStep "flex" @("-o",$lexerC,(Join-Path $Root "c.l")) "flex"
    $sources = @(
        $parserC, $lexerC,
        (Join-Path $Root "semantic.c"), (Join-Path $Root "syntax_tree.c"),
        (Join-Path $Root "logger.c"), (Join-Path $Root "print.c"),
        (Join-Path $PSScriptRoot "ast_assert.c"),
        (Join-Path $PSScriptRoot "ast_options.c"),
        (Join-Path $PSScriptRoot "ast_expression.c"),
        (Join-Path $PSScriptRoot "ast_declaration.c"),
        (Join-Path $PSScriptRoot "ast_statement.c"),
        (Join-Path $PSScriptRoot "ast.c")
    )
    Invoke-BuildStep "gcc" (@("-Wall","-Wextra","-std=c11","-g","-O0","-I",$Directory,"-I",$Root) + $sources + @("-o",$executable)) "gcc"
    return $executable
}

function Invoke-AstCompiler {
    param([string]$Executable, [string]$Source)
    $start = New-Object Diagnostics.ProcessStartInfo
    $start.FileName = $Executable
    $start.WorkingDirectory = $Root
    $start.UseShellExecute = $false
    $start.RedirectStandardInput = $true
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    $start.CreateNoWindow = $true
    foreach ($key in @($start.EnvironmentVariables.Keys)) {
        if ([string]$key -like "AST_TEST_*") { $start.EnvironmentVariables.Remove([string]$key) }
    }
    $start.EnvironmentVariables["AST_PRINT"] = "1"
    $process = New-Object Diagnostics.Process
    $process.StartInfo = $start
    [void]$process.Start()
    $process.StandardInput.Write([IO.File]::ReadAllText($Source))
    $process.StandardInput.Close()
    $stdout = $process.StandardOutput.ReadToEnd()
    $stderr = $process.StandardError.ReadToEnd()
    $process.WaitForExit()
    return [pscustomobject]@{ ExitCode=$process.ExitCode; Stdout=$stdout; Stderr=$stderr }
}

function Format-Difference {
    param($Difference)
    Write-Host "Path: $($Difference.Path)"
    Write-Host "Expected: $(Format-AstValue $Difference.Expected)"
    Write-Host "Actual:   $(Format-AstValue $Difference.Actual)"
}

$cases = @(Get-CheckCases)
$temp = Join-Path ([IO.Path]::GetTempPath()) ("w4-check-ast-" + [guid]::NewGuid().ToString("N"))
$results = New-Object System.Collections.ArrayList
try {
    [void](New-Item -ItemType Directory -Path $temp)
    $parser = Build-CurrentParser $temp
    foreach ($case in $cases) {
        $status = "UNVERIFIABLE"
        $reason = $null
        $differences = @()
        if ($null -eq $case.Source) { $reason = "numbered C source was not found" }
        elseif ($null -eq $case.Txt) { $reason = "manual expected TXT was not found" }
        else {
            $json = Join-Path (Split-Path $case.Txt -Parent) ($case.Stem + ".json")
            if (-not (Test-Path -LiteralPath $json -PathType Leaf)) { $reason = "structured companion JSON was not found" }
            else {
                try {
                    $expected = Import-ExpectedGraph $json $Root
                    if ([IO.Path]::GetFullPath($expected.Source) -ne [IO.Path]::GetFullPath($case.Source)) {
                        throw "JSON source metadata does not match the numbered C source"
                    }
                    $run = Invoke-AstCompiler $parser $case.Source
                    if ($run.ExitCode -ne 0) {
                        $status = "FAIL"
                        $reason = if ($run.Stderr.Trim()) { $run.Stderr.Trim() } else { $run.Stdout.Trim() }
                    } else {
                        $actual = ConvertFrom-AstPrint $run.Stdout
                        $differences = @(Compare-AstGraph $expected.Root $actual)
                        $status = if ($differences.Count -eq 0) { "PASS" } else { "FAIL" }
                    }
                } catch {
                    $reason = $_.Exception.Message
                }
            }
        }
        [void]$results.Add([pscustomobject]@{Case=$case;Status=$status;Reason=$reason;Differences=$differences})
    }
} catch {
    Write-Host "[ERROR] $($_.Exception.Message)"
    exit 1
} finally {
    if (Test-Path -LiteralPath $temp) {
        $resolvedTemp = [IO.Path]::GetFullPath($temp)
        $tempBase = [IO.Path]::GetFullPath([IO.Path]::GetTempPath())
        if ($resolvedTemp.StartsWith($tempBase, [StringComparison]::OrdinalIgnoreCase) -and (Split-Path $resolvedTemp -Leaf).StartsWith("w4-check-ast-")) {
            Remove-Item -LiteralPath $resolvedTemp -Recurse -Force
        }
    }
}

foreach ($result in $results) {
    Write-Host "[$($result.Status)] AST $($result.Case.Number)"
    if ($result.Reason) { Write-Host "Reason: $($result.Reason)" }
    if ($result.Status -eq "FAIL" -and $result.Differences.Count -gt 0) {
        $shown = if ($Diff) { $result.Differences } else { @($result.Differences[0]) }
        foreach ($difference in $shown) { Format-Difference $difference; Write-Host "" }
    }
}

if ($All) {
    $passed = @($results | Where-Object Status -eq "PASS").Count
    $failed = @($results | Where-Object Status -eq "FAIL").Count
    $unknown = @($results | Where-Object Status -eq "UNVERIFIABLE").Count
    Write-Host "Summary: $passed passed, $failed failed, $unknown unverifiable, $($results.Count) total"
}
if (@($results | Where-Object Status -ne "PASS").Count -gt 0) { exit 1 }
exit 0

