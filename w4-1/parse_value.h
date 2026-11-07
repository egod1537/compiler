#ifndef PARSE_VALUE_H
#define PARSE_VALUE_H

#include <limits.h>
#include <stdint.h>

/*
 * The photographed code stores both integers and pointers in yacc's semantic
 * value.  intptr_t preserves that representation on 32-bit and 64-bit hosts.
 */
#define YYSTYPE_IS_DECLARED 1

#if INTPTR_MAX == LONG_MAX
typedef long YYSTYPE;
#elif INTPTR_MAX == LLONG_MAX
typedef long long YYSTYPE;
#else
#error "No suitable integer type for YYSTYPE"
#endif

#define YY_TO_PTR(type, value) ((type *)(intptr_t)(value))
#define YY_FROM_PTR(value) ((intptr_t)(value))
#define YY(value) ((YYSTYPE)(intptr_t)(value))
#define PTR(type, value) ((type *)(intptr_t)(value))

_Static_assert(sizeof(YYSTYPE) >= sizeof(void *),
               "YYSTYPE must be able to hold a pointer");

#endif
