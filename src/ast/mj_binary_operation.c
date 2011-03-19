#include "utils.h"
#include "errors.h"
#include "mj_binary_operation.h"

int new_mj_binary_operation(nodetype type, ast *left_operand, 
                            ast *right_operand, ast **node)
{
    mj_binary_operation *op = jrv_malloc(sizeof(mj_binary_operation));
    op->type = type;
    op->left_operand = left_operand;
    op->right_operand = right_operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

void delete_mj_binary_operation(mj_binary_operation *op)
{
    delete_ast(op->left_operand);
    delete_ast(op->right_operand);
    jrv_free(&op);
}
