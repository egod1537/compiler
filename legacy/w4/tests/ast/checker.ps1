Set-StrictMode -Version Latest

function New-AstObject {
    param([hashtable]$Graph, [string]$Class)
    $Graph.NextKey++
    return [ordered]@{ Key = "actual:$($Graph.NextKey)"; Class = $Class }
}

function New-TypeObject {
    param([hashtable]$Graph, $Kind)
    $result = New-AstObject $Graph "A_TYPE"
    $result.Kind = $Kind
    $result.ElementType = $null
    $result.Field = $null
    $result.Expr = $null
    return $result
}

function ConvertTo-AddressKey {
    param([string]$Text)
    $value = $Text.Trim().ToLowerInvariant()
    if ($value -in @("(nil)", "nil", "null", "0x0") -or $value -match '^0+$') {
        return $null
    }
    if ($value.StartsWith("0x")) { $value = $value.Substring(2) }
    $value = $value.TrimStart('0')
    if ($value.Length -eq 0) { return $null }
    return $value
}

function ConvertFrom-AstPrintTokens {
    param([string]$Output)
    $marker = "=======  syntax tree  =========="
    $markerAt = $Output.IndexOf($marker, [StringComparison]::Ordinal)
    if ($markerAt -lt 0) { throw "AST_PRINT header was not found" }
    $tree = $Output.Substring($markerAt + $marker.Length)
    $tree = [regex]::Replace($tree, '(\((?:void|null)\))(?=\|)', "`$1`n")
    $tokens = New-Object System.Collections.ArrayList
    $lineNumber = 0
    foreach ($raw in ($tree -split "`r?`n")) {
        $lineNumber++
        $text = $raw.TrimStart()
        $depth = 0
        while ($text.StartsWith("|  ")) {
            $depth++
            $text = $text.Substring(3)
        }
        $content = $text.Trim()
        if ($content.Length -eq 0) { continue }

        $kind = $null
        $value = $null
        if ($content -match '^(N_[A-Z0-9_]+)\s+\(([^,]+),(-?\d+)\)$') {
            $kind = "NODE"
            $value = @{
                Name = $Matches[1]
                TypeAddress = ConvertTo-AddressKey $Matches[2]
                Value = [int]$Matches[3]
            }
        }
        elseif ($content -match '^\(ID="([^"]*)"\)\s+TYPE:(\S+)\s+KIND:([A-Z_]+)\s+LEV=(-?\d+)\s+VAL=(-?\d+)\s+ADDR=(-?\d+)') {
            $kind = "ID"
            $value = @{
                Name = $Matches[1]
                TypeAddress = ConvertTo-AddressKey $Matches[2]
                Kind = "ID_$($Matches[3])"
                Specifier = $null
                Level = [int]$Matches[4]
                Value = [int]$Matches[5]
                Address = [int]$Matches[6]
            }
        }
        elseif ($content -in @("PARAMETER", "TYPE", "BODY", "ELEMENT_TYPE", "INDEX", "FIELD", "ENUMERATORS", "INIT")) {
            $kind = "LABEL"; $value = $content
        }
        elseif ($content -eq "(int)") { $kind = "TYPE_KIND"; $value = "T_INT" }
        elseif ($content -eq "(float)") { $kind = "TYPE_KIND"; $value = "T_FLOAT" }
        elseif ($content -match '^\(char\s+\d+\)$') { $kind = "TYPE_KIND"; $value = "T_CHAR" }
        elseif ($content -eq "(void)") { $kind = "TYPE_KIND"; $value = "T_VOID" }
        elseif ($content -eq "(null)") { $kind = "TYPE_KIND"; $value = "T_NULL" }
        elseif ($content -match '^\(DONE:([^\)]+)\)$') {
            $kind = "TYPE_REF"; $value = ConvertTo-AddressKey $Matches[1]
        }
        elseif ($content -in @("FUNCTION", "POINTER", "ARRAY", "STRUCT", "UNION", "ENUM", "NULL", "VOID")) {
            $kind = "TYPE_KIND"
            $value = @{
                FUNCTION="T_FUNC"; POINTER="T_POINTER"; ARRAY="T_ARRAY";
                STRUCT="T_STRUCT"; UNION="T_UNION"; ENUM="T_ENUM";
                NULL="T_NULL"; VOID="T_VOID"
            }[$content]
        }
        elseif ($content -eq "(none)") { $kind = "NONE" }
        elseif ($content -match '^-?\d+$') { $kind = "INTEGER"; $value = [int64]$content }
        else { throw "unrecognized AST_PRINT content on tree line $lineNumber`: $content" }

        [void]$tokens.Add([pscustomobject]@{ Kind=$kind; Value=$value; Line=$lineNumber; Depth=$depth })
    }
    return $tokens.ToArray()
}

