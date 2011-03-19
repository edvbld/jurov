#include "errors.h"
#include "utils.h"
#include "mj_method_arg.h"

int new_mj_method_arg(ast *type, ast *id, ast **node)
{
    mj_method_arg *a;

    if(!is_of_type(MJ_TYPE, type)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    a = jrv_malloc(sizeof(mj_method_arg));
    a->type = MJ_METHOD_ARG;
    a->mj_type = (mj_type *) type;
    a->id = (mj_identifier *) id;
    *node = (ast *) a;
    return JRV_SUCCESS;
}

void delete_mj_method_arg(mj_method_arg *m)
{
    if(m != NULL) {
        delete_ast((ast *) m->mj_type);
        delete_ast((ast *) m->id);
        jrv_free(&m);
    }
}
