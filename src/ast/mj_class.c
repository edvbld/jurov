#include "utils.h"
#include "errors.h"
#include "mj_class.h"

int new_mj_class(ast *id, ast *var_declarations,
                 ast *method_declarations, ast **node)
{
    mj_class *mc;

    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, var_declarations)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, method_declarations)) {
        return invalid_type(node);
    }
    
    mc = jrv_malloc(sizeof(mj_class));
    mc->type = MJ_CLASS;
    mc->id = (mj_identifier *) id;
    mc->var_declarations = (mj_ast_list *) var_declarations;
    mc->method_declarations = (mj_ast_list *) method_declarations;
    *node = (ast *) mc;
    return JRV_SUCCESS;
}

void delete_mj_class(mj_class *c)
{
    delete_ast((ast *) c->id);
    delete_ast((ast *) c->var_declarations);
    delete_ast((ast *) c->method_declarations);
    jrv_free(&c);
}
