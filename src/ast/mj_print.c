#include "errors.h"
#include "utils.h"
#include "mj_print.h"

int new_mj_print(ast* expression, ast **node)
{
    mj_print *p = jrv_malloc(sizeof(mj_print));
    p->type = MJ_PRINT;
    p->expression = expression;
    *node = (ast *) p;
    return JRV_SUCCESS;
}

void delete_mj_print(mj_print *p)
{
    delete_ast((ast *) p->expression);
    jrv_free(&p);
}
