#!/usr/bin/env python3
"""Generate reproducible Assignment 7 analyzer/cc comparison artifacts."""

from __future__ import annotations

import csv
from datetime import datetime, timezone
import json
import os
from pathlib import Path
import re
import shlex
import socket
import subprocess
import sys
from typing import Any


CH7_DIR = Path(__file__).resolve().parent
PROJECT_DIR = CH7_DIR.parent.parent
CASES_DIR = CH7_DIR / "cases"
MANIFEST_PATH = CH7_DIR / "manifest.json"
OUTPUT_DIR = CH7_DIR / "gcc_comparison"
TRANSCRIPT_DIR = OUTPUT_DIR / "transcripts"
PARSER = PROJECT_DIR / "parser"
TIMEOUT_SECONDS = 10
CC_OPTIONS = ["-std=c11", "-Wall", "-Wextra", "-pedantic", "-fsyntax-only"]

ANALYZER_DIAGNOSTIC_RE = re.compile(
    r"(?:syntax error:|\*\*\* semantic error|--- warning)"
)
CC_DIAGNOSTIC_RE = re.compile(r"(?:^|:\d+(?::\d+)?): (warning|error):")
INCIDENTAL_CC_PATTERNS = (
    "a function declaration without a prototype",
    "unused variable",
    "unused parameter",
    "unused function",
    "set but not used",
)

LEVEL_KO = {"normal": "정상", "warning": "경고", "error": "오류"}
SEVERITY_DIFFERENCE = {"TC05", "TC10", "TC11", "TC44"}
PARTIAL_MEANING = {"TC16", "TC20", "TC24", "TC37"}


def timestamp() -> str:
    return datetime.now(timezone.utc).astimezone().isoformat(timespec="seconds")


def run(command: list[str], *, input_bytes: bytes | None = None) -> dict[str, Any]:
    try:
        completed = subprocess.run(
            command,
            cwd=PROJECT_DIR,
            input=input_bytes,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=TIMEOUT_SECONDS,
            check=False,
        )
        return {
            "command": shlex.join(command),
            "exit": completed.returncode,
            "output": completed.stdout.decode("utf-8", errors="replace"),
            "timeout": False,
        }
    except subprocess.TimeoutExpired as exc:
        partial = exc.stdout or b""
        if isinstance(partial, bytes):
            partial = partial.decode("utf-8", errors="replace")
        return {"command": shlex.join(command), "exit": None, "output": partial, "timeout": True}


def analyzer_diagnostics(output: str) -> list[str]:
    return [line for line in output.splitlines() if ANALYZER_DIAGNOSTIC_RE.search(line)]


def cc_diagnostics(output: str) -> list[dict[str, Any]]:
    result: list[dict[str, Any]] = []
    for line in output.splitlines():
        match = CC_DIAGNOSTIC_RE.search(line)
        if not match:
            continue
        result.append(
            {
                "level": match.group(1),
                "message": line,
                "incidental": any(pattern in line for pattern in INCIDENTAL_CC_PATTERNS),
            }
        )
    return result


def analyzer_level(exit_code: int | None, diagnostics: list[str]) -> str:
    if exit_code not in (0, None) or any("error" in line for line in diagnostics):
        return "error"
    if any("warning" in line for line in diagnostics):
        return "warning"
    return "normal"


def cc_level(exit_code: int | None, diagnostics: list[dict[str, Any]], *, core: bool) -> str:
    selected = [item for item in diagnostics if not core or not item["incidental"]]
    if exit_code not in (0, None) or any(item["level"] == "error" for item in selected):
        return "error"
    if any(item["level"] == "warning" for item in selected):
        return "warning"
    return "normal"


