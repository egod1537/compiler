#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

typedef enum {
    /* 오류 원인을 출력 형식과 테스트에서 안정적으로 구분한다. */
    LEXICAL_ERROR,
    SYNTAX_ERROR,
    DECLARATION_ERROR,
    INTERNAL_ERROR
} ERROR_CLASS;

const char *error_class_name(ERROR_CLASS error_class);
int compiler_error_tags_enabled(void);
void report_compiler_error(ERROR_CLASS error_class, int code, int line,
                           const char *format, ...);

#endif
