#!/usr/bin/env bash
set -u

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
project_dir=$(CDPATH= cd -- "$script_dir/../.." && pwd)
parser=${1:-"$project_dir/parser"}
if [ ! -f "$parser" ] && [ -f "${parser}.exe" ]; then
    parser="${parser}.exe"
fi
result_file=$(mktemp "${TMPDIR:-/tmp}/w4-parser-test.XXXXXX") || exit 1
trap 'rm -f "$result_file"' EXIT HUP INT TERM

passed=0
failed=0

run_valid() {
    input=$1
    if "$parser" < "$input" > "$result_file" 2>&1 && grep -q "N_PROGRAM" "$result_file"; then
        printf 'PASS valid   %s\n' "$(basename "$input")"
        passed=$((passed + 1))
    else
        printf 'FAIL valid   %s\n' "$(basename "$input")"
        cat "$result_file"
        failed=$((failed + 1))
    fi
}

run_invalid() {
    input=$1
    if "$parser" < "$input" > "$result_file" 2>&1; then
        printf 'FAIL invalid %s (accepted)\n' "$(basename "$input")"
        cat "$result_file"
        failed=$((failed + 1))
    elif grep -qi "syntax error" "$result_file"; then
        printf 'PASS invalid %s\n' "$(basename "$input")"
        passed=$((passed + 1))
    else
        printf 'FAIL invalid %s (no syntax error message)\n' "$(basename "$input")"
        cat "$result_file"
        failed=$((failed + 1))
    fi
}

for input in "$script_dir"/valid/*.c; do
    run_valid "$input"
done

for input in "$script_dir"/invalid/*.c; do
    run_invalid "$input"
done

printf 'int main()\n{\n    return 0;\n}\n' | "$parser" > "$result_file" 2>&1
if [ "$?" -eq 0 ] && grep -q "N_PROGRAM" "$result_file"; then
    printf 'PASS newline LF\n'
    passed=$((passed + 1))
else
    printf 'FAIL newline LF\n'
    cat "$result_file"
    failed=$((failed + 1))
fi

printf 'int main()\r\n{\r\n    return 0;\r\n}\r\n' | "$parser" > "$result_file" 2>&1
if [ "$?" -eq 0 ] && grep -q "N_PROGRAM" "$result_file"; then
    printf 'PASS newline CRLF\n'
    passed=$((passed + 1))
else
    printf 'FAIL newline CRLF\n'
    cat "$result_file"
    failed=$((failed + 1))
fi

printf '\n%d passed, %d failed\n' "$passed" "$failed"
[ "$failed" -eq 0 ]
