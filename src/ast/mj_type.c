#include "errors.h"
#include "utils.h"
#include "mj_type.h"

int new_mj_type(minijava_type type, ast *id, ast **node)
{
    mj_type *t;

    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    t = jrv_malloc(sizeof(mj_type));
    t->type = MJ_TYPE;
    t->mj_type = type;
    if(type == MJ_TYPE_USER_DEFINED) {
        t->id = (mj_identifier *) id;
    } else {
        t->id = NULL;
    }
    *node = (ast *) t;
    return JRV_SUCCESS;
}

void delete_mj_type(mj_type *t)
{
    delete_ast((ast *) t->id);
    jrv_free(&t);
}