function New-ParserState {
    param([object[]]$Tokens)
    $scopes = New-Object System.Collections.ArrayList
    [void]$scopes.Add((New-Object System.Collections.ArrayList))
    return @{
        Tokens = $Tokens; Position = 0; Graph = @{ NextKey = 0 };
        Types = @{}; Builtins = @{};
        Unaddressed = (New-Object System.Collections.ArrayList); Scopes = $scopes
    }
}

function Test-Token {
    param([hashtable]$State, [string]$Kind, $Value, [int]$Depth = -1, [switch]$MatchValue)
    if ($State.Position -ge $State.Tokens.Count) { return $false }
    $token = $State.Tokens[$State.Position]
    if ($token.Kind -ne $Kind) { return $false }
    if ($Depth -ge 0 -and $token.Depth -ne $Depth) { return $false }
    if ($MatchValue -and $token.Value -ne $Value) { return $false }
    return $true
}

function Read-Token {
    param([hashtable]$State, [string]$Kind, $Value, [int]$Depth = -1, [switch]$MatchValue)
    if (-not (Test-Token $State $Kind $Value -Depth $Depth -MatchValue:$MatchValue)) {
        if ($State.Position -ge $State.Tokens.Count) { throw "unexpected end of AST_PRINT; expected $Kind" }
        $got = $State.Tokens[$State.Position]
        throw "tree line $($got.Line): expected $Kind at depth $Depth, got $($got.Kind) at depth $($got.Depth)"
    }
    $token = $State.Tokens[$State.Position]
    $State.Position++
    return $token
}

function Get-TypeAt {
    param([hashtable]$State, $Address)
    if ($null -eq $Address) { return $null }
    if (-not $State.Types.ContainsKey($Address)) {
        $State.Types[$Address] = New-TypeObject $State.Graph $null
    }
    return $State.Types[$Address]
}

function New-NodeFromToken {
    param([hashtable]$State, $Token, $Llink=$null, $Clink=$null, $Rlink=$null)
    $node = New-AstObject $State.Graph "A_NODE"
    $node.Name = $Token.Value.Name
    $node.Type = Get-TypeAt $State $Token.Value.TypeAddress
    $node.Value = [int64]$Token.Value.Value
    $node.Llink = $Llink; $node.Clink = $Clink; $node.Rlink = $Rlink
    return $node
}

function Read-IdList {
    param([hashtable]$State, [int]$Depth, [bool]$RegisterScope)
    $items = New-Object System.Collections.ArrayList
    while (Test-Token $State "ID" $null -Depth $Depth) {
        [void]$items.Add((Read-Declaration $State $Depth $RegisterScope))
    }
    $head = $null
    for ($index = $items.Count - 1; $index -ge 0; $index--) {
        $items[$index].Link = $head; $head = $items[$index]
    }
    return $head
}

