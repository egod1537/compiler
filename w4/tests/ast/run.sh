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

if [[ ! -x "$parser" ]]; then
    printf 'parser executable not found: %s\n' "$parser" >&2
    printf 'usage: %s /path/to/parser [test-number|list]\n' "$0" >&2
    exit 2
fi

test_cases=()
test_kinds=()

for test_case in "$script_dir"/valid/*.c; do
    test_cases+=("$test_case")
    test_kinds+=("valid")
done

for test_case in "$script_dir"/invalid/*.c; do
    test_cases+=("$test_case")
    test_kinds+=("invalid")
done

if [[ "$selection" == "list" ]]; then
    for index in "${!test_cases[@]}"; do
        printf '%s[AST:%02d]%s %-7s %s\n' "$cyan" "$((index + 1))" \
            "$reset" "${test_kinds[$index]}" "$(basename "${test_cases[$index]}")"
    done
    exit 0
fi

selected=0
if [[ "$selection" != "all" ]]; then
    if [[ ! "$selection" =~ ^[0-9]+$ ]]; then
        printf 'invalid AST test number: %s\n' "$selection" >&2
        exit 2
    fi

    selected=$((10#$selection))
    if (( selected < 1 || selected > ${#test_cases[@]} )); then
        printf 'invalid AST test number: %s (valid: 1-%d)\n' \
            "$selection" "${#test_cases[@]}" >&2
        exit 2
    fi
fi

for index in "${!test_cases[@]}"; do
    number=$((index + 1))
    if (( selected != 0 && selected != number )); then
        continue
    fi

    test_case=${test_cases[$index]}
    kind=${test_kinds[$index]}
    result=1

    if "$parser" < "$test_case" >/dev/null 2>&1; then
        if [[ "$kind" == "valid" ]]; then
            result=0
        fi
    elif [[ "$kind" == "invalid" ]]; then
        result=0
    fi

    if (( result == 0 )); then
        printf '%sPASS%s %s[AST:%02d]%s %-7s %s\n' "$green" "$reset" \
            "$cyan" "$number" "$reset" "$kind" "$(basename "$test_case")"
        passed=$((passed + 1))
    else
        printf '%sFAIL%s %s[AST:%02d]%s %-7s %s\n' "$red" "$reset" \
            "$cyan" "$number" "$reset" "$kind" "$(basename "$test_case")"
        failed=$((failed + 1))
        status=1
    fi
done

printf '\n%sSUMMARY%s %s[AST]%s %s%d passed%s, %s%d failed%s, %d total\n' \
    "$bold" "$reset" "$cyan" "$reset" "$green" "$passed" "$reset" \
    "$red" "$failed" "$reset" "$((passed + failed))"

exit "$status"
