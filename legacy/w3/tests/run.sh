#!/usr/bin/env bash

set -u

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
parser=${1:-"$script_dir/../parser"}
status=0
passed=0
failed=0

if [[ -t 1 && -z "${NO_COLOR:-}" ]]; then
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
    printf 'usage: %s /path/to/parser\n' "$0" >&2
    exit 2
fi

for test_case in "$script_dir"/valid/*.c; do
    if "$parser" < "$test_case" >/dev/null 2>&1; then
        printf '%sPASS%s %svalid%s   %s\n' "$green" "$reset" "$cyan" "$reset" "$(basename "$test_case")"
        passed=$((passed + 1))
    else
        printf '%sFAIL%s %svalid%s   %s\n' "$red" "$reset" "$cyan" "$reset" "$(basename "$test_case")"
        failed=$((failed + 1))
        status=1
    fi
done

for test_case in "$script_dir"/invalid/*.c; do
    if "$parser" < "$test_case" >/dev/null 2>&1; then
        printf '%sFAIL%s %sinvalid%s %s\n' "$red" "$reset" "$cyan" "$reset" "$(basename "$test_case")"
        failed=$((failed + 1))
        status=1
    else
        printf '%sPASS%s %sinvalid%s %s\n' "$green" "$reset" "$cyan" "$reset" "$(basename "$test_case")"
        passed=$((passed + 1))
    fi
done

printf '\n%sResult:%s %s%d passed%s, %s%d failed%s, %d total\n' \
    "$bold" "$reset" "$green" "$passed" "$reset" "$red" "$failed" "$reset" "$((passed + failed))"

exit "$status"
