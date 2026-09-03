# w1 C 개발 환경

## LazyVim에서 시작

```powershell
cd C:\Users\egod1\proj\compiler\w1
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
.\build\w1.exe
```

새 소스 파일을 실행 파일에 포함하려면 `CMakeLists.txt`의 `add_executable`에 파일명을
추가합니다. 단일 파일은 CMake 수정 없이 `<Space>rb` 또는 `<Space>rr`로 바로 실행할 수
있습니다.