function Read-Declaration {
    param([hashtable]$State, [int]$Depth, [bool]$RegisterScope)
    $printed = (Read-Token $State "ID" $null -Depth $Depth).Value
    $item = New-AstObject $State.Graph "A_ID"
    foreach ($field in @("Name","Kind","Level","Specifier","Value","Address")) { $item[$field] = $printed[$field] }
    $item.Type = Get-TypeAt $State $printed.TypeAddress
    $item.Init = $null; $item.Link = $null
    if ($RegisterScope) { [void]$State.Scopes[$State.Scopes.Count-1].Add($item) }
    if (Test-Token $State "LABEL" "TYPE" -Depth ($Depth+1) -MatchValue) {
        [void](Read-Token $State "LABEL" "TYPE" -Depth ($Depth+1) -MatchValue)
        $item.Type = Read-AType $State ($Depth+2) $printed.TypeAddress
    }
    elseif ($null -ne $printed.TypeAddress) { throw "identifier $($printed.Name) has a type address but no TYPE output" }
    if (Test-Token $State "LABEL" "INIT" -Depth ($Depth+1) -MatchValue) {
        [void](Read-Token $State "LABEL" "INIT" -Depth ($Depth+1) -MatchValue)
        if ($item.Kind -eq "ID_ENUM_LITERAL") { $item.Init = Read-Expression $State ($Depth+2) }
        else { $item.Init = Read-Initializer $State ($Depth+2) }
    }
    return $item
}

function Resolve-IdReference {
    param([hashtable]$State, $Reference)
    for ($scopeIndex = $State.Scopes.Count - 1; $scopeIndex -ge 0; $scopeIndex--) {
        $named = @($State.Scopes[$scopeIndex] | Where-Object { $_.Name -eq $Reference.Name })
        if ($named.Count -eq 0) { continue }
        $matches = @($named | Where-Object {
            $_.Kind -eq $Reference.Kind -and $_.Level -eq $Reference.Level -and
            $_.Value -eq $Reference.Value -and
            $_.Address -eq $Reference.Address -and [object]::ReferenceEquals($_.Type, $Reference.Type)
        })
        if ($matches.Count -eq 1) { return $matches[0] }
        return $null
    }
    return $null
}

function Read-IdReference {
    param([hashtable]$State, [int]$Depth)
    $printed = (Read-Token $State "ID" $null -Depth $Depth).Value
    $item = New-AstObject $State.Graph "A_ID_REF"
    foreach ($field in @("Name","Kind","Level","Specifier","Value","Address")) { $item[$field] = $printed[$field] }
    $item.Type = Get-TypeAt $State $printed.TypeAddress
    $item.Target = Resolve-IdReference $State $item
    return $item
}

