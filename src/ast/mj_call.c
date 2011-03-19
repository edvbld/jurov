#include "utils.h"
#include "errors.h"
#include "mj_call.h"

int new_mj_call(ast *object, ast *method, ast *parameters, ast **node)
{
    mj_call *c;
   
    if(!is_of_type(MJ_IDENTIFIER, method)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, parameters)) {
        return invalid_type(node);
    }

    c = jrv_malloc(sizeof(mj_call));
    c->type = MJ_CALL;
    c->object = object;
    c->method = (mj_identifier *) method;
    c->parameters = (mj_ast_list *) parameters;
    *node = (ast *) c;
    return JRV_SUCCESS;
}

void delete_mj_call(mj_call *call)
{
    delete_ast(call->object);
    delete_ast((ast *) call->method);
    delete_ast((ast *) call->parameters);
    jrv_free(&call);
}
