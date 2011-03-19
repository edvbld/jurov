#include "utils.h"
#include "errors.h"
#include "mj_unary_operation.h"

int new_mj_unary_operation(nodetype type, ast *operand, ast **node)
{
    mj_unary_operation *op = jrv_malloc(sizeof(mj_unary_operation));
    op->type = type;
    op->operand = operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

void delete_mj_unary_operation(mj_unary_operation *op)
{
    delete_ast(op->operand);
    jrv_free(&op);
}

