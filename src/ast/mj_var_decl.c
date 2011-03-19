#include "errors.h"
#include "utils.h"
#include "mj_var_decl.h"

int new_mj_var_decl(ast *type, ast *id, ast **node)
{
    mj_var_decl *d;

    if(!is_of_type(MJ_TYPE, type)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    d = jrv_malloc(sizeof(mj_var_decl));
    d->type = MJ_VAR_DECL;
    d->mj_type = (mj_type *) type;
    d->id = (mj_identifier *) id;
    *node = (ast *) d;
    return JRV_SUCCESS;
}

void delete_mj_var_decl(mj_var_decl *vd)
{
    if(vd != NULL) {
        delete_ast((ast *) vd->mj_type);
        delete_ast((ast *) vd->id);
        jrv_free(&vd);
    }
}