def cause_for(case_id: str, raw_cc_level: str, core_cc_level: str) -> str:
    if case_id in {"TC05", "TC11", "TC44"}:
        return "같은 과다 초기값을 분석기는 오류로 중단하지만 cc는 경고 후 계속 처리한다."
    if case_id == "TC10":
        return "0 길이 배열을 분석기는 오류로 처리하지만 cc는 비표준 확장 기능 경고로 수락한다."
    if case_id == "TC16":
        return "없는 필드 진단은 같지만 분석기가 후속 형변환 오류를 한 건 더 연쇄 출력한다."
    if case_id == "TC20":
        return "콤마식의 결과 타입과 수락 판정은 같지만 cc만 값이 버려지는 왼쪽 피연산자를 경고한다."
    if case_id == "TC24":
        return "분석기는 int·float 일반 산술 변환도 경고하지만 cc는 표준 변환으로 보고 진단하지 않는다."
    if case_id == "TC37":
        return "교재 분석기는 조건식에 정수형을 요구하고, cc는 스칼라 조건을 허용한 뒤 double→_Bool 변환을 경고한다."
    if raw_cc_level != core_cc_level:
        return "핵심 의미 판정은 같고 cc의 프로토타입 또는 미사용 변수 경고만 추가되었다."
    return "두 검사기가 같은 C 의미 규칙에 따라 동일한 핵심 판정을 내렸다."


def meaning_for(case_id: str) -> str:
    if case_id in PARTIAL_MEANING:
        return "부분 일치"
    if case_id in SEVERITY_DIFFERENCE:
        return "일치(수준 차이)"
    return "일치"


def transcript_text(
    *, prompt: str, display_command: str, output: str, exit_code: int | None, timeout: bool
) -> str:
    body = f"{prompt}{display_command}\n"
    if output:
        body += output
        if not body.endswith("\n"):
            body += "\n"
    if timeout:
        body += "[timeout]\n"
    elif exit_code == 0 and not output:
        body += "[exit=0] compile success\n"
    else:
        body += f"[exit={exit_code}]\n"
    return body


