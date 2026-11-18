param(
    [string]$Parser
)

$ErrorActionPreference = 'Stop'
$projectDir = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
if ([string]::IsNullOrWhiteSpace($Parser)) {
    $Parser = Join-Path $projectDir 'parser.exe'
}
$Parser = [IO.Path]::GetFullPath($Parser)

if (-not (Test-Path -LiteralPath $Parser -PathType Leaf)) {
    throw "Parser not found: $Parser"
}

function Invoke-ParserText {
    param([string]$Text)

    $startInfo = [Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $Parser
    $startInfo.WorkingDirectory = $projectDir
    $startInfo.UseShellExecute = $false
    $startInfo.RedirectStandardInput = $true
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true

    $process = [Diagnostics.Process]::new()
    $process.StartInfo = $startInfo
    [void]$process.Start()
    $process.StandardInput.Write($Text)
    $process.StandardInput.Close()
    $stdout = $process.StandardOutput.ReadToEnd()
    $stderr = $process.StandardError.ReadToEnd()
    $process.WaitForExit()

    [PSCustomObject]@{
        ExitCode = $process.ExitCode
        Output = $stdout + $stderr
    }
}

function Invoke-ParserFile {
    param([IO.FileInfo]$File)
    Invoke-ParserText ([IO.File]::ReadAllText($File.FullName))
}

$passed = 0
$failed = 0

Get-ChildItem -LiteralPath (Join-Path $PSScriptRoot 'valid') -Filter '*.c' |
    Sort-Object Name |
    ForEach-Object {
        $result = Invoke-ParserFile $_
        if ($result.ExitCode -eq 0 -and $result.Output -match 'N_PROGRAM') {
            Write-Host "PASS valid   $($_.Name)"
            $script:passed++
        } else {
            Write-Host "FAIL valid   $($_.Name)"
            Write-Host $result.Output
            $script:failed++
        }
    }

Get-ChildItem -LiteralPath (Join-Path $PSScriptRoot 'invalid') -Filter '*.c' |
    Sort-Object Name |
    ForEach-Object {
        $result = Invoke-ParserFile $_
        if ($result.ExitCode -ne 0 -and $result.Output -match '(?i)syntax error') {
            Write-Host "PASS invalid $($_.Name)"
            $script:passed++
        } else {
            Write-Host "FAIL invalid $($_.Name)"
            Write-Host $result.Output
            $script:failed++
        }
    }

$newlineCases = @(
    [PSCustomObject]@{ Name = 'LF'; Text = "int main()`n{`n    return 0;`n}`n" },
    [PSCustomObject]@{ Name = 'CRLF'; Text = "int main()`r`n{`r`n    return 0;`r`n}`r`n" }
)

foreach ($case in $newlineCases) {
    $result = Invoke-ParserText $case.Text
    if ($result.ExitCode -eq 0 -and $result.Output -match 'N_PROGRAM') {
        Write-Host "PASS newline $($case.Name)"
        $passed++
    } else {
        Write-Host "FAIL newline $($case.Name)"
        Write-Host $result.Output
        $failed++
    }
}

Write-Host "`n$passed passed, $failed failed"
if ($failed -ne 0) {
    exit 1
}
