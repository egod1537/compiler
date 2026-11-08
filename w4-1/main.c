#include "type.h"

extern int syntax_err;

void initialize();
int yyparse();

int main()
{
    initialize();
    yyparse();

    if (syntax_err)
        return(1);

    return(0);
}
