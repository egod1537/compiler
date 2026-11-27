#!/usr/bin/env python3
"""과제7 시멘틱 분석기 및 과제6 회귀 테스트 러너."""

from __future__ import annotations

import csv
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import sys
from datetime import datetime, timezone
from typing import Any


CH7_DIR = Path(__file__).resolve().parent
PROJECT_DIR = CH7_DIR.parent.parent
CASES_DIR = CH7_DIR / "cases"
RESULTS_DIR = CH7_DIR / "results"
MANIFEST = CH7_DIR / "manifest.json"
PARSER = PROJECT_DIR / "parser"
TIMEOUT_SECONDS = 5

CATEGORY_LABELS = {
    "variables": "변수 선언 및 초기화",
    "arrays": "배열 및 포인터",
    "aggregates": "구조체·공용체·enum",
    "expressions": "수식 및 형변환",
    "functions": "함수",
    "statements": "명령문",
    "literals": "리터럴 테이블",
}
EXPECTED_CATEGORY_COUNTS = {
    "variables": 6,
    "arrays": 6,
    "aggregates": 5,
    "expressions": 7,
    "functions": 6,
    "statements": 7,
    "literals": 3,
}
EXPECTED_KIND_COUNTS = {"normal": 20, "error": 15, "warning": 5}

# 기존 tests/1~5의 과제6 입력 중 원래 오류 입력이다. 나머지는 정상 입력이다.
CH6_ERROR_CASES = {
    "CH6-1-6", "CH6-1-7", "CH6-1-8",
    "CH6-2-7", "CH6-2-8", "CH6-2-10",
    "CH6-3-9", "CH6-3-10",
    "CH6-4-6", "CH6-4-7", "CH6-4-8", "CH6-4-9",
    "CH6-5-4", "CH6-5-5", "CH6-5-6", "CH6-5-7",
}


def utc_timestamp() -> str:
    return datetime.now(timezone.utc).astimezone().isoformat(timespec="seconds")


def normalize_output(text: str) -> str:
    text = re.sub(r"0x[0-9a-fA-F]+", "<ADDR>", text)
    text = text.replace("(nil)", "<ADDR>")
    return text


def run_process(
    command: list[str], *, cwd: Path, input_bytes: bytes | None = None
) -> dict[str, Any]:
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            input=input_bytes,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            timeout=TIMEOUT_SECONDS,
            check=False,
        )
        output = completed.stdout.decode("utf-8", errors="replace")
        return {
            "command": shlex.join(command),
            "exit": completed.returncode,
            "output": output,
            "timeout": False,
            "crash": completed.returncode < 0,
        }
    except subprocess.TimeoutExpired as exc:
        partial = exc.stdout or b""
        if isinstance(partial, str):
            output = partial
        else:
            output = partial.decode("utf-8", errors="replace")
        return {
            "command": shlex.join(command),
            "exit": None,
            "output": output,
            "timeout": True,
            "crash": False,
        }
    except OSError as exc:
        return {
            "command": shlex.join(command),
            "exit": None,
            "output": f"runner error: {exc}\n",
            "timeout": False,
            "crash": False,
            "runner_error": True,
        }


def load_manifest() -> list[dict[str, Any]]:
    cases = json.loads(MANIFEST.read_text(encoding="utf-8"))
    if len(cases) != 40:
        raise ValueError(f"과제7 TC는 40개여야 함: 실제 {len(cases)}개")

    category_counts = {name: 0 for name in EXPECTED_CATEGORY_COUNTS}
    kind_counts = {name: 0 for name in EXPECTED_KIND_COUNTS}
    seen_ids: set[str] = set()
    for case in cases:
        case_id = case["id"]
        if case_id in seen_ids:
            raise ValueError(f"중복 TC ID: {case_id}")
        seen_ids.add(case_id)
        category_counts[case["category"]] += 1
        kind_counts[case["kind"]] += 1
        source = CASES_DIR / case["file"]
        if not source.is_file():
            raise ValueError(f"TC 소스 없음: {source}")

    if category_counts != EXPECTED_CATEGORY_COUNTS:
        raise ValueError(f"분류 개수 불일치: {category_counts}")
    if kind_counts != EXPECTED_KIND_COUNTS:
        raise ValueError(f"결과 종류 개수 불일치: {kind_counts}")
    return cases


