# 과제7 시멘틱 분석기 테스트 결과

## 1. 실행 개요

- 기준 커밋: `41f955b` (`w7`)
- 실행일: 2026-11-28 (KST)
- 환경: macOS arm64, Apple Clang 17.0.0, Python 3.15.2, Bison 2.3, Flex 2.6.4
- 실행 명령: `make clean`, `make test`
- 빌드 순서: 명시적 `make clean` 후 테스트 러너의 `make clean`, `make`
- 비교 컴파일러: `cc -std=c11 -Wall -Wextra -pedantic -fsyntax-only`
- 분석기 타임아웃: TC당 5초

빌드는 성공했다. 기존 소스에서 발생하는 컴파일러 경고는 로그에 보존했으며 테스트를
위해 구현 코드를 변경하지 않았다. 전체 원시 빌드 출력은
[`results/build.log`](results/build.log), 99개 입력의 분석기·일반 C 컴파일러 출력은
[`results/test.log`](results/test.log)에 있다. 자동 판정 원본은
[`results/summary.json`](results/summary.json), 과제7 TC별 표의 CSV 원본은
[`results/cases.csv`](results/cases.csv)이다.

## 2. 테스트 구성

과제7 전용 TC는 정상 24개, 오류 19개, 경고 8개로 구성했다. 각 TC의 목적과
기대 결과는 [`manifest.json`](manifest.json)에 고정되어 있으며 러너는 이를 실행
결과에 맞춰 변경하지 않는다. 기존 `tests/1`~`tests/5`의 과제6 입력 48개도 원본
그대로 회귀 실행했다.

| 기능 분류 | 전체 | 성공 | 실패 |
|---|---:|---:|---:|
| 변수 선언 및 초기화 | 7 | 7 | 0 |
| 배열 및 포인터 | 13 | 13 | 0 |
| 구조체·공용체·enum | 6 | 6 | 0 |
| 수식 및 형변환 | 7 | 7 | 0 |
| 함수 | 6 | 6 | 0 |
| 명령문 | 9 | 7 | 2 |
| 리터럴 테이블 | 3 | 3 | 0 |
| 과제7 합계 | 51 | 49 | 2 |

| 기대 결과 종류 | 전체 | 성공 | 실패 |
|---|---:|---:|---:|
| 정상 | 24 | 24 | 0 |
| 오류 | 19 | 17 | 2 |
| 경고 | 8 | 8 | 0 |

| 실행군 | 전체 | 성공 | 실패 | 통과율 |
|---|---:|---:|---:|---:|
| 과제7 전용 | 51 | 49 | 2 | 96.08% |
| 과제6 회귀 | 48 | 47 | 1 | 97.92% |
| 전체 | 99 | 96 | 3 | 96.97% |

크래시와 타임아웃은 두 실행군 모두 0건이다. Runner 기준 실패 3건은
TC48, TC49, CH6-5-10이며 모두 의도적으로 유지한 제한 사항이다. 러너는 이를
실패로 숨기지 않으므로 `make test`는 비정상 종료한다(`run.py` 1, `make` 2).
기대값과 컴파일러 구현 코드는 수정하지 않았다.

## 3. 과제7 TC별 결과

`실제` 열의 `AST`는 시멘틱 AST 출력 여부다. C 컴파일러 열은 종료 코드와 분석기
수락/거부 판정의 일치 여부를 나타낸다.

