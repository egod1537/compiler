#!/usr/bin/env bash

set -u

script_dir=$(CDPATH= cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
parser=${1:-"$script_dir/../../parser"}
selection=${2:-all}
manifest="$script_dir/cases.tsv"
output=$(mktemp "${TMPDIR:-/tmp}/w4-semerr.XXXXXX") || exit 1
trap 'rm -f "$output"' EXIT HUP INT TERM

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

if [[ "$selection" != "all" && "$selection" != "list" &&
      ! "$selection" =~ ^[0-9]+$ ]]; then
    printf 'invalid SEMERR test number: %s\n' "$selection" >&2
    exit 2
fi

selected=0
if [[ "$selection" =~ ^[0-9]+$ ]]; then
    selected=$((10#$selection))
fi

passed=0
failed=0
found=0

while IFS='|' read -r number name expected source; do
    [[ -z "$number" || "$number" == \#* ]] && continue
    numeric=$((10#$number))

    if [[ "$selection" == "list" ]]; then
        printf '%s[SEMERR:%02d]%s %-40s expected=%s\n' \
            "$cyan" "$numeric" "$reset" "$name" "$expected"
        continue
    fi

    if (( selected != 0 && selected != numeric )); then
        continue
    fi
    found=1

    "$parser" < "$script_dir/cases/$source" > "$output" 2>&1
    exit_code=$?
    actual=$(grep -Eo '\[(LEXICAL_ERROR|SYNTAX_ERROR|DECLARATION_ERROR|INTERNAL_ERROR)(:[0-9]+)?\]' "$output" |
        tr -d '[]' | paste -sd, -)
    first=${actual%%,*}
    [[ -n "$actual" ]] || actual=OK
    [[ -n "$first" ]] || first=OK

    result=1
    if [[ "$expected" == "OK" ]]; then
        if (( exit_code == 0 )) && [[ "$first" == "OK" ]]; then
            result=0
        fi
    elif (( exit_code != 0 )) && [[ "$first" == "$expected" ]]; then
        result=0
    fi

    if (( result == 0 )); then
        printf '%sPASS%s %s[SEMERR:%02d]%s %-40s expected=%-22s actual=%s\n' \
            "$green" "$reset" "$cyan" "$numeric" "$reset" "$name" \
            "$expected" "$actual"
        passed=$((passed + 1))
    else
        printf '%sFAIL%s %s[SEMERR:%02d]%s %-40s expected=%-22s actual=%s exit=%d\n' \
            "$red" "$reset" "$cyan" "$numeric" "$reset" "$name" \
            "$expected" "$actual" "$exit_code"
        sed 's/^/    /' "$output"
        failed=$((failed + 1))
    fi
done < "$manifest"

if [[ "$selection" == "list" ]]; then
    exit 0
fi

if (( selected != 0 && found == 0 )); then
    printf 'invalid SEMERR test number: %s\n' "$selection" >&2
    exit 2
fi

printf '\n%sSUMMARY%s %s[SEMERR]%s %s%d passed%s, %s%d failed%s, %d total\n' \
    "$bold" "$reset" "$cyan" "$reset" "$green" "$passed" "$reset" \
    "$red" "$failed" "$reset" "$((passed + failed))"

(( failed == 0 ))
