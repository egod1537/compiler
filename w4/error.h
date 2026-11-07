#ifndef COMPILER_ERROR_H
#define COMPILER_ERROR_H

typedef enum {
    LEXICAL_ERROR,
    SYNTAX_ERROR,
    DECLARATION_ERROR,
    INTERNAL_ERROR
} ERROR_CLASS;

const char *error_class_name(ERROR_CLASS error_class);
void report_compiler_error(ERROR_CLASS error_class, int code, int line,
                           const char *format, ...);

#endif