| TC | 분류 | 기대 | 실제 | C 컴파일러 | 결과 |
|---|---|---|---|---|---|
| TC01 | 변수 | 정상, int 초기화와 ADDR=12 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC02 | 변수 | 정상, 다중 초기화와 ADDR=16 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC03 | 변수 | 정상, 전역·지역 초기화 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC04 | 변수 | 미선언 식별자 오류 | exit 1, 지정 진단 있음 | 1 / 일치 | PASS |
| TC05 | 변수 | 스칼라 과다 초기값 오류 | exit 1, 오류 88 | 0 / 차이 | PASS |
| TC06 | 변수 | float→int 초기화 경고 | exit 0, 경고 11, cast AST | 0 / 일치 | PASS |
| TC07 | 배열 | 정상, 크기 3 초기화 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC08 | 배열 | 정상, 빈 크기를 3으로 추론 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC09 | 포인터 | 정상, 주소·역참조 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC10 | 배열 | 0 크기 오류 | exit 1, 오류 82·86 | 0 / 차이 | PASS |
| TC11 | 배열 | 과다 배열 초기값 오류 | exit 1, 오류 87 | 0 / 차이 | PASS |
| TC12 | 포인터 | float→pointer 대입 오류 | exit 1, 오류 58 | 1 / 일치 | PASS |
| TC13 | 구조체 | 정상, 필드 타입·주소 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC14 | 공용체 | 정상, 공용 필드 주소 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC15 | enum | 정상, A=4·B=5 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC16 | 구조체 | 없는 필드 오류 | exit 1, 오류 37 | 1 / 일치 | PASS |
| TC17 | enum | 실수 열거값 오류 | exit 1, 오류 81 | 1 / 일치 | PASS |
| TC18 | 수식 | 정상, 산술 우선순위 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC19 | 수식 | 정상, 좌·우 시프트 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC20 | 수식 | 정상, 콤마 타입 전파 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC21 | 형변환 | 정상, 명시적 float→int | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC22 | 수식 | float 시프트 오류 | exit 1, 오류 29 | 1 / 일치 | PASS |
| TC23 | 수식 | float 나머지 오류 | exit 1, 오류 29 | 1 / 일치 | PASS |
| TC24 | 수식 | 혼합 산술 경고 | exit 0, 경고 14, cast AST | 0 / 일치 | PASS |
| TC25 | 함수 | 정상, 고정 인자 2개 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC26 | 함수 | 정상, 배열 인자 decay | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC27 | 함수 | 정상, 포인터 반환 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC28 | 함수 | 인자 과다 오류 | exit 1, 오류 34 | 1 / 일치 | PASS |
| TC29 | 함수 | 인자 부족 오류 | exit 1, 오류 35 | 1 / 일치 | PASS |
| TC30 | 함수 | float→int 인자 경고 | exit 0, 경고 12, cast AST | 0 / 일치 | PASS |
| TC31 | 명령문 | 정상, 중첩 switch 문맥 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC32 | 명령문 | 정상, break·continue 문맥 | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC33 | 명령문 | 정상, void return | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC34 | 명령문 | switch 밖 case 오류 | exit 1, 오류 71 | 1 / 일치 | PASS |
| TC35 | 명령문 | loop 밖 continue 오류 | exit 1, 오류 74 | 1 / 일치 | PASS |
| TC36 | 명령문 | void 값 반환 오류 | exit 1, 오류 75 | 1 / 일치 | PASS |
| TC37 | 명령문 | float 조건 경고 | exit 0, 경고 16, cast AST | 0 / 일치 | PASS |
| TC38 | 리터럴 | 정상, float·string·char | exit 0, 경고 없음, AST 있음 | 0 / 일치 | PASS |
| TC39 | 리터럴 | 문자열 간 덧셈 오류 | exit 1, 오류 24 | 1 / 일치 | PASS |
| TC40 | 리터럴 | float 반환 경고 | exit 0, 경고 12, cast AST | 0 / 일치 | PASS |
| TC41 | 배열 | 중첩 배열 크기 추론 | exit 0, AST 있음 | 0 / 일치 | PASS |
| TC42 | 배열 | 중첩 float 초기화 | exit 0, 경고 11, cast·리터럴 AST | 0 / 일치 | PASS |
| TC43 | 배열 | 중괄호 생략 초기화 | exit 0, 경고 11 2건, AST 있음 | 0 / 일치 | PASS |
| TC44 | 배열 | 내측 배열 과다 초기값 | exit 1, 오류 87 | 0 / 차이 | PASS |
| TC45 | 배열 | 대입식 배열 decay | exit 0, cast AST | 0 / 일치 | PASS |
| TC46 | 배열 | 포인터 덧셈의 배열 decay | exit 0, ADD·cast AST | 0 / 일치 | PASS |
| TC47 | 포인터 | 포인터 뺄셈의 int 결과 | exit 0, SUB·int AST | 0 / 일치 | PASS |
| TC48 | 명령문 | 중복 case | exit 0, 진단 없음 | 1 / 차이 | FAIL (의도적 제한) |
| TC49 | 명령문 | 중복 default | exit 0, 진단 없음 | 1 / 차이 | FAIL (의도적 제한) |
| TC50 | 변수 | 전역 비상수 초기화 | exit 1, 오류 92 | 1 / 일치 | PASS |
| TC51 | 구조체 | 필드 float→int 초기화 | exit 0, 경고 11, cast·리터럴 AST | 0 / 일치 | PASS |

