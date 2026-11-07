# 테스트 결과

검증일: 2026-11-07

## Windows 전체 회귀

`make clean && make && make test` 결과는 총 72개 통과, 0개 실패이다.

| 그룹 | 통과 | 실패 | 검증 내용 |
|---|---:|---:|---|
| CH5 | 15 | 0 | 기본 구문, 제외 문법, LF/CRLF |
| AST | 17 | 0 | 정상/오류 파서 입력 |
| ASTEXP | 7 | 0 | 선택된 기대 AST 입력 |
| SEM | 17 | 0 | 보존된 GPT 의미 도우미 단위 테스트 |
| SEMERR | 16 | 0 | 실제 파서 선언 오류와 오류 분류 |

추가 검증:

- 컴파일 경고 없음
- `parser.cmd` 빌드 성공
- `tests/ch5/run.ps1`: 15개 통과, 0개 실패
- `tests/sem/run.cmd 1`: 개별 실행 성공
- `make test-semerr TEST=1`: 1개 통과, 0개 실패
- 잘못된 SEMERR 번호는 0이 아닌 종료 코드 반환
- 제공된 AST JSON 기대 그래프 7개 모두 현재 출력과 일치

SEMERR에서 확인한 강의자료 오류 코드는 11, 12, 13, 14, 21, 22, 23,
26, 32이다. 정상 스코프 가림, 완성되는 구조체 전방 참조, 일치하는 함수
원형/정의 및 `void` 매개변수 목록에서는 오탐이 없었다. 별도로 Yacc 문법
오류는 `SYNTAX_ERROR`, 잘못된 문자는 `LEXICAL_ERROR`로 확인했다.

## Unix

동일 Makefile과 POSIX Bash 러너를 사용하며 Unix에서는 `YYSTYPE`을 64비트
`long`으로 구성한다. 로컬 WSL Ubuntu에는 GCC, Bison, Flex, Make가 설치되어
있지 않아 이 환경에서 Linux 실빌드는 수행하지 못했다.