function Read-AType {
    param([hashtable]$State, [int]$Depth, $AddressHint=$null)
    if (Test-Token $State "TYPE_REF" $null -Depth $Depth) {
        $address = (Read-Token $State "TYPE_REF" $null -Depth $Depth).Value
        if ($null -eq $address) { throw "DONE contains a null address" }
        if (-not $State.Types.ContainsKey($address)) {
            if ($State.Unaddressed.Count -eq 1) {
                $candidate = $State.Unaddressed[0]; $State.Unaddressed.Clear()
                $State.Types[$address] = $candidate
            } else { [void](Get-TypeAt $State $address) }
        }
        return Get-TypeAt $State $address
    }
    $kind = (Read-Token $State "TYPE_KIND" $null -Depth $Depth).Value
    if ($kind -in @("T_INT","T_FLOAT","T_CHAR","T_VOID","T_NULL")) {
        if ($State.Builtins.ContainsKey($kind)) { $type = $State.Builtins[$kind] }
        elseif ($null -ne $AddressHint) { $type = Get-TypeAt $State $AddressHint }
        else { $type = New-TypeObject $State.Graph $kind }
        $type.Kind = $kind; $State.Builtins[$kind] = $type
        if ($null -ne $AddressHint) { $State.Types[$AddressHint] = $type }
        return $type
    }
    if ($null -ne $AddressHint) { $type = Get-TypeAt $State $AddressHint }
    else {
        $type = New-TypeObject $State.Graph $kind
        [void]$State.Unaddressed.Add($type)
    }
    if ($null -ne $type.Kind -and $type.Kind -ne $kind) { throw "conflicting type kinds for one address" }
    $type.Kind = $kind

    if ($kind -eq "T_FUNC") {
        [void](Read-Token $State "LABEL" "PARAMETER" -Depth ($Depth+1) -MatchValue)
        [void]$State.Scopes.Add((New-Object System.Collections.ArrayList))
        try {
            $type.Field = Read-IdList $State ($Depth+2) $true
            [void](Read-Token $State "LABEL" "TYPE" -Depth ($Depth+1) -MatchValue)
            $type.ElementType = Read-AType $State ($Depth+2)
            if (Test-Token $State "LABEL" "BODY" -Depth ($Depth+1) -MatchValue) {
                [void](Read-Token $State "LABEL" "BODY" -Depth ($Depth+1) -MatchValue)
                $type.Expr = Read-Statement $State ($Depth+2) $true
            }
        } finally { $State.Scopes.RemoveAt($State.Scopes.Count-1) }
    }
    elseif ($kind -eq "T_POINTER") {
        [void](Read-Token $State "LABEL" "ELEMENT_TYPE" -Depth ($Depth+1) -MatchValue)
        $type.ElementType = Read-AType $State ($Depth+2)
    }
    elseif ($kind -eq "T_ARRAY") {
        [void](Read-Token $State "LABEL" "INDEX" -Depth ($Depth+1) -MatchValue)
        if (Test-Token $State "NONE" $null -Depth ($Depth+2)) { [void](Read-Token $State "NONE" $null -Depth ($Depth+2)) }
        else { $type.Expr = Read-Expression $State ($Depth+2) }
        [void](Read-Token $State "LABEL" "ELEMENT_TYPE" -Depth ($Depth+1) -MatchValue)
        $type.ElementType = Read-AType $State ($Depth+2)
    }
    elseif ($kind -in @("T_STRUCT","T_UNION","T_ENUM")) {
        $label = if ($kind -eq "T_ENUM") { "ENUMERATORS" } else { "FIELD" }
        [void](Read-Token $State "LABEL" $label -Depth ($Depth+1) -MatchValue)
        $type.Field = Read-IdList $State ($Depth+2) ($kind -eq "T_ENUM")
    }
    else { throw "unsupported type $kind" }
    return $type
}

function Read-StatementList {
    param([hashtable]$State, [int]$Depth)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    if ($token.Value.Name -eq "N_STMT_LIST_NIL") { return New-NodeFromToken $State $token }
    if ($token.Value.Name -ne "N_STMT_LIST") { throw "expected statement list, got $($token.Value.Name)" }
    return New-NodeFromToken $State $token (Read-Statement $State ($Depth+1)) $null (Read-StatementList $State ($Depth+1))
}

function Read-ForExpression {
    param([hashtable]$State, [int]$Depth)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    if ($token.Value.Name -ne "N_FOR_EXP") {
        throw "expected N_FOR_EXP, got $($token.Value.Name)"
    }

    $expressions = New-Object System.Collections.ArrayList
    while (Test-Token $State "NODE" $null -Depth ($Depth+1)) {
        $nextName = $State.Tokens[$State.Position].Value.Name
        if (-not $nextName.StartsWith("N_EXP_")) { break }
        [void]$expressions.Add((Read-Expression $State ($Depth+1)))
        if ($expressions.Count -gt 3) { throw "N_FOR_EXP has more than three expressions" }
    }

    if ($expressions.Count -eq 0) {
        return New-NodeFromToken $State $token $null $null $null
    }
    if ($expressions.Count -ne 3) {
        throw "N_FOR_EXP contains $($expressions.Count) printed expression(s); print.c does not identify which slot was omitted"
    }
    return New-NodeFromToken $State $token $expressions[0] $expressions[1] $expressions[2]
}

