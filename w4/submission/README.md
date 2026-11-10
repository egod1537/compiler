# 5장 구문분석기 제출 소스

## 파일 구성

- `c.l`, `c.y`: 어휘분석기와 구문분석기
- `type.h`: 부록 A1 자료구조
- `print.c`: 부록 A5 신택스 트리 출력 함수
- `semantic.c`, `semantic.h`: 선언·타입·스코프 처리 함수
- `syntax_tree.c`, `syntax_tree.h`: 신택스 트리 노드 생성 함수
- `error.c`, `error.h`: 오류 분류 및 출력 함수
- `parse_value.h`: 포인터 크기 `YYSTYPE` 선언
- `main.c`: 구문분석기 진입점

## 빌드 및 실행

Bison, Flex, C11 컴파일러가 설치된 Unix/MSYS2 환경에서 실행한다.

```sh
make
./parser < input.c
```

Windows 명령 프롬프트에서는 `parser.cmd`로 빌드할 수도 있다.

생성 파일(`y.tab.c`, `y.tab.h`, `lex.yy.c`), 목적 파일과 실행 파일은 제출
압축 파일에 포함하지 않았다.
