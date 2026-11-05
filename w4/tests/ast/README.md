# AST parser cases

이 디렉터리의 파일은 5장 지원 문법 안에서 각 문법 요소를 독립적으로 파싱하기 위한 입력이다.
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
.\parser.cmd tests/ast/01_integer.c
```

## 독립 기대 AST 검증

24, 25, 44, 59번은 `tests/ast_expected.py`에 C 입력을 기준으로 직접 작성한 기대
AST가 있다. `tests/verify_ast.py`는 컴파일러를 `AST_PRINT=1`로 실행하고 출력의 포인터
주소와 서식을 제거한 뒤, 노드 링크, 선언 타입, 식별자와 선언 순서를 비교한다.

`syntax`는 실행할 때마다 현재 `c.l`, `c.y`, `semantic.c`로 파서를 임시 빌드한다.
따라서 저장소에 남아 있는 `parser` 또는 `parser.exe`는 검증에 사용하지 않는다.

개별 테스트와 정규화된 기대/실제 AST, 구조 차이를 확인한다.

```powershell
.\syntax.cmd 24
.\syntax.cmd 24 --show
.\syntax.cmd 24 --diff
```

Unix 계열에서는 동일한 인터페이스를 사용한다.

```bash
./syntax 24
./syntax --all
```

`--all`은 `tests/ast` 전체를 번호순으로 확인한다. 현재 기대 AST가 정의된 24, 25,
44, 59번 외의 입력은 `PASS`가 아니라 `SKIP`으로 표시한다. 불일치는
`N_PROGRAM > add > BODY > RETURN` 형식의 구조 경로와 기대값/실제값으로 출력된다.

## 파싱 단축 명령

`parse`는 기대 AST와 비교하지 않고 현재 컴파일러로 입력을 파싱한다. Windows에서는
기존 `parser.cmd`로 현재 소스를 먼저 빌드하고, Unix 계열에서는 동일한 소스 목록을
임시 디렉터리에서 빌드한다.

```powershell
.\parse.cmd 24
.\parse.cmd 24 --print
.\parse.cmd tests/ast/24_function_prototype.c
.\parse.cmd --all
```

```bash
./parse 24
./parse 24 --print
./parse tests/ast/24_function_prototype.c
./parse --all
```

번호는 `syntax`와 공유하는 검색 코드로 `tests/ast`에서 찾는다. 동일 번호 파일이 여러
개면 후보를 표시하고 번호를 입력받는다. 예를 들어 02번은 `02_add.c`와 `02_sub.c`
중 하나를 선택한다.

| 명령 | 역할 |
|---|---|
| `parse 24` | 현재 컴파일러로 24번 입력 파싱 |
| `parse 24 --print` | 현재 컴파일러의 `print.c` AST 출력 |
| `syntax 24` | 실제 AST와 독립 기대 AST 비교 |
| `syntax 24 --diff` | 모든 구조 불일치 출력 |
| `syntax --all` | 전체 AST 검증 및 미구현 항목 `SKIP` 처리 |
