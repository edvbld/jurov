#include "utils.h"
#include "errors.h"
#include "mj_new_object.h"

int new_mj_new_object(ast *class_id, ast **node)
{
    mj_new_object *no;
   
    if(!is_of_type(MJ_IDENTIFIER, class_id)) {
        return invalid_type(node);
    }

    no = jrv_malloc(sizeof(mj_new_object));
    no->type = MJ_NEW_OBJECT;
    no->class_id = (mj_identifier *) class_id;
    *node = (ast *) no;
    return JRV_SUCCESS;
}

void delete_mj_new_object(mj_new_object *no)
{
    delete_ast((ast *) no->class_id);
    jrv_free(&no);
}