def discover_ch6_cases() -> list[dict[str, Any]]:
    result: list[dict[str, Any]] = []
    for group in range(1, 6):
        group_dir = PROJECT_DIR / "tests" / str(group)
        paths = sorted(group_dir.glob("*.c"), key=lambda path: int(path.stem))
        for path in paths:
            case_id = f"CH6-{group}-{path.stem}"
            expected_exit = 1 if case_id in CH6_ERROR_CASES else 0
            result.append(
                {
                    "id": case_id,
                    "file": str(path.relative_to(PROJECT_DIR)),
                    "expected_exit": expected_exit,
                }
            )
    if len(result) != 48:
        raise ValueError(f"과제6 회귀 입력은 48개여야 함: 실제 {len(result)}개")
    return result


def run_build(make_command: list[str]) -> tuple[bool, str]:
    sections: list[str] = [f"과제7 빌드 로그\n시각: {utc_timestamp()}\n"]
    for command in (make_command + ["clean"], make_command):
        result = run_process(command, cwd=PROJECT_DIR)
        sections.append(f"$ {result['command']}\n")
        sections.append(result["output"])
        sections.append(f"[exit={result['exit']}]\n\n")
        if result["timeout"] or result.get("runner_error") or result["exit"] != 0:
            return False, "".join(sections)
    return True, "".join(sections)


def expected_exit_for(case: dict[str, Any]) -> int:
    return 1 if case["kind"] == "error" else 0


def evaluate_ch7(case: dict[str, Any], analyzer: dict[str, Any]) -> tuple[bool, list[str]]:
    reasons: list[str] = []
    output = analyzer["output"]
    expected_exit = expected_exit_for(case)

    if analyzer["timeout"]:
        reasons.append("타임아웃")
    if analyzer["crash"]:
        reasons.append(f"크래시(signal {-analyzer['exit']})")
    if analyzer.get("runner_error"):
        reasons.append("러너 실행 오류")
    if analyzer["exit"] != expected_exit:
        reasons.append(f"종료 코드 기대 {expected_exit}, 실제 {analyzer['exit']}")

    diagnostic = case["diagnostic"]
    if diagnostic and diagnostic not in output:
        reasons.append(f"필수 진단 누락: {diagnostic}")

    kind = case["kind"]
    if kind in {"normal", "warning"}:
        if "=======  semantic tree  ==========" not in output:
            reasons.append("시멘틱 AST 출력 누락")
        if "*** semantic error" in output or "syntax error:" in output:
            reasons.append("예상하지 않은 오류 진단")
    if kind == "normal" and "--- warning" in output:
        reasons.append("예상하지 않은 시멘틱 경고")
    if kind == "warning" and "--- warning" not in output:
        reasons.append("예상 경고 출력 누락")
    if kind == "error" and "error" not in output:
        reasons.append("오류 TC에 오류 진단이 없음")

    for check in case["checks"]:
        if check not in output:
            reasons.append(f"AST/의미 확인 문자열 누락: {check}")
    return not reasons, reasons


def run_analyzer(source: Path) -> dict[str, Any]:
    result = run_process([str(PARSER)], cwd=PROJECT_DIR, input_bytes=source.read_bytes())
    result["output"] = normalize_output(result["output"])
    return result


def run_cc(source: Path, cc_command: list[str]) -> dict[str, Any]:
    command = cc_command + [
        "-std=c11",
        "-Wall",
        "-Wextra",
        "-pedantic",
        "-fsyntax-only",
        str(source),
    ]
    result = run_process(command, cwd=PROJECT_DIR)
    result["output"] = normalize_output(result["output"])
    return result


def comparison_label(analyzer: dict[str, Any], compiler: dict[str, Any]) -> str:
    if analyzer["timeout"] or analyzer["crash"]:
        return "비교 불가"
    analyzer_accepts = analyzer["exit"] == 0
    compiler_accepts = compiler["exit"] == 0
    return "일치" if analyzer_accepts == compiler_accepts else "차이"


