#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <io.h>
#define ISATTY _isatty
#define FILENO _fileno
#else
#include <unistd.h>
#define ISATTY isatty
#define FILENO fileno
#endif

/* 타입 테이블 생성, T_KIND 설정 및 초기 필드 값 검증 */
void SEM_01_MakeType(void);
/* 식별자 생성, 이름 저장 및 심볼 테이블 prev 연결 검증 */
void SEM_02_MakeIdentifier(void);
/* 식별자 검색, 스코프 내 이름 가림 및 중복 검색 검증 */
void SEM_03_SearchIdentifier(void);
/* 스코프 진입/종료에 따른 레벨과 검색 가능 식별자 변경 검증 */
void SEM_04_Scope(void);
/* 선언자 link 목록 연결 및 prev 심볼 테이블 체인 보존 검증 */
void SEM_05_LinkDeclaratorList(void);
/* 포인터/배열 타입 체인 끝에 원소 타입 연결 검증 */
void SEM_06_SetTypeElementType(void);
/* 선언자의 타입 설정, 중첩 타입 연결 및 NULL 처리 검증 */
void SEM_07_SetDeclaratorElementType(void);
/* 배열 크기 수식 연결 및 크기 생략 배열 처리 검증 */
void SEM_08_SetTypeExpr(void);
/* 구조체 필드와 함수 매개변수 목록의 타입 테이블 연결 검증 */
void SEM_09_SetTypeField(void);
/* 타입과 저장 클래스를 결합한 선언 지정자 생성 검증 */
void SEM_10_MakeSpecifier(void);
/* 기존 선언 지정자에 타입 또는 저장 클래스 정보 추가 검증 */
void SEM_11_UpdateSpecifier(void);
/* 타입 생략 시 기본 int 타입 설정 및 기존 타입 유지 검증 */
void SEM_12_SetDefaultSpecifier(void);
/* 기본 타입, 내장 함수 및 전역 식별자 초기화 검증 */
void SEM_13_Initialize(void);
/* 일반 선언의 최종 타입, 종류, 저장 클래스 및 스코프 처리 검증 */
void SEM_14_SetDeclaratorListSpecifier(void);
/* 함수 프로토타입, 함수 정의 및 매개변수 타입 연결 검증 */
void SEM_15_SetFunctionDeclaratorSpecifier(void);
/* 함수 본문 AST 연결, 함수 종류 및 타입 유지 검증 */
void SEM_16_SetFunctionDeclaratorBody(void);
/* 매개변수 타입, 포인터, 익명 void, 스코프 및 목록 연결 검증 */
void SEM_17_SetParameterDeclaratorSpecifier(void);

typedef void (*SemTestFunction)(void);

typedef struct {
  const char *function_name;
  const char *name;
  SemTestFunction function;
} SemTest;

static const SemTest tests[] = {
    {"SEM_01_MakeType", "make type", SEM_01_MakeType},
    {"SEM_02_MakeIdentifier", "make identifier", SEM_02_MakeIdentifier},
    {"SEM_03_SearchIdentifier", "search identifier", SEM_03_SearchIdentifier},
    {"SEM_04_Scope", "scope", SEM_04_Scope},
    {"SEM_05_LinkDeclaratorList", "link declarator list", SEM_05_LinkDeclaratorList},
    {"SEM_06_SetTypeElementType", "set type element type", SEM_06_SetTypeElementType},
    {"SEM_07_SetDeclaratorElementType", "set declarator element type",
     SEM_07_SetDeclaratorElementType},
    {"SEM_08_SetTypeExpr", "set type expression", SEM_08_SetTypeExpr},
    {"SEM_09_SetTypeField", "set type field", SEM_09_SetTypeField},
    {"SEM_10_MakeSpecifier", "make specifier", SEM_10_MakeSpecifier},
    {"SEM_11_UpdateSpecifier", "update specifier", SEM_11_UpdateSpecifier},
    {"SEM_12_SetDefaultSpecifier", "set default specifier",
     SEM_12_SetDefaultSpecifier},
    {"SEM_13_Initialize", "initialize", SEM_13_Initialize},
    {"SEM_14_SetDeclaratorListSpecifier", "set declarator list specifier",
     SEM_14_SetDeclaratorListSpecifier},
    {"SEM_15_SetFunctionDeclaratorSpecifier", "set function declarator specifier",
     SEM_15_SetFunctionDeclaratorSpecifier},
    {"SEM_16_SetFunctionDeclaratorBody", "set function declarator body",
     SEM_16_SetFunctionDeclaratorBody},
    {"SEM_17_SetParameterDeclaratorSpecifier", "set parameter declarator specifier",
     SEM_17_SetParameterDeclaratorSpecifier},
};

static const char *green = "";
static const char *cyan = "";
static const char *red = "";
static const char *bold = "";
static const char *reset = "";

static void initializeColors(void) {
  int use_color = ISATTY(FILENO(stdout));

  if (getenv("NO_COLOR") != NULL)
    use_color = 0;
  else if (getenv("FORCE_COLOR") != NULL)
    use_color = 1;

  if (!use_color)
    return;

  green = "\x1b[32m";
  cyan = "\x1b[36m";
  red = "\x1b[31m";
  bold = "\x1b[1m";
  reset = "\x1b[0m";
}

static void printTestList(void) {
  size_t count = sizeof(tests) / sizeof(tests[0]);

  for (size_t i = 0; i < count; i++)
    printf("%s[SEM:%02zu]%s %-40s %s\n", cyan, i + 1, reset,
           tests[i].function_name, tests[i].name);
}

int main(int argc, char **argv) {
  size_t count = sizeof(tests) / sizeof(tests[0]);
  long selected = 0;

  initializeColors();

  if (argc > 2) {
    fprintf(stderr, "%sERROR%s [SEM] Usage: %s [test-number|list]\n", red,
            reset, argv[0]);
    return 2;
  }

  if (argc == 2) {
    if (strcmp(argv[1], "list") == 0) {
      printTestList();
      return 0;
    }

    char *end = NULL;
    selected = strtol(argv[1], &end, 10);

    if (argv[1][0] == '\0' || end == NULL || *end != '\0' || selected < 1 ||
        selected > (long)count) {
      fprintf(stderr,
              "%sERROR%s [SEM] Invalid test number: %s (valid: 1-%zu)\n",
              red, reset, argv[1], count);
      return 2;
    }
  }

  if (selected != 0) {
    size_t index = (size_t)(selected - 1);
    tests[index].function();
    printf("%sPASS%s %s[SEM:%02ld]%s %-40s %s\n", green, reset, cyan,
           selected, reset, tests[index].function_name, tests[index].name);
    printf("\n%sSUMMARY%s %s[SEM]%s %s1 passed%s, 0 failed, 1 total\n",
           bold, reset, cyan, reset, green, reset);
    return 0;
  }

  for (size_t i = 0; i < count; i++) {
    tests[i].function();
    printf("%sPASS%s %s[SEM:%02zu]%s %-40s %s\n", green, reset, cyan,
           i + 1, reset, tests[i].function_name, tests[i].name);
  }

  printf("\n%sSUMMARY%s %s[SEM]%s %s%zu passed%s, 0 failed, %zu total\n",
         bold, reset, cyan, reset, green, count, reset, count);
  return 0;
}

