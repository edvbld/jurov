#include "errors.h"
#include "utils.h"
#include "mj_array_assignment.h"

int new_mj_array_assignment(ast *id, ast *index_exp, ast *value_exp, ast **node)
{
    mj_array_assignment *aa;

    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    aa = jrv_malloc(sizeof(mj_array_assignment));
    aa->type = MJ_ARRAY_ASSIGNMENT;
    aa->id = (mj_identifier *) id;
    aa->index_exp = index_exp;
    aa->value_exp = value_exp;
    *node = (ast *) aa;
    return JRV_SUCCESS;
}

void delete_mj_array_assignment(mj_array_assignment *aa) {
    delete_ast((ast *) aa->id);
    delete_ast(aa->index_exp);
    delete_ast(aa->value_exp);
    jrv_free(&aa);
}
