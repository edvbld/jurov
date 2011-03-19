#ifndef INCLUDE_jrv_mj_method_body_h__
#define INCLUDE_jrv_mj_method_body_h__

#include "ast2.h"
#include "ast_list.h"

/**
 * Reperesents a method body in MJ
 */
typedef struct {
    /** The type of the node */
    nodetype type;

    /** The variable declarations in the method body */
    mj_ast_list *var_declarations;

    /** The statements in the method */
    mj_ast_list *statements;
} mj_method_body;

/**
 * Creates a new method body in the MiniJava language
 *
 * @param[in] var_declarations The variable declarations in the method body
 * @param[in] statements The statements in the method body
 * @param[out] node The address of the pointer that the result will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_method_body(ast *var_declarations, ast *statements, ast **node);

/**
 * Deletes a mj_method_body struct
 *
 * @param mb The struct to delete
 */
void delete_mj_method_body(mj_method_body *mb);

#endif /* INCLUDE_jrv_mj_method_body_h__ */
