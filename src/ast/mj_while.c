#include "errors.h"
#include "utils.h"
#include "mj_while.h"

int new_mj_while(ast *condition, ast *statement, ast **node)
{
    mj_while *w;

    w = jrv_malloc(sizeof(mj_while));
    w->type = MJ_WHILE;
    w->condition = condition;
    w->statement = statement;
    *node = (ast *) w;
    return JRV_SUCCESS;
}

void delete_mj_while(mj_while *w)
{
    if(w != NULL) {
        delete_ast(w->condition);
        delete_ast(w->statement);
        jrv_free(&w);
    }
}
