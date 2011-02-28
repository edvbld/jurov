#include "stddef.h"
#include "parser.h"

int yyparse();
int parse_string(char *str, ast **tree)
{
    int res = 0;
    *tree = NULL;
    yy_scan_string(str);
    res = yyparse(tree);
    return res;
}

void delete_parser(ast *tree)
{
    if(tree != NULL) {
        delete_ast(tree);
    }
    yylex_destroy();
}