## 4. 대표 사례 상세 분석

### TC01 — 지역 변수 초기화와 주소

`int a = 10`은 시멘틱 AST에서 `AUTO`, `(int)`, `N_INIT_LIST_ONE`, `ADDR=12`로
출력됐다. 지역 주소는 [`semantic.c`의 `sem_declaration()`](../../semantic.c#L696)에서
전달받은 프레임 주소를 사용하고 4바이트 정렬한다. 타입, 초기화 트리, 주소를 함께
검증한 정상 사례다.

### TC08 — 초기값을 이용한 배열 크기 추론

`int a[] = {4, 5, 6}`은 `ARRAY`, `INT=3`으로 출력됐다. 빈 배열이고 스칼라 원소
초기화 목록인 경우 원소 수를 세어 크기 표현식을 만드는
[`semantic.c:702`](../../semantic.c#L702) 경로가 동작했다. 명시 크기 배열과 과다
초기값은 TC07·TC11에서 별도로 검증했다.

### TC15 — enum 상수식의 시프트

`A = 1 << 2`는 4, 다음 열거자 `B`는 5로 저장됐다. 시프트의 피연산자 타입 검사는
[`semantic.c:282`](../../semantic.c#L282), enum 값 계산과 증가는
[`semantic.c:618`](../../semantic.c#L618)에서 수행된다. 정수 포인터 필드 변환 이후에도
두 값이 손상되지 않았다.

### TC20 — 콤마 표현식

`(1, 2, 3)`의 시멘틱 AST에 `N_EXP_COMMA`가 유지되고 대입이 성공했다.
[`semantic.c:376`](../../semantic.c#L376)는 왼쪽을 분석한 뒤 오른쪽 표현식의 타입을
전체 결과로 사용한다. 과거 콤마 노드 누락 회귀를 직접 확인하는 사례다.

### TC26 — 배열 인자의 포인터 변환

`first(values)` 호출에서 배열 인자가 포인터로 decay되어 고정 매개변수 검사에
통과했다. 배열·함수·문자에 대한 unary conversion은
[`semantic.c:927`](../../semantic.c#L927), 변환 뒤 고정 인자 검사는
[`semantic.c:405`](../../semantic.c#L405)에 있다. `node->llink->type` NULL 방어가 있는
인자 크기 계산도 같은 경로에서 실행됐다.

### TC30 — 함수 인자의 대입 호환 변환

`take(2.5)`는 오류 59가 아니라 경고 12와 `N_EXP_CAST`를 만들고 정상 종료했다.
고정 매개변수 검사에서 대입 호환성을 적용하고 필요한 경우 기존 cast 변환을 넣는
동작을 검증했다. 일반 C 컴파일러도 입력을 수락했다.

### TC31 — 중첩 제어문의 switch 문맥

`switch`의 `case` 안에 `if`와 `while`을 중첩해도 오류 71이 발생하지 않았다.
[`semantic.c:452`](../../semantic.c#L452)부터 `if`, `if-else`, `while`, `do`, `for`의
재귀 호출이 `sw` 상태를 전달하며, `switch` 진입만 `TRUE`로 초기화한다. 최근 문맥
전파 수정의 핵심 회귀 사례다.

### TC38 — 리터럴 테이블

float `1.25`, string `"abc"`, char `65`가 각각 `LITERAL: 1.250000`,
`LITERAL: "abc"`, `INT=65`로 출력됐다. 리터럴 등록과 4바이트 정렬은
[`semantic.c:86`](../../semantic.c#L86), 인덱스를 이용한 출력은
[`print_sem.c:79`](../../print_sem.c#L79)와
[`print_sem.c:262`](../../print_sem.c#L262)에서 확인된다.

### TC41~47, TC50~51 — 추가 기능 확인

- TC41~43은 중첩 배열의 외측 크기 추론, 재귀 초기화, 중괄호 생략 초기화를
  확인했다. [`sem_declaration()`](../../semantic.c#L696)과
  [`sem_initializer()`](../../semantic.c#L786) 경로에서 크기·cast·리터럴이 정상 저장됐다.
- TC45~46은 대입과 덧셈에서 배열이 포인터로 decay되는지 확인했다.
  대입 변환은 [`semantic.c:380`](../../semantic.c#L380), 덧셈 변환은
  [`semantic.c:292`](../../semantic.c#L292)에서 수행됐다.
- TC47은 호환 포인터 뺄셈의 결과 타입이 `int`임을 확인했다.
- TC50은 전역 비상수 초기화를 분석기와 Clang이 모두 거부하는지 확인했다.
- TC51은 구조체 필드의 float→int 변환이 경고 11과 cast AST를 남기는지 확인했다.

### TC48·49 — 중복 switch 레이블 제한

Clang은 중복 `case` 값과 두 번째 `default`를 각각 오류로 거부했다. 분석기는 두 입력을
수락하고 시멘틱 AST를 출력했다. [`sem_statement()`](../../semantic.c#L452)는
`case/default`가 switch 내부인지만 `sw` 플래그로 검사하며, switch별 case 값 집합과
default 출현 횟수를 저장하지 않는다. 교수님 코드 구조 보존을 위해 의도적 제한으로
유지했으며 기대값을 바꾸지 않아 runner에서 FAIL로 남는다.

### CH6-5-10 — 불완전 구조체 포인터 제한

`struct Node; struct Node *ptr;`는 표준 C에서 유효하고 Clang도 수락하지만, 분석기는
`incomplete forward reference for identifier Node`로 종료했다.
[`checkForwardReference()`](../../support.c#L126)이 포인터로만 사용된 불완전 구조체와
완전한 객체가 필요한 사용을 구분하지 않는다. 교수님 원본의 검사 방식을 유지한
의도적 제한으로 분류하며, 기대값을 정상 수락으로 그대로 두어 회귀 실패로 남겼다.

## 5. 일반 C 컴파일러와의 차이

과제7 TC의 수락/거부 차이는 6건이다.

- **TC05, TC11, TC44:** Clang은 과다 초기값을 경고로 진단하고 종료 코드 0을 반환했다.
  분석기는 교재 오류 88·87로 처리한다. 컴파일러의 계속 처리와 과제 분석기의
  즉시 오류 정책 차이다.
- **TC10:** 길이 0 배열은 표준 C11 기능이 아니지만 Clang이 확장으로 수락하고 경고만 냈다.
- **TC48, TC49:** Clang은 중복 switch 레이블을 거부하지만 분석기는 중복 상태를
  저장하지 않아 수락했다. 의도적으로 유지한 제한이다.

과제6 회귀의 수락/거부 차이는 3건이다.

- **CH6-5-4, CH6-5-6:** 불완전 enum 선언을 분석기는 거부하지만 Clang은 확장으로 수락했다.
  기존 회귀 기대값이 오류이므로 두 TC는 PASS다.
- **CH6-5-10:** 불완전 구조체 포인터 제한으로 분석기는 거부하고 Clang은 수락했다.

## 6. 결론

기준 커밋 `41f955b`에서 빌드, 크래시, 타임아웃 관련 예상 밖 실패는 없었다.
과제7 51개 중 49개, 과제6 회귀 48개 중 47개가 runner 기준을 통과했다. 남은
TC48, TC49, CH6-5-10은 교수님 코드 구조를 보존하기 위해 의도적으로 유지한 제한으로
별도 분류했다. 기존 기대값과 컴파일러 구현은 변경하지 않았다.