def append_case_log(
    sections: list[str],
    title: str,
    source: Path,
    analyzer: dict[str, Any],
    compiler: dict[str, Any],
    passed: bool,
    reasons: list[str],
) -> None:
    sections.append(f"\n{'=' * 78}\n{title}\nsource: {source.relative_to(PROJECT_DIR)}\n")
    sections.append(f"result: {'PASS' if passed else 'FAIL'}\n")
    if reasons:
        sections.append("reasons:\n")
        sections.extend(f"  - {reason}\n" for reason in reasons)
    sections.append(f"\n[semantic analyzer] $ {analyzer['command']}\n")
    sections.append(f"exit={analyzer['exit']} timeout={analyzer['timeout']} crash={analyzer['crash']}\n")
    sections.append(analyzer["output"] or "<no output>\n")
    sections.append(f"\n[system C compiler] $ {compiler['command']}\n")
    sections.append(f"exit={compiler['exit']} timeout={compiler['timeout']} crash={compiler['crash']}\n")
    sections.append(compiler["output"] or "<no output>\n")


def main() -> int:
    RESULTS_DIR.mkdir(parents=True, exist_ok=True)
    cases = load_manifest()
    regression_cases = discover_ch6_cases()
    make_command = shlex.split(os.environ.get("MAKE", "make"))
    cc_command = shlex.split(os.environ.get("CC", "cc"))

    build_ok, build_log = run_build(make_command)
    (RESULTS_DIR / "build.log").write_text(build_log, encoding="utf-8")
    if not build_ok:
        summary = {
            "generated_at": utc_timestamp(),
            "build": "FAIL",
            "tests_executed": False,
            "reason": "빌드 실패로 테스트 중단",
        }
        (RESULTS_DIR / "summary.json").write_text(
            json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
        )
        print("BUILD FAIL: tests/ch7/results/build.log 확인", file=sys.stderr)
        return 2

    log_sections = [
        "과제7 시멘틱 분석기 전체 테스트 로그\n",
        f"시각: {utc_timestamp()}\n",
        f"과제7 TC: {len(cases)}, 과제6 회귀: {len(regression_cases)}\n",
    ]
    case_rows: list[dict[str, Any]] = []
    primary_results: list[dict[str, Any]] = []
    regression_results: list[dict[str, Any]] = []

    for case in cases:
        source = CASES_DIR / case["file"]
        analyzer = run_analyzer(source)
        compiler = run_cc(source, cc_command)
        passed, reasons = evaluate_ch7(case, analyzer)
        comparison = comparison_label(analyzer, compiler)
        actual = (
            f"exit={analyzer['exit']}, warning={'yes' if '--- warning' in analyzer['output'] else 'no'}, "
            f"semantic_ast={'yes' if '=======  semantic tree  ==========' in analyzer['output'] else 'no'}"
        )
        result = {
            "id": case["id"],
            "category": case["category"],
            "kind": case["kind"],
            "purpose": case["purpose"],
            "expected": case["expected"],
            "actual": actual,
            "analyzer_exit": analyzer["exit"],
            "compiler_exit": compiler["exit"],
            "compiler_comparison": comparison,
            "passed": passed,
            "reasons": reasons,
            "timeout": analyzer["timeout"],
            "crash": analyzer["crash"],
        }
        primary_results.append(result)
        case_rows.append(result)
        append_case_log(
            log_sections,
            f"{case['id']} [{case['kind']}/{CATEGORY_LABELS[case['category']]}] {case['purpose']}",
            source,
            analyzer,
            compiler,
            passed,
            reasons,
        )

    for case in regression_cases:
        source = PROJECT_DIR / case["file"]
        analyzer = run_analyzer(source)
        compiler = run_cc(source, cc_command)
        reasons: list[str] = []
        if analyzer["timeout"]:
            reasons.append("타임아웃")
        if analyzer["crash"]:
            reasons.append(f"크래시(signal {-analyzer['exit']})")
        if analyzer["exit"] != case["expected_exit"]:
            reasons.append(
                f"종료 코드 기대 {case['expected_exit']}, 실제 {analyzer['exit']}"
            )
        passed = not reasons
        result = {
            "id": case["id"],
            "file": case["file"],
            "expected_exit": case["expected_exit"],
            "analyzer_exit": analyzer["exit"],
            "compiler_exit": compiler["exit"],
            "compiler_comparison": comparison_label(analyzer, compiler),
            "passed": passed,
            "reasons": reasons,
            "timeout": analyzer["timeout"],
            "crash": analyzer["crash"],
        }
        regression_results.append(result)
        append_case_log(
            log_sections,
            f"{case['id']} [과제6 회귀, expected exit={case['expected_exit']}]",
            source,
            analyzer,
            compiler,
            passed,
            reasons,
        )

    (RESULTS_DIR / "test.log").write_text("".join(log_sections), encoding="utf-8")

    csv_path = RESULTS_DIR / "cases.csv"
    with csv_path.open("w", encoding="utf-8", newline="") as stream:
        fieldnames = [
            "id", "category", "kind", "purpose", "expected", "actual",
            "analyzer_exit", "compiler_exit", "compiler_comparison", "passed",
            "reasons", "timeout", "crash",
        ]
        writer = csv.DictWriter(stream, fieldnames=fieldnames)
        writer.writeheader()
        for row in case_rows:
            csv_row = row.copy()
            csv_row["reasons"] = "; ".join(row["reasons"])
            writer.writerow(csv_row)

    category_summary: dict[str, dict[str, int]] = {}
    for category in EXPECTED_CATEGORY_COUNTS:
        selected = [row for row in primary_results if row["category"] == category]
        category_summary[category] = {
            "total": len(selected),
            "passed": sum(1 for row in selected if row["passed"]),
            "failed": sum(1 for row in selected if not row["passed"]),
        }
    kind_summary: dict[str, dict[str, int]] = {}
    for kind in EXPECTED_KIND_COUNTS:
        selected = [row for row in primary_results if row["kind"] == kind]
        kind_summary[kind] = {
            "total": len(selected),
            "passed": sum(1 for row in selected if row["passed"]),
            "failed": sum(1 for row in selected if not row["passed"]),
        }

    primary_passed = sum(1 for row in primary_results if row["passed"])
    regression_passed = sum(1 for row in regression_results if row["passed"])
    summary = {
        "generated_at": utc_timestamp(),
        "build": "PASS",
        "tests_executed": True,
        "primary": {
            "total": len(primary_results),
            "passed": primary_passed,
            "failed": len(primary_results) - primary_passed,
            "pass_rate": round(primary_passed * 100.0 / len(primary_results), 2),
            "by_category": category_summary,
            "by_kind": kind_summary,
            "compiler_differences": sum(
                1 for row in primary_results if row["compiler_comparison"] == "차이"
            ),
            "timeouts": sum(1 for row in primary_results if row["timeout"]),
            "crashes": sum(1 for row in primary_results if row["crash"]),
            "cases": primary_results,
        },
        "regression": {
            "total": len(regression_results),
            "passed": regression_passed,
            "failed": len(regression_results) - regression_passed,
            "pass_rate": round(regression_passed * 100.0 / len(regression_results), 2),
            "compiler_differences": sum(
                1 for row in regression_results if row["compiler_comparison"] == "차이"
            ),
            "timeouts": sum(1 for row in regression_results if row["timeout"]),
            "crashes": sum(1 for row in regression_results if row["crash"]),
            "cases": regression_results,
        },
    }
    (RESULTS_DIR / "summary.json").write_text(
        json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )

    print("BUILD PASS")
    print(
        f"CH7: {primary_passed}/{len(primary_results)} PASS "
        f"({summary['primary']['pass_rate']:.2f}%)"
    )
    print(
        f"CH6 regression: {regression_passed}/{len(regression_results)} PASS "
        f"({summary['regression']['pass_rate']:.2f}%)"
    )
    print(
        f"timeouts={summary['primary']['timeouts'] + summary['regression']['timeouts']} "
        f"crashes={summary['primary']['crashes'] + summary['regression']['crashes']}"
    )
    return 0 if primary_passed == 40 and regression_passed == 48 else 1


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (KeyError, ValueError, json.JSONDecodeError) as exc:
        print(f"test configuration error: {exc}", file=sys.stderr)
        raise SystemExit(2)
