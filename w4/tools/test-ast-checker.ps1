Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
. (Join-Path $PSScriptRoot "ast-checker.ps1")

$Root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot ".."))
$Passed = 0
$Failed = 0

function Invoke-Test {
    param([string]$Name, [scriptblock]$Body)
    try {
        & $Body
        Write-Host "[PASS] $Name"
        $script:Passed++
    } catch {
        Write-Host "[FAIL] $Name - $($_.Exception.Message)"
        $script:Failed++
    }
}

function Import-CaseGraph {
    param([string]$Stem)
    return Import-ExpectedGraph (Join-Path $Root "tests\ast_expected\$Stem.json") $Root
}

function Assert-Pass {
    param($Expected, $Actual)
    $differences = @(Compare-AstGraph $Expected $Actual)
    if ($differences.Count -ne 0) { throw "expected PASS, got $($differences.Count) difference(s)" }
}

function Assert-Fail {
    param($Expected, $Actual)
    $differences = @(Compare-AstGraph $Expected $Actual)
    if ($differences.Count -eq 0) { throw "corrupted graph was accepted" }
}

function New-RecursiveProgram {
    $graph = @{NextKey=0}
    $struct = New-TypeObject $graph "T_STRUCT"
    $pointer = New-TypeObject $graph "T_POINTER"
    $pointer.ElementType = $struct
    $field = New-AstObject $graph "A_ID"
    $field.Name="next"; $field.Kind="ID_FIELD"; $field.Level=0; $field.Specifier="S_NULL"
    $field.Value=0; $field.Address=0; $field.Type=$pointer; $field.Init=$null; $field.Link=$null
    $struct.Field = $field
    $rootId = New-AstObject $graph "A_ID"
    $rootId.Name="root"; $rootId.Kind="ID_VAR"; $rootId.Level=0; $rootId.Specifier="S_AUTO"
    $rootId.Value=0; $rootId.Address=0; $rootId.Type=$struct; $rootId.Init=$null; $rootId.Link=$null
    $program = New-AstObject $graph "A_NODE"
    $program.Name="N_PROGRAM"; $program.Type=$null; $program.Value=0
    $program.Llink=$null; $program.Clink=$rootId; $program.Rlink=$null
    return $program
}

Invoke-Test "normal expected graph" {
    $left = Import-CaseGraph "25_function_parameters"
    $right = Import-CaseGraph "25_function_parameters"
    Assert-Pass $left.Root $right.Root
}

Invoke-Test "node kind corruption" {
    $expected = Import-CaseGraph "25_function_parameters"
    $actual = Import-CaseGraph "25_function_parameters"
    $actual.Objects["add_exp"].Name = "N_EXP_SUB"
    Assert-Fail $expected.Root $actual.Root
}

Invoke-Test "identifier target corruption" {
    $expected = Import-CaseGraph "44_scope_shadowing"
    $actual = Import-CaseGraph "44_scope_shadowing"
    $actual.Objects["ref_outer_return"].Target = $actual.Objects["inner_x"]
    Assert-Fail $expected.Root $actual.Root
}

Invoke-Test "declaration order corruption" {
    $expected = Import-CaseGraph "24_function_prototype"
    $actual = Import-CaseGraph "24_function_prototype"
    $add = $actual.Objects["add"]
    $main = $actual.Objects["main"]
    $actual.Root.Clink = $main; $main.Link = $add; $add.Link = $null
    Assert-Fail $expected.Root $actual.Root
}

Invoke-Test "N_STMT_LIST_NIL child corruption" {
    $expected = Import-CaseGraph "25_function_parameters"
    $actual = Import-CaseGraph "25_function_parameters"
    $actual.Objects["stmt_nil"].Llink = $actual.Objects["add_exp"]
    Assert-Fail $expected.Root $actual.Root
}

Invoke-Test "normal recursive DONE type" {
    $output = @'
=======  syntax tree  ==========
N_PROGRAM (00000000,0)
|  (ID="root") TYPE:00000010 KIND:VAR SPEC=AUTO LEV=0 VAL=0 ADDR=0
|  |  TYPE
|  |  |  STRUCT
|  |  |  |  FIELD
|  |  |  |  |  (ID="next") TYPE:00000020 KIND:FIELD SPEC=NULL LEV=0 VAL=0 ADDR=0
|  |  |  |  |  |  TYPE
|  |  |  |  |  |  |  POINTER
|  |  |  |  |  |  |  |  ELEMENT_TYPE
|  |  |  |  |  |  |  |  |  (DONE:00000010)
'@
    $actual = ConvertFrom-AstPrint $output
    Assert-Pass (New-RecursiveProgram) $actual
}

Invoke-Test "broken recursive type sharing" {
    $expected = New-RecursiveProgram
    $actual = New-RecursiveProgram
    $clone = New-RecursiveProgram
    $clone.Clink.Type.Key = "actual:clone-struct"
    $actual.Clink.Type.Field.Type.ElementType = $clone.Clink.Type
    Assert-Fail $expected $actual
}

Invoke-Test "N_ARG_LIST_NIL child corruption" {
    $graphA=@{NextKey=0}; $graphB=@{NextKey=0}
    $expected=New-AstObject $graphA "A_NODE"; $actual=New-AstObject $graphB "A_NODE"
    foreach ($item in @($expected,$actual)) {
        $item.Name="N_ARG_LIST_NIL"; $item.Type=$null; $item.Value=0
        $item.Llink=$null; $item.Clink=$null; $item.Rlink=$null
    }
    $actual.Llink = New-AstObject $graphB "A_NODE"
    $actual.Llink.Name="N_EXP_INT_CONST"; $actual.Llink.Type=$null; $actual.Llink.Value=0
    $actual.Llink.Llink=$null; $actual.Llink.Clink=1; $actual.Llink.Rlink=$null
    Assert-Fail $expected $actual
}

Write-Host "Summary: $Passed passed, $Failed failed, $($Passed + $Failed) total"
if ($Failed -gt 0) { exit 1 }
exit 0

