#include "support.h"

int yyparse(void);

int main(void)
{
    initialize();
    if (yyparse()!=0 || syntax_err)
        return 1;
    print_ast(root);
    return 0;
}
