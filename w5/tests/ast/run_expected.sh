#!/usr/bin/env bash

set -u

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
parser=${1:-"$script_dir/../../parser"}
selection=${2:-all}
status=0
passed=0
failed=0

if [[ ! -x "$parser" && -x "$parser.exe" ]]; then
    parser="$parser.exe"
fi

if [[ ! -x "$parser" ]]; then
    printf 'parser executable not found: %s\n' "$parser" >&2
    printf 'usage: %s /path/to/parser [test-number|list]\n' "$0" >&2
    exit 2
fi

if [[ -z "${NO_COLOR+x}" ]] && { [[ -t 1 ]] || [[ -n "${FORCE_COLOR+x}" ]]; }; then
    green=$'\033[32m'
    red=$'\033[31m'
    cyan=$'\033[36m'
    bold=$'\033[1m'
    reset=$'\033[0m'
else
    green=
    red=
    cyan=
    bold=
    reset=
fi

run_expected() {
    local number=$1
    local label=$2
    local source=$3

    if (( selected != 0 && selected != number )); then
        return
    fi

    if env AST_TEST_EXPECTED_NUMBER="$number" \
        "$parser" < "$script_dir/cases/$source" >/dev/null 2>&1; then
        printf '%sPASS%s %s[ASTEXP:%02d]%s %s\n' "$green" "$reset" \
            "$cyan" "$number" "$reset" "$label"
        passed=$((passed + 1))
    else
        printf '%sFAIL%s %s[ASTEXP:%02d]%s %s\n' "$red" "$reset" \
            "$cyan" "$number" "$reset" "$label"
        env AST_TEST_EXPECTED_NUMBER="$number" "$parser" < "$script_dir/cases/$source"
        failed=$((failed + 1))
        status=1
    fi
}

if [[ "$selection" == "list" ]]; then
    printf '%s[ASTEXP:01]%s ASTEXP_01_Precedence          03 precedence\n' "$cyan" "$reset"
    printf '%s[ASTEXP:02]%s ASTEXP_02_IfElse             07 if/else\n' "$cyan" "$reset"
    printf '%s[ASTEXP:03]%s ASTEXP_03_For                09 for\n' "$cyan" "$reset"
    printf '%s[ASTEXP:04]%s ASTEXP_04_FunctionPrototype  24 function prototype\n' "$cyan" "$reset"
    printf '%s[ASTEXP:05]%s ASTEXP_05_FunctionParameters 25 function parameters\n' "$cyan" "$reset"
    printf '%s[ASTEXP:06]%s ASTEXP_06_ScopeShadowing     44 scope shadowing\n' "$cyan" "$reset"
    printf '%s[ASTEXP:07]%s ASTEXP_07_FunctionDeclarator 59 function declarator\n' "$cyan" "$reset"
    exit 0
fi

selected=0
if [[ "$selection" != "all" ]]; then
    if [[ ! "$selection" =~ ^[0-9]+$ ]]; then
        printf 'invalid expected-AST test number: %s\n' "$selection" >&2
        exit 2
    fi

    selected=$((10#$selection))
    if (( selected < 1 || selected > 7 )); then
        printf 'invalid expected-AST test number: %s (valid: 1-7)\n' \
            "$selection" >&2
        exit 2
    fi
fi

run_expected 1 'ASTEXP_01_Precedence (03 precedence)' '03_precedence.c'
run_expected 2 'ASTEXP_02_IfElse (07 if/else)' '07_if_else.c'
run_expected 3 'ASTEXP_03_For (09 for)' '09_for.c'
run_expected 4 'ASTEXP_04_FunctionPrototype (24 function prototype)' '24_function_prototype.c'
run_expected 5 'ASTEXP_05_FunctionParameters (25 function parameters)' '25_function_parameters.c'
run_expected 6 'ASTEXP_06_ScopeShadowing (44 scope shadowing)' '44_scope_shadowing.c'
run_expected 7 'ASTEXP_07_FunctionDeclarator (59 function declarator)' '59_function_declarator.c'

printf '\n%sSUMMARY%s %s[ASTEXP]%s %s%d passed%s, %s%d failed%s, %d total\n' \
    "$bold" "$reset" "$cyan" "$reset" "$green" "$passed" "$reset" \
    "$red" "$failed" "$reset" "$((passed + failed))"

exit "$status"