function Read-Statement {
    param([hashtable]$State, [int]$Depth, [bool]$FunctionBody=$false)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    $name = $token.Value.Name
    if ($name -eq "N_STMT_COMPOUND") {
        if (-not $FunctionBody) { [void]$State.Scopes.Add((New-Object System.Collections.ArrayList)) }
        try {
            $declarations = Read-IdList $State ($Depth+1) $true
            $statements = Read-StatementList $State ($Depth+1)
        } finally { if (-not $FunctionBody) { $State.Scopes.RemoveAt($State.Scopes.Count-1) } }
        return New-NodeFromToken $State $token $declarations $null $statements
    }
    if ($name -in @("N_STMT_EMPTY","N_STMT_CONTINUE","N_STMT_BREAK")) { return New-NodeFromToken $State $token }
    if ($name -eq "N_STMT_EXPRESSION") { return New-NodeFromToken $State $token $null (Read-Expression $State ($Depth+1)) }
    if ($name -eq "N_STMT_RETURN") {
        $expression = $null
        if (Test-Token $State "NODE" $null -Depth ($Depth+1)) {
            $nextName = $State.Tokens[$State.Position].Value.Name
            if ($nextName.StartsWith("N_EXP_")) { $expression = Read-Expression $State ($Depth+1) }
        }
        return New-NodeFromToken $State $token $null $expression
    }
    if ($name -eq "N_STMT_IF") { return New-NodeFromToken $State $token (Read-Expression $State ($Depth+1)) $null (Read-Statement $State ($Depth+1)) }
    if ($name -eq "N_STMT_IF_ELSE") { return New-NodeFromToken $State $token (Read-Expression $State ($Depth+1)) (Read-Statement $State ($Depth+1)) (Read-Statement $State ($Depth+1)) }
    if ($name -eq "N_STMT_FOR") {
        $forExpression = Read-ForExpression $State ($Depth+1)
        $body = Read-Statement $State ($Depth+1)
        return New-NodeFromToken $State $token $forExpression $null $body
    }
    throw "unsupported statement $name"
}

function Read-Expression {
    param([hashtable]$State, [int]$Depth)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    $name = $token.Value.Name
    if ($name -eq "N_EXP_IDENT") { return New-NodeFromToken $State $token $null (Read-IdReference $State ($Depth+1)) }
    if ($name -in @("N_EXP_INT_CONST","N_EXP_CHAR_CONST")) {
        $integer = (Read-Token $State "INTEGER" $null -Depth ($Depth+1)).Value
        return New-NodeFromToken $State $token $null $integer
    }
    $binary = @("N_EXP_ARRAY","N_EXP_MUL","N_EXP_DIV","N_EXP_MOD","N_EXP_ADD","N_EXP_SUB","N_EXP_LSS","N_EXP_GTR","N_EXP_LEQ","N_EXP_GEQ","N_EXP_NEQ","N_EXP_EQL","N_EXP_AND","N_EXP_OR","N_EXP_ASSIGN")
    if ($name -in $binary) { return New-NodeFromToken $State $token (Read-Expression $State ($Depth+1)) $null (Read-Expression $State ($Depth+1)) }
    $unary = @("N_EXP_POST_INC","N_EXP_POST_DEC","N_EXP_PRE_INC","N_EXP_PRE_DEC","N_EXP_AMP","N_EXP_STAR","N_EXP_NOT","N_EXP_PLUS","N_EXP_MINUS","N_EXP_SIZE_EXP")
    if ($name -in $unary) { return New-NodeFromToken $State $token $null (Read-Expression $State ($Depth+1)) }
    if ($name -eq "N_EXP_FUNCTION_CALL") { return New-NodeFromToken $State $token (Read-Expression $State ($Depth+1)) $null (Read-ArgumentList $State ($Depth+1)) }
    throw "unsupported expression $name"
}

