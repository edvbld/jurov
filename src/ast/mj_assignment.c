#include "errors.h"
#include "utils.h"
#include "mj_assignment.h"

int new_mj_assignment(ast *id, ast *expression, ast **node)
{
    mj_assignment *a;

    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    a = jrv_malloc(sizeof(mj_assignment));
    a->type = MJ_ASSIGNMENT;
    a->id = (mj_identifier *) id;
    a->expression = expression;
    *node = (ast *) a;
    return JRV_SUCCESS;
}

void delete_mj_assignment(mj_assignment *a)
{
    if(a != NULL) {
        delete_ast((ast *) a->id);
        delete_ast(a->expression);
        jrv_free(&a);
    }
}
