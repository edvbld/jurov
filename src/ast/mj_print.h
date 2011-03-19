#ifndef INCLUDE_jrv_mj_print_h__
#define INCLUDE_jrv_mj_print_h__

#include "ast.h"

/**
 * This struct represents a print statement
 */
typedef struct {
    /** The type of the node (nodetype.PRINT) */
    nodetype type;

    /** The expression that will evaluate to the print argument */
    ast *expression;
} mj_print;

/**
 * Creates a new print node with the given expression.
 *
 * @param[in] expression The expression which result will be printed
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_print(ast* expression, ast **node);

/**
 * Deletes a mj_print struct
 *
 * @param p The mj_print struct to delete
 */
void delete_mj_print(mj_print *p);

#endif /* INCLUDE_jrv_mj_print_h__ */