function Read-ArgumentList {
    param([hashtable]$State, [int]$Depth)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    if ($token.Value.Name -eq "N_ARG_LIST_NIL") { return New-NodeFromToken $State $token }
    if ($token.Value.Name -ne "N_ARG_LIST") { throw "expected argument list" }
    return New-NodeFromToken $State $token (Read-Expression $State ($Depth+1)) $null (Read-ArgumentList $State ($Depth+1))
}

function Read-Initializer {
    param([hashtable]$State, [int]$Depth)
    $token = Read-Token $State "NODE" $null -Depth $Depth
    switch ($token.Value.Name) {
        "N_INIT_LIST_NIL" { return New-NodeFromToken $State $token }
        "N_INIT_LIST_ONE" { return New-NodeFromToken $State $token $null (Read-Expression $State ($Depth+1)) }
        "N_INIT_LIST" { return New-NodeFromToken $State $token (Read-Initializer $State ($Depth+1)) $null (Read-Initializer $State ($Depth+1)) }
        default { throw "unsupported initializer $($token.Value.Name)" }
    }
}

function ConvertFrom-AstPrint {
    param([string]$Output)
    $tokens = @(ConvertFrom-AstPrintTokens $Output)
    $state = New-ParserState $tokens
    $rootToken = Read-Token $state "NODE" $null -Depth 0
    if ($rootToken.Value.Name -ne "N_PROGRAM") { throw "expected N_PROGRAM" }
    $root = New-NodeFromToken $state $rootToken $null (Read-IdList $state 1 $true)
    if ($state.Position -ne $state.Tokens.Count) { throw "unexpected trailing AST_PRINT content" }
    $unresolved = @($state.Types.GetEnumerator() | Where-Object { $null -eq $_.Value.Kind })
    if ($unresolved.Count -gt 0) { throw "DONE type address could not be resolved without guessing" }
    return $root
}

function Resolve-ExpectedValue {
    param($Value, [hashtable]$Objects)
    if ($null -eq $Value) { return $null }
    if ($Value -is [pscustomobject] -and $Value.PSObject.Properties.Name -contains "ref") {
        $name = [string]$Value.ref
        if (-not $Objects.ContainsKey($name)) { throw "unknown expected object reference: $name" }
        return $Objects[$name]
    }
    return $Value
}

function Import-ExpectedGraph {
    param([string]$JsonPath, [string]$RootDirectory)
    $document = Get-Content -LiteralPath $JsonPath -Raw -Encoding UTF8 | ConvertFrom-Json
    $manual = Join-Path $RootDirectory ([string]$document.manual_reference)
    $source = Join-Path $RootDirectory ([string]$document.source)
    if (-not (Test-Path -LiteralPath $manual -PathType Leaf)) { throw "manual TXT reference not found: $manual" }
    if (-not (Test-Path -LiteralPath $source -PathType Leaf)) { throw "source file not found: $source" }
    $objects = @{}
    foreach ($record in $document.objects) {
        $objects[[string]$record.id] = [ordered]@{ Key="expected:$($record.id)"; Class=[string]$record.class }
    }
    foreach ($record in $document.objects) {
        $target = $objects[[string]$record.id]
        foreach ($property in $record.PSObject.Properties) {
            if ($property.Name -in @("id","class")) { continue }
            $target[$property.Name] = Resolve-ExpectedValue $property.Value $objects
        }
    }
    $rootName = [string]$document.root
    if (-not $objects.ContainsKey($rootName)) { throw "expected root object not found: $rootName" }
    return @{ Root=$objects[$rootName]; Objects=$objects; Source=$source; Manual=$manual; Test=[string]$document.test }
}

