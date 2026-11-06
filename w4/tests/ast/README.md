# AST parser cases

이 디렉터리는 AST/parser 테스트에 필요한 파일을 함께 관리한다.

- `cases/`: 문법 요소별 AST 입력 TC
- `expected/`: 수동 작성 기대 AST와 구조화된 JSON
- `valid/`: 파싱에 성공해야 하는 통합 입력
- `invalid/`: 문법 오류가 발생해야 하는 통합 입력
- `ast.c`: AST 테스트 parser 실행 진입점
- `ast_options.c`: CLI 테스트 모드 처리
- `ast_expression.c`: 표현식 AST 테스트 실행
- `ast_declaration.c`: 선언·타입 AST 테스트 실행
- `ast_statement.c`: 문장·제어 흐름 AST 테스트 실행
- `ast_runner.h`: AST 테스트 실행기 공통 선언
- `ast_assert.c`, `ast_assert.h`: parser에 연결되는 AST assertion 코드
- `run.sh`: `valid/`와 `invalid/`를 실행하는 Unix 테스트 러너
- `check.cmd`, `check.ps1`, `checker.ps1`: 기대 AST 비교 도구
- `checker_tests.ps1`: AST 비교기 자체의 회귀 테스트

`cases/`의 파일은 5장 지원 문법 안에서 각 문법 요소를 독립적으로 파싱하기 위한 입력이다.
`Parsing success`는 문법 인식 성공만 뜻하며, 기대 AST가 만들어졌다는 뜻은 아니다.

현재 `c.y`에는 `INTEGER_CONSTANT`의 `N_EXP_INT_CONST` 생성 액션만 있다. 따라서 01번도
정수 표현식 노드만 부분 구현된 상태이고, `return`, 함수, 선언을 포함한 전체 AST는 아직
구성되지 않는다. 나머지 대상 노드는 Semantic Action이 추가되기 전까지 AST 검증 성공으로
판정하지 않는다.

| 파일 | 검증 대상 | 핵심 표현식 | 기대 AST/타입 구조 | 현재 구현 상태 |
|---|---|---|---|---|
| `01_integer.c` | 정수 상수 | `return 123;` | `N_STMT_RETURN -> N_EXP_INT_CONST(123)` | 부분 구현: `N_EXP_INT_CONST`만 생성, 구문 파싱 성공 |
| `02_add.c` | 덧셈 | `return 1 + 2;` | `N_STMT_RETURN -> N_EXP_ADD(N_EXP_INT_CONST(1), N_EXP_INT_CONST(2))` | AST 미구현, 구문 파싱 성공 |
| `03_precedence.c` | 연산자 우선순위 | `return 1 + 2 * 3;` | `N_EXP_ADD(N_EXP_INT_CONST(1), N_EXP_MUL(N_EXP_INT_CONST(2), N_EXP_INT_CONST(3)))` | AST 미구현, 구문 파싱 성공 |
| `04_parentheses.c` | 괄호 | `return (1 + 2) * 3;` | `N_EXP_MUL(N_EXP_ADD(N_EXP_INT_CONST(1), N_EXP_INT_CONST(2)), N_EXP_INT_CONST(3))` | AST 미구현, 구문 파싱 성공 |
| `05_identifier.c` | 변수 참조 | `int x; return x;` | `N_STMT_RETURN -> N_EXP_IDENT(x)` | AST 미구현, 구문 파싱 성공 |
| `06_assignment.c` | 대입문 | `x = 10; return x;` | `N_STMT_EXPRESSION -> N_EXP_ASSIGN(N_EXP_IDENT(x), N_EXP_INT_CONST(10))` | AST 미구현, 구문 파싱 성공 |
| `07_if_else.c` | 조건문 | `if (x > 0) ... else ...` | `N_STMT_IF_ELSE`, `N_EXP_GTR`, 두 `N_STMT_RETURN` | AST 미구현, 구문 파싱 성공 |
| `08_while.c` | 반복문 | `while (x < 10) x = x + 1;` | `N_STMT_WHILE`, `N_EXP_LSS`, `N_EXP_ASSIGN`, `N_EXP_ADD` | AST 미구현, 구문 파싱 성공 |
| `09_for.c` | for 반복문 | `for (i = 0; i < 10; i++) ...` | `N_STMT_FOR`, `N_FOR_EXP`, `N_EXP_ASSIGN`, `N_EXP_LSS`, `N_EXP_POST_INC` | AST 미구현, 구문 파싱 성공 |
| `10_function_call.c` | 함수 호출 | `return add(1, 2);` | `N_EXP_FUNCTION_CALL`, `N_ARG_LIST`, 인자 정수 노드 | AST 미구현, 구문 파싱 성공 |
| `11_array.c` | 배열 선언 및 참조 | `int a[10]; return a[0];` | 선언 타입 `T_ARRAY`, 참조 `N_EXP_ARRAY(N_EXP_IDENT(a), N_EXP_INT_CONST(0))` | AST/타입 연결 미구현, 구문 파싱 성공 |
| `12_pointer.c` | 포인터 | `int *p; return *p;` | 선언 타입 `T_POINTER`, 역참조 `N_EXP_STAR(N_EXP_IDENT(p))` | AST/타입 연결 미구현, 구문 파싱 성공 |
| `13_struct.c` | 구조체 | `struct Point { int x; int y; } origin;` | `T_STRUCT` 필드 목록과 멤버 참조 `N_EXP_STRUCT` | AST/타입 연결 미구현, 구문 파싱 성공 |

현재 문법의 `declaration`은 선언자 없는 `struct Point { ... };` 형태를 받지 않으므로,
13번은 동일한 구조체 정의에 전역 선언자 `origin`을 붙여 파싱 가능한 형태로 작성했다.

각 파일은 다음처럼 개별 실행한다.

```powershell
.\parser.cmd tests/ast/cases/01_integer.c
```

Unix에서 parser 통합 테스트를 실행한다.

```sh
make test-ast
```

Windows에서 기대 AST를 비교한다.

```powershell
.\tests\ast\check.cmd 24
.\tests\ast\check.cmd --all
```
