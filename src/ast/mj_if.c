#include "utils.h"
#include "errors.h"
#include "mj_if.h"

int new_mj_if(ast *condition, ast *true_statement, ast *false_statement, 
              ast **node)
{
    mj_if *mi;

    mi = jrv_malloc(sizeof(mj_if));
    mi->type = MJ_IF;
    mi->condition = condition;
    mi->true_statement = true_statement;
    mi->false_statement = false_statement;
    *node = (ast *) mi;
    return JRV_SUCCESS;
}

void delete_mj_if(mj_if *i)
{
    delete_ast(i->condition);
    delete_ast(i->true_statement);
    delete_ast(i->false_statement);
    jrv_free(&i);
}
