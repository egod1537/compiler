#!/usr/bin/env bash

set -u

script_dir=$(CDPATH='' cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
project_dir=$(CDPATH='' cd -- "$script_dir/.." && pwd)
manifest="$script_dir/cases.tsv"
parser="$project_dir/parser"
selection=${1:-all}
build_parser=1

if [[ "${2:-}" == "--no-build" ]]; then
    build_parser=0
elif [[ -n "${2:-}" ]]; then
    printf 'unknown option: %s\n' "$2" >&2
    exit 2
fi

list_cases() {
    while IFS='|' read -r id category description expected_exit source check1 check2 check3; do
        [[ -z "$id" || "$id" == \#* ]] && continue
        printf '%-3s %-8s exit=%s  %s\n' "$id" "$category" "$expected_exit" "$description"
    done < "$manifest"
}

if [[ "$selection" == "list" ]]; then
    list_cases
    exit 0
fi

case "$selection" in
    all|parse|ast|error|boundary)
        ;;
    *)
        if ! awk -F '|' -v selected="$selection" '$1 == selected { found=1 } END { exit !found }' "$manifest"; then
            printf 'unknown test selection: %s\n' "$selection" >&2
            printf 'use all, parse, ast, error, boundary, list, or a case ID such as A01\n' >&2
            exit 2
        fi
        ;;
esac

temp_dir=$(mktemp -d "${TMPDIR:-/tmp}/w4-1-tests.XXXXXX") || exit 2
trap 'rm -R -- "$temp_dir"' EXIT HUP INT TERM
build_log="$temp_dir/build.log"

run_build_step() {
    printf '[BUILD]'
    printf ' %s' "$@"
    printf '\n'
    if ! (
        cd "$project_dir" || exit 2
        "$@"
    ) >> "$build_log" 2>&1; then
        printf 'BUILD FAIL (environment/build issue)\n' >&2
        sed 's/^/    /' "$build_log" >&2
        exit 2
    fi
}

if (( build_parser )); then
    : > "$build_log"
    run_build_step bison -d -o y.tab.c c.y
    run_build_step flex -o lex.yy.c c.l
    run_build_step gcc -o parser y.tab.c lex.yy.c support.c print.c main.c
    printf '[BUILD PASS] parser created\n\n'
elif [[ ! -x "$parser" ]]; then
    printf 'parser executable not found: %s\n' "$parser" >&2
    exit 2
fi

normalize_output() {
    LC_ALL=C sed -E \
        -e 's/0x[0-9a-fA-F]+/<ADDR>/g' \
        -e 's/\(nil\)/<ADDR>/g' \
        "$1" > "$2"
}

extract_nodes() {
    awk '
        /N_[A-Z_]+/ {
            prefix=$0
            sub(/N_[A-Z_]+.*/, "", prefix)
            depth=0
            while (index(prefix, "|  ") != 0) {
                sub(/\|  /, "", prefix)
                depth++
            }
            match($0, /N_[A-Z_]+/)
            print depth ":" substr($0, RSTART, RLENGTH)
        }
    ' "$1" > "$2"
}

parse_passed=0
parse_failed=0
ast_passed=0
ast_failed=0
error_passed=0
error_failed=0
boundary_passed=0
boundary_failed=0
found=0

while IFS='|' read -r id category description expected_exit source check1 check2 check3; do
    [[ -z "$id" || "$id" == \#* ]] && continue

    if [[ "$selection" != "all" && "$selection" != "$category" && "$selection" != "$id" ]]; then
        continue
    fi
    found=1

    source_path="$script_dir/$source"
    raw_output="$temp_dir/$id.raw"
    normalized_output="$temp_dir/$id.normalized"
    actual_nodes="$temp_dir/$id.nodes"

    "$parser" < "$source_path" > "$raw_output" 2>&1
    actual_exit=$?
    normalize_output "$raw_output" "$normalized_output"

    result=0
    reason=
    if (( actual_exit != expected_exit )); then
        result=1
        reason="exit mismatch (parser behavior, test expectation, or grammar limit)"
    fi

    if [[ "$category" == "ast" ]]; then
        expected_nodes="$script_dir/$check1"
        extract_nodes "$normalized_output" "$actual_nodes"
        if ! cmp -s "$expected_nodes" "$actual_nodes"; then
            result=1
            reason="AST node/depth mismatch (implementation or expected-tree issue)"
        fi
    else
        for expected_text in "$check1" "$check2" "$check3"; do
            [[ -z "$expected_text" ]] && continue
            if ! grep -F -q -- "$expected_text" "$normalized_output"; then
                result=1
                reason="expected output missing (implementation or expectation issue)"
            fi
        done
    fi

    if [[ "$category" != "error" ]]; then
        if ! grep -F -q -- '=======  syntax tree  ==========' "$normalized_output" ||
           ! grep -F -q -- 'N_PROGRAM' "$normalized_output" ||
           grep -F -q -- '****syntax tree error******' "$normalized_output"; then
            result=1
            reason="missing or malformed syntax-tree output"
        fi
    elif grep -F -q -- '=======  syntax tree  ==========' "$normalized_output"; then
        result=1
        reason="AST printed after an expected error"
    fi

    if (( result == 0 )); then
        printf 'PASS [%s] %-8s %s\n' "$id" "$category" "$description"
        case "$category" in
            parse) parse_passed=$((parse_passed + 1)) ;;
            ast) ast_passed=$((ast_passed + 1)) ;;
            error) error_passed=$((error_passed + 1)) ;;
            boundary) boundary_passed=$((boundary_passed + 1)) ;;
        esac
    else
        printf 'FAIL [%s] %-8s %s\n' "$id" "$category" "$description"
        printf '  reason: %s\n' "$reason"
        printf '  input (%s):\n' "$source"
        sed 's/^/    /' "$source_path"
        printf '  expected exit: %d\n' "$expected_exit"
        if [[ "$category" == "ast" ]]; then
            printf '  expected node tree:\n'
            sed 's/^/    /' "$expected_nodes"
            printf '  actual node tree:\n'
            sed 's/^/    /' "$actual_nodes"
        else
            printf '  expected output fragments:\n'
            for expected_text in "$check1" "$check2" "$check3"; do
                [[ -n "$expected_text" ]] && printf '    %s\n' "$expected_text"
            done
        fi
        printf '  actual exit: %d\n' "$actual_exit"
        printf '  actual normalized output:\n'
        sed 's/^/    /' "$normalized_output"
        case "$category" in
            parse) parse_failed=$((parse_failed + 1)) ;;
            ast) ast_failed=$((ast_failed + 1)) ;;
            error) error_failed=$((error_failed + 1)) ;;
            boundary) boundary_failed=$((boundary_failed + 1)) ;;
        esac
    fi
done < "$manifest"

if (( found == 0 )); then
    printf 'no tests selected\n' >&2
    exit 2
fi

passed=$((parse_passed + ast_passed + error_passed + boundary_passed))
failed=$((parse_failed + ast_failed + error_failed + boundary_failed))

printf '\nSUMMARY\n'
printf '  parse:    %2d passed, %2d failed\n' "$parse_passed" "$parse_failed"
printf '  ast:      %2d passed, %2d failed\n' "$ast_passed" "$ast_failed"
printf '  error:    %2d passed, %2d failed\n' "$error_passed" "$error_failed"
printf '  boundary: %2d passed, %2d failed\n' "$boundary_passed" "$boundary_failed"
printf '  total:    %2d passed, %2d failed\n' "$passed" "$failed"

(( failed == 0 ))
