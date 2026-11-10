#!/usr/bin/env bash

set -u

export LC_ALL=C

script_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)
parser=${1:-"$script_dir/../../parser"}
selection=${2:-}

if [[ ! -x "$parser" && -x "$parser.exe" ]]; then
    parser="$parser.exe"
fi

if [[ -z "${NO_COLOR+x}" ]] && { [[ -t 1 ]] || [[ -n "${FORCE_COLOR+x}" ]]; }; then
    red=$'\033[31m'
    cyan=$'\033[36m'
    reset=$'\033[0m'
else
    red=
    cyan=
    reset=
fi

if [[ ! -x "$parser" ]]; then
    printf '%sERROR%s [ASTTREE] parser executable not found: %s\n' \
        "$red" "$reset" "$parser" >&2
    exit 2
fi

cases=("$script_dir"/cases/*.c)

if [[ "$selection" == "list" ]]; then
    for index in "${!cases[@]}"; do
        printf '%s[ASTTREE:%02d]%s %s\n' "$cyan" "$((index + 1))" \
            "$reset" "$(basename "${cases[$index]}")"
    done
    exit 0
fi

if [[ -z "$selection" ]]; then
    printf '%sERROR%s [ASTTREE] Usage: make print-ast FILE=list|number|path\n' \
        "$red" "$reset" >&2
    exit 2
fi

input=

if [[ "$selection" =~ ^[0-9]+$ ]]; then
    number=$((10#$selection))

    if (( number < 1 || number > ${#cases[@]} )); then
        printf '%sERROR%s [ASTTREE] Invalid number: %s (valid: 1-%d)\n' \
            "$red" "$reset" "$selection" "${#cases[@]}" >&2
        exit 2
    fi

    input=${cases[$((number - 1))]}
elif [[ -f "$selection" ]]; then
    input=$selection
else
    printf '%sERROR%s [ASTTREE] Input file not found: %s\n' \
        "$red" "$reset" "$selection" >&2
    exit 2
fi

printf '%s[ASTTREE]%s %s\n' "$cyan" "$reset" "$(basename "$input")"
"$parser" --print-ast < "$input"
