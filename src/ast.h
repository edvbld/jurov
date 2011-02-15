#ifndef __AST_H__
#define __AST_H__

struct ast {
    int nodetype;
};

struct ast* result;

void yyerror(char *s)
{
    // do nothing for now
}

#endif // __AST_H__
