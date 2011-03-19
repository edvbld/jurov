#include "utils.h"
#include "errors.h"
#include "mj_main_class.h"

int new_mj_main_class(ast *class_id, ast *parameter_id, ast* statements, 
                      ast **node)
{
    mj_main_class *mc;
   
    if(!is_of_type(MJ_IDENTIFIER, class_id)) {
        return invalid_type(node);
    }
   
    if(!is_of_type(MJ_IDENTIFIER, parameter_id)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, statements)) {
        return invalid_type(node);
    }
    
    mc = jrv_malloc(sizeof(mj_main_class));
    mc->type = MJ_MAIN_CLASS;
    mc->class_id = (mj_identifier *) class_id;
    mc->parameter_id = (mj_identifier *) parameter_id;
    mc->statements = (mj_ast_list *) statements;
    *node = (ast *) mc;
    return JRV_SUCCESS;
}

void delete_mj_main_class(mj_main_class *mc)
{
    delete_ast((ast *) mc->class_id);
    delete_ast((ast *) mc->parameter_id);
    delete_ast((ast *) mc->statements);
    jrv_free(&mc);
}
