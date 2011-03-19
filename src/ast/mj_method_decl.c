#include "errors.h"
#include "utils.h"
#include "mj_method_decl.h"

int new_mj_method_decl(ast *return_type, ast *id, ast *arguments,
                       ast *body, ast *return_expression, ast **node)
{
    mj_method_decl *m;

    if(!is_of_type(MJ_TYPE, return_type)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_AST_LIST, arguments)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_METHOD_BODY, body)) {
        return invalid_type(node);
    }

    m = jrv_malloc(sizeof(mj_method_decl));
    m->type = MJ_METHOD_DECL;
    m->return_type = (mj_type *) return_type;
    m->id = (mj_identifier *) id;
    m->arguments = (mj_ast_list *) arguments;
    m->body = (mj_method_body *) body;
    m->return_expression = return_expression;
    *node = (ast *) m;
    return JRV_SUCCESS;
}

void delete_mj_method_decl(mj_method_decl *m)
{
    delete_ast((ast *) m->return_type);
    delete_ast((ast *) m->id);
    delete_ast((ast *) m->arguments);
    delete_ast((ast *) m->body);
    delete_ast(m->return_expression);
    jrv_free(&m);
}
