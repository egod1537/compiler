#!/usr/bin/env bash

set -u

script_dir=$(CDPATH='' cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
project_dir=$(CDPATH='' cd -- "$script_dir/../.." && pwd)
current=${1:-"$project_dir/parser"}
baseline=${2:-"$project_dir/../w4-1/parser"}

if [[ ! -x "$current" && -x "$current.exe" ]]; then
    current="$current.exe"
fi
if [[ ! -x "$baseline" && -x "$baseline.exe" ]]; then
    baseline="$baseline.exe"
fi
if [[ ! -x "$current" || ! -x "$baseline" ]]; then
    printf 'baseline comparison requires both parser executables\n' >&2
    exit 2
fi

temp_dir=$(mktemp -d "${TMPDIR:-/tmp}/w4-baseline.XXXXXX") || exit 1
trap 'rm -rf "$temp_dir"' EXIT HUP INT TERM

normalize_ast() {
    sed -E \
        -e 's/\r$//' \
        -e 's/TYPE:[^ ]+/TYPE:ADDR/g' \
        -e 's/\([0-9A-Fa-fx]+,/\(ADDR,/g' \
        -e 's/\(DONE:[^)]+\)/(DONE:ADDR)/g' "$1"
}

cases=()
while IFS= read -r source; do
    cases+=("$source")
done < <(
    cd "$project_dir" &&
    find tests/baseline/cases tests/ch5 tests/ast/valid tests/ast/invalid tests/ast/cases \
        tests/ast/unsupported tests/semerr/cases -type f -name '*.c' -print | sort -u
)

if (( ${#cases[@]} == 0 )); then
    printf 'no baseline comparison inputs found\n' >&2
    exit 2
fi

passed=0
failed=0
for source in "${cases[@]}"; do
    baseline_output="$temp_dir/baseline.txt"
    current_output="$temp_dir/current.txt"

    "$baseline" < "$project_dir/$source" > "$baseline_output" 2>&1
    baseline_exit=$?
    "$current" < "$project_dir/$source" > "$current_output" 2>&1
    current_exit=$?

    result=0
    if (( baseline_exit != current_exit )); then
        result=1
        printf 'FAIL [BASELINE] %-55s baseline=%d current=%d\n' \
            "$source" "$baseline_exit" "$current_exit"
    else
        normalize_ast "$baseline_output" > "$temp_dir/baseline.normalized"
        normalize_ast "$current_output" > "$temp_dir/current.normalized"
        if ! cmp -s "$temp_dir/baseline.normalized" "$temp_dir/current.normalized"; then
            result=1
            printf 'FAIL [BASELINE] %-55s output differs\n' "$source"
        fi
    fi

    if (( result == 0 )); then
        passed=$((passed + 1))
    else
        failed=$((failed + 1))
    fi
done

printf 'SUMMARY [BASELINE] %d passed, %d failed, %d total\n' \
    "$passed" "$failed" "$((passed + failed))"

(( failed == 0 ))