def main() -> int:
    cases = json.loads(MANIFEST_PATH.read_text(encoding="utf-8"))
    if len(cases) != 49:
        raise ValueError(f"expected 49 cases, found {len(cases)}")
    if not PARSER.is_file():
        raise FileNotFoundError("parser is missing; run make first")

    cc_command = shlex.split(os.environ.get("CC", "cc"))
    version = run(cc_command + ["--version"])
    if version["exit"] != 0:
        raise RuntimeError("could not read compiler version")

    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    TRANSCRIPT_DIR.mkdir(parents=True, exist_ok=True)
    prompt = f"{os.environ.get('USER', 'user')}@{socket.gethostname().split('.')[0]} w7 % "
    rows: list[dict[str, Any]] = []
    full_log: list[str] = []

    for case in cases:
        source = CASES_DIR / case["file"]
        relative_source = source.relative_to(PROJECT_DIR)
        analyzer = run([str(PARSER)], input_bytes=source.read_bytes())
        cc_args = cc_command + CC_OPTIONS + [str(relative_source)]
        compiler = run(cc_args)
        a_diag = analyzer_diagnostics(analyzer["output"])
        c_diag = cc_diagnostics(compiler["output"])
        a_level = analyzer_level(analyzer["exit"], a_diag)
        c_raw_level = cc_level(compiler["exit"], c_diag, core=False)
        c_core_level = cc_level(compiler["exit"], c_diag, core=True)
        meaning = meaning_for(case["id"])
        verdict = f"분석기 {LEVEL_KO[a_level]} / cc {LEVEL_KO[c_core_level]}"
        if c_raw_level != c_core_level:
            verdict += f" (원출력 {LEVEL_KO[c_raw_level]}, 부수 경고 제외)"

        display_command = shlex.join([Path(cc_command[0]).name] + CC_OPTIONS + [str(relative_source)])
        transcript = transcript_text(
            prompt=prompt,
            display_command=display_command,
            output=compiler["output"],
            exit_code=compiler["exit"],
            timeout=compiler["timeout"],
        )
        (TRANSCRIPT_DIR / f"{case['id']}.txt").write_text(transcript, encoding="utf-8")

        row = {
            "id": case["id"],
            "purpose": case["purpose"],
            "analyzer_exit": analyzer["exit"],
            "analyzer_level": a_level,
            "analyzer_message": "\n".join(a_diag) if a_diag else "<진단 없음>",
            "cc_exit": compiler["exit"],
            "cc_raw_level": c_raw_level,
            "cc_core_level": c_core_level,
            "cc_message": "\n".join(item["message"] for item in c_diag) if c_diag else "<진단 없음>",
            "cc_core_message": "\n".join(item["message"] for item in c_diag if not item["incidental"]) or "<핵심 진단 없음>",
            "verdict_comparison": verdict,
            "meaning_match": meaning,
            "difference_cause": cause_for(case["id"], c_raw_level, c_core_level),
            "acceptance_match": (analyzer["exit"] == 0) == (compiler["exit"] == 0),
            "analyzer_output": analyzer["output"],
            "cc_output": compiler["output"],
            "command": display_command,
        }
        rows.append(row)
        full_log.extend(
            [
                "=" * 100 + "\n",
                f"{case['id']} {case['purpose']}\n",
                f"[analyzer exit={analyzer['exit']}]\n{analyzer['output']}",
                f"[cc exit={compiler['exit']}] $ {display_command}\n{compiler['output']}",
            ]
        )

    acceptance_matches = sum(1 for row in rows if row["acceptance_match"])
    level_matches = sum(1 for row in rows if row["analyzer_level"] == row["cc_core_level"])
    exact_meaning = sum(1 for row in rows if row["meaning_match"] == "일치")
    severity_meaning = sum(1 for row in rows if row["meaning_match"] == "일치(수준 차이)")
    partial_meaning = sum(1 for row in rows if row["meaning_match"] == "부분 일치")
    summary = {
        "generated_at": timestamp(),
        "branch": "w7",
        "commit": subprocess.run(
            ["git", "rev-parse", "HEAD"], cwd=PROJECT_DIR, text=True,
            stdout=subprocess.PIPE, check=True
        ).stdout.strip(),
        "compiler_command": cc_command,
        "compiler_version": version["output"].strip(),
        "options": CC_OPTIONS,
        "total": len(rows),
        "acceptance_matches": acceptance_matches,
        "acceptance_match_rate": round(100.0 * acceptance_matches / len(rows), 2),
        "level_matches": level_matches,
        "level_match_rate": round(100.0 * level_matches / len(rows), 2),
        "meaning_exact": exact_meaning,
        "meaning_with_severity_difference": severity_meaning,
        "meaning_partial": partial_meaning,
        "rows": rows,
    }
    (OUTPUT_DIR / "comparison.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    (OUTPUT_DIR / "comparison.log").write_text("".join(full_log), encoding="utf-8")
    (OUTPUT_DIR / "compiler.txt").write_text(
        f"실행 시각: {summary['generated_at']}\n"
        f"브랜치: {summary['branch']}\n커밋: {summary['commit']}\n"
        f"컴파일러:\n{summary['compiler_version']}\n"
        f"실행 옵션: {' '.join(CC_OPTIONS)}\n",
        encoding="utf-8",
    )
    with (OUTPUT_DIR / "comparison.csv").open("w", encoding="utf-8", newline="") as stream:
        fields = [
            "id", "purpose", "analyzer_message", "cc_message", "verdict_comparison",
            "meaning_match", "difference_cause", "acceptance_match",
        ]
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        for row in rows:
            writer.writerow({key: row[key] for key in fields})

    print(f"generated {len(rows)} comparisons")
    print(f"acceptance match: {acceptance_matches}/{len(rows)} ({summary['acceptance_match_rate']:.2f}%)")
    print(f"diagnostic level match: {level_matches}/{len(rows)} ({summary['level_match_rate']:.2f}%)")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, RuntimeError, json.JSONDecodeError) as exc:
        print(f"comparison generation failed: {exc}", file=sys.stderr)
        raise SystemExit(1)
