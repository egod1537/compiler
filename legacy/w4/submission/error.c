#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"

const char *error_class_name(ERROR_CLASS error_class)
{
    switch (error_class) {
    case LEXICAL_ERROR:
        return "LEXICAL_ERROR";
    case SYNTAX_ERROR:
        return "SYNTAX_ERROR";
    case DECLARATION_ERROR:
        return "DECLARATION_ERROR";
    case INTERNAL_ERROR:
        return "INTERNAL_ERROR";
    default:
        return "INTERNAL_ERROR";
    }
}

int compiler_error_tags_enabled(void)
{
    const char *value = getenv("COMPILER_ERROR_TAGS");
    return value != NULL && value[0] != '\0' && strcmp(value, "0") != 0;
}

/* 분류와 강의 오류 번호를 메시지 본문과 분리해 출력한다. */
void report_compiler_error(ERROR_CLASS error_class, int code, int line,
                           const char *format, ...)
{
    va_list arguments;

    if (code > 0)
        fprintf(stderr, "[%s:%d] line %d: ",
                error_class_name(error_class), code, line);
    else
        fprintf(stderr, "[%s] line %d: ",
                error_class_name(error_class), line);

    va_start(arguments, format);
    vfprintf(stderr, format, arguments);
    va_end(arguments);
    fputc('\n', stderr);
    fflush(stderr);
}
