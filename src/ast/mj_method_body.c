#include "errors.h"
#include "utils.h"
#include "mj_method_body.h"
#include "mj_var_decl.h"

int new_mj_method_body(ast *var_declarations, ast *statements, ast **node)
{
    mj_method_body *b;

    if(!is_of_type(MJ_AST_LIST, var_declarations)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, statements)) {
        return invalid_type(node);
    }

    b = jrv_malloc(sizeof(mj_method_body));
    b->type = MJ_METHOD_BODY;
    b->var_declarations = (mj_ast_list *) var_declarations;
    b->statements = (mj_ast_list *) statements;
    *node = (ast *) b;
    return JRV_SUCCESS;
}

int mj_method_body_add_statement(ast *statement, ast *method_body)
{
    mj_method_body *b;

    if(!is_of_type(MJ_METHOD_BODY, method_body)) {
        return JRV_INVALID_TYPE;
    }
    
    b = (mj_method_body *) method_body;
    mj_ast_list_prepend((ast *) b->statements, statement);
    return JRV_SUCCESS;
}

int mj_method_body_add_var_decl(ast *var_decl, ast *method_body)
{
    mj_method_body *b;

    if(!is_of_type(MJ_METHOD_BODY, method_body)) {
        return JRV_INVALID_TYPE;
    }

    if(!is_of_type(MJ_VAR_DECL, var_decl)) {
        return JRV_INVALID_TYPE;
    }

    b = (mj_method_body *) method_body;
    mj_ast_list_prepend((ast *) b->var_declarations, var_decl);
    return JRV_SUCCESS;
}

void delete_mj_method_body(mj_method_body *mb)
{
    if(mb != NULL) {
        delete_ast((ast *) mb->var_declarations);
        delete_ast((ast *) mb->statements);
        jrv_free(&mb);
    }
}
