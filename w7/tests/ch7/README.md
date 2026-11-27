# 과제7 시멘틱 분석기 테스트

이 디렉터리는 과제7 전용 40개 테스트와 기존 과제6 입력 48개의 회귀 실행을
담당한다. 과제7 테스트의 목적, 기대 결과, 필수 진단과 AST 확인 항목은
`manifest.json`에 고정되어 있다.

## 구성

| 분류 | 개수 |
|---|---:|
| 변수 선언 및 초기화 (`variables`) | 6 |
| 배열 및 포인터 (`arrays`) | 6 |
| 구조체·공용체·enum (`aggregates`) | 5 |
| 수식 및 형변환 (`expressions`) | 7 |
| 함수 (`functions`) | 6 |
| 명령문 (`statements`) | 7 |
| 리터럴 테이블 (`literals`) | 3 |
| 합계 | 40 |

기대 결과 분포는 정상 20개, 오류 15개, 경고 5개다. `run.py`는 먼저
`make clean`과 `make`를 실행하며 빌드 실패 시 파서를 실행하지 않는다. 이후 각
입력을 과제 파서와 시스템 C 컴파일러(`CC`, 기본값 `cc`)에 전달하고 종료 코드,
진단, 시멘틱 AST 필수 조각, 크래시 및 타임아웃을 기록한다.

```sh
make test
# 또는
python3 tests/ch7/run.py
```

결과 파일은 `results/`에 생성된다.

- `build.log`: clean/build 전체 로그
- `test.log`: 모든 TC와 회귀 테스트의 정규화된 실행 로그
- `summary.json`: 자동 판정 및 비교 결과
- `cases.csv`: TC별 목적·기대·실제·C 컴파일러 결과·성공 여부

`RESULTS.md`는 실제 실행 결과를 바탕으로 작성한 한국어 분석 보고서다.