function Format-AstValue {
    param($Value)
    if ($null -eq $Value) { return "NULL" }
    if ($Value -isnot [System.Collections.IDictionary] -or -not $Value.Contains("Class")) { return [string]$Value }
    switch ($Value.Class) {
        "A_NODE" {
            if ($Value.Name -eq "N_EXP_IDENT") { return "N_EXP_IDENT($($Value.Clink.Name))" }
            if ($Value.Name -in @("N_EXP_INT_CONST","N_EXP_CHAR_CONST")) { return "$($Value.Name)($($Value.Clink))" }
            return [string]$Value.Name
        }
        "A_ID" { return "A_ID(`"$($Value.Name)`", $($Value.Kind), level=$($Value.Level))" }
        "A_ID_REF" { return "A_ID_REF(`"$($Value.Name)`", $($Value.Kind), level=$($Value.Level))" }
        "A_TYPE" { return [string]$Value.Kind }
    }
    return [string]$Value
}

function Add-AstDifference {
    param([hashtable]$State, [string[]]$Path, $Expected, $Actual)
    [void]$State.Differences.Add([pscustomobject]@{
        Path=($Path -join " > "); Expected=$Expected; Actual=$Actual
    })
}

function Compare-AstValue {
    param($Expected, $Actual, [string[]]$Path, [hashtable]$State)
    if ($null -eq $Expected -or $null -eq $Actual) {
        if (-not ($null -eq $Expected -and $null -eq $Actual)) { Add-AstDifference $State $Path $Expected $Actual }
        return
    }
    $expectedObject = $Expected -is [System.Collections.IDictionary] -and $Expected.Contains("Class")
    $actualObject = $Actual -is [System.Collections.IDictionary] -and $Actual.Contains("Class")
    if (-not $expectedObject -or -not $actualObject) {
        if ($expectedObject -ne $actualObject -or $Expected -ne $Actual) { Add-AstDifference $State $Path $Expected $Actual }
        return
    }
    if ($Expected.Class -ne $Actual.Class) { Add-AstDifference $State $Path $Expected $Actual; return }
    if ($State.ExpectedMap.ContainsKey($Expected.Key)) {
        if ($State.ExpectedMap[$Expected.Key] -ne $Actual.Key) { Add-AstDifference $State ($Path + "REFERENCE_IDENTITY") $Expected $Actual }
        return
    }
    if ($State.ActualMap.ContainsKey($Actual.Key) -and $State.ActualMap[$Actual.Key] -ne $Expected.Key) {
        Add-AstDifference $State ($Path + "REFERENCE_IDENTITY") $Expected $Actual; return
    }
    $State.ExpectedMap[$Expected.Key] = $Actual.Key
    $State.ActualMap[$Actual.Key] = $Expected.Key

    if ($Expected.Class -eq "A_NODE") {
        if ($Expected.Name -ne $Actual.Name) { Add-AstDifference $State $Path $Expected $Actual; return }
        Compare-AstValue $Expected.Type $Actual.Type ($Path + "TYPE") $State
        if ($Expected.Value -ne $Actual.Value) { Add-AstDifference $State ($Path + "VALUE") $Expected.Value $Actual.Value }
        $leftPath = $Path + "llink"; $centerPath = $Path + "clink"; $rightPath = $Path + "rlink"
        if ($Expected.Name -eq "N_PROGRAM" -and $null -ne $Expected.Clink) { $centerPath = $Path + $Expected.Clink.Name }
        elseif ($Expected.Name -eq "N_STMT_COMPOUND") { $leftPath = $Path + "DECLARATIONS"; $rightPath = $Path }
        elseif ($Expected.Name -eq "N_STMT_FOR") { $leftPath = $Path + "N_FOR_EXP"; $rightPath = $Path + "BODY" }
        elseif ($Expected.Name -eq "N_FOR_EXP") { $leftPath = $Path + "INIT"; $centerPath = $Path + "CONDITION"; $rightPath = $Path + "INCREMENT" }
        elseif ($Expected.Name -eq "N_STMT_LIST" -and $null -ne $Expected.Llink) {
            $labels = @{N_STMT_RETURN="RETURN";N_STMT_EXPRESSION="EXPRESSION";N_STMT_COMPOUND="BLOCK";N_STMT_IF="IF";N_STMT_IF_ELSE="IF_ELSE";N_STMT_FOR="FOR"}
            $label = if ($labels.ContainsKey($Expected.Llink.Name)) { $labels[$Expected.Llink.Name] } else { "STATEMENT" }
            $leftPath = $Path + $label; $rightPath = $Path
        }
        elseif ($Expected.Llink -is [System.Collections.IDictionary] -and $Expected.Llink.Class -eq "A_NODE" -and $Expected.Llink.Name -notin @("N_EXP_IDENT","N_EXP_INT_CONST","N_EXP_CHAR_CONST")) { $leftPath = $Path + $Expected.Llink.Name }
        elseif ($Expected.Clink -is [System.Collections.IDictionary] -and $Expected.Clink.Class -eq "A_NODE" -and $Expected.Clink.Name -notin @("N_EXP_IDENT","N_EXP_INT_CONST","N_EXP_CHAR_CONST")) { $centerPath = $Path + $Expected.Clink.Name }
        Compare-AstValue $Expected.Llink $Actual.Llink $leftPath $State
        Compare-AstValue $Expected.Clink $Actual.Clink $centerPath $State
        Compare-AstValue $Expected.Rlink $Actual.Rlink $rightPath $State
    }
    elseif ($Expected.Class -eq "A_ID") {
        foreach ($field in @("Name","Kind","Level","Value","Address")) {
            if ($Expected[$field] -ne $Actual[$field]) { Add-AstDifference $State $Path $Expected $Actual; break }
        }
        Compare-AstValue $Expected.Type $Actual.Type ($Path + "TYPE") $State
        Compare-AstValue $Expected.Init $Actual.Init ($Path + "INIT") $State
        $linkPath = if ($null -ne $Expected.Link) { $Path[0..($Path.Count-2)] + $Expected.Link.Name } else { $Path + "LINK" }
        Compare-AstValue $Expected.Link $Actual.Link $linkPath $State
    }
    elseif ($Expected.Class -eq "A_ID_REF") {
        foreach ($field in @("Name","Kind","Level","Value","Address")) {
            if ($Expected[$field] -ne $Actual[$field]) { Add-AstDifference $State $Path $Expected $Actual; break }
        }
        Compare-AstValue $Expected.Type $Actual.Type ($Path + "TYPE") $State
        Compare-AstValue $Expected.Target $Actual.Target ($Path + "TARGET") $State
    }
    elseif ($Expected.Class -eq "A_TYPE") {
        if ($Expected.Kind -ne $Actual.Kind) { Add-AstDifference $State $Path $Expected $Actual; return }
        $elementLabel = if ($Expected.Kind -eq "T_FUNC") { "RETURN_TYPE" } else { "ELEMENT_TYPE" }
        $fieldLabel = if ($Expected.Kind -eq "T_FUNC") { "PARAMETER" } else { "FIELD" }
        $exprLabel = if ($Expected.Kind -eq "T_FUNC") { "BODY" } else { "EXPR" }
        Compare-AstValue $Expected.ElementType $Actual.ElementType ($Path + $elementLabel) $State
        Compare-AstValue $Expected.Field $Actual.Field ($Path + $fieldLabel) $State
        Compare-AstValue $Expected.Expr $Actual.Expr ($Path + $exprLabel) $State
    }
}

function Compare-AstGraph {
    param($Expected, $Actual)
    $state = @{
        Differences=(New-Object System.Collections.ArrayList);
        ExpectedMap=@{}; ActualMap=@{}
    }
    Compare-AstValue $Expected $Actual @("N_PROGRAM") $state
    return $state.Differences.ToArray()
}
