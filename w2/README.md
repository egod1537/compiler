# w2 LR 수식 계산기

## LazyVim에서 시작

```powershell
cd C:\Users\egod1\proj\compiler\w2
nvim .
```

`main.c`를 연 뒤 다음 키를 사용할 수 있습니다.

- `<Space>rb`: 현재 C 파일을 GCC(C17)로 빌드
- `<Space>rr`: 현재 C 파일을 빌드하고 실행
- `<Space>cf`: clang-format으로 포맷
- `gd`: 정의로 이동
- `K`: 심볼 설명 보기
- `<Space>ca`: 코드 액션

## CMake로 빌드

```powershell
cmake --preset default
cmake --build --preset default
.\build-w2\w2.exe
```

전체 테스트 케이스를 채점하려면 프로젝트 루트에서 grader를 실행합니다.

```powershell
.\build-w2\grader.exe
```

grader는 `main.c`를 다시 컴파일한 뒤 `tc` 폴더의 모든 입력과 출력을 비교합니다.

- `이름.in`: 표준 입력
- `이름.out`: 기대하는 표준 출력
- `이름.exit`: 기대하는 종료 코드(선택 사항이며, 없으면 `0`)

현재 테스트는 정상 수식 40개와 오류 수식 45개로 구성되어 있습니다. 정상
수식은 정수, 연산자 우선순위, 괄호, 공백, 긴 연산 사슬과 `int` 범위의
경계값을 검사합니다. 오류 수식은 잘못된 연산자 배치, 괄호, 암시적 곱셈,
지원하지 않는 문자와 숫자 표기를 검사합니다.

새 소스 파일을 실행 파일에 포함하려면 `CMakeLists.txt`의 `add_executable`에 파일명을
추가합니다. 단일 파일은 CMake 수정 없이 `<Space>rb` 또는 `<Space>rr`로 바로 실행할 수
있습니다.
