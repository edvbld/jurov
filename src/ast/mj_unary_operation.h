#ifndef INCLUDE_jrv_mj_unary_operation_h__
#define INCLUDE_jrv_mj_unary_operation_h__

#include "ast.h"

/**
 * Represents an unary operation (such as .length, new, not) node in the AST
 */
typedef struct {
    /** The type of the node */
    nodetype type;
    /** The argument to the operation */
    ast *operand;
} mj_unary_operation;

/**
 * Creates a new unary operation with the given type and 
 * operand.
 *
 * @param[in] type The type of the operation
 * @param[in] operand The operand of the expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_unary_operation(nodetype type, ast* operand, ast **node);

/**
 * Deletes an unary operation struct
 *
 * @param op The unary operation to delete
 */
void delete_mj_unary_operation(mj_unary_operation *op);

#endif /* INCLUDE_jrv_mj_unary_operation_h__ */
