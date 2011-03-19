#ifndef INCLUDE_jrv_mj_binary_operation_h__
#define INCLUDE_jrv_mj_binary_operation_h__

#include "ast.h"

/**
 * Represents a binary operation (such as +,-,*,< etc.) node in the AST
 */
typedef struct {
    /** The type of the node */
    nodetype type;
    /** The left operand to the operation */
    ast *left_operand;
    /** The right operand to the operation */
    ast *right_operand;

} mj_binary_operation;

/**
 * Creates a new binary operation with the given type and 
 * operands.
 *
 * @param[in] type The type of the operation
 * @param[in] left_operand The left operand of the expression
 * @param[in] right_operand The right operand of the expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_binary_operation(nodetype type, ast* left_operand, 
                            ast* right_operand, ast **node);

/**
 * Deletes a binary operation
 *
 * @param op The binary operation to delete
 */
void delete_mj_binary_operation(mj_binary_operation *op);

#endif /* INCLUDE_jrv_mj_binary_operation_h__ */
