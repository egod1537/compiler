
#ifndef PARSER_VALUE_H
#define PARSER_VALUE_H

#include <limits.h>
#include <stdint.h>

#define YYSTYPE_IS_DECLARED 1

#if INTPTR_MAX == LONG_MAX
typedef long YYSTYPE;
#elif INTPTR_MAX == LLONG_MAX
typedef long long YYSTYPE;
#else
#error "No suitable integer type for YYSTYPE"
#endif

_Static_assert(sizeof(YYSTYPE) >= sizeof(void *),
               "YYSTYPE must be able to hold a pointer");

#endif
