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
 * Adds a statement to a method body
 *
 * @param[in] statement The statement to add to the method_body
 * @param[in] method_body The method_body to add the statement to
 * @return The result of the function
 */
int mj_method_body_add_statement(ast *statement, ast *method_body);

/**
 * Adds a variable declaration to a method body
 *
 * @param[in] var_decl The variable declaration to add
 * @param[in] method_body The method to add the variable declaration to
 * @return The result of the function
 */
int mj_method_body_add_var_decl(ast *var_decl, ast *method_body);

/**
 * Deletes a mj_method_body struct
 *
 * @param mb The struct to delete
 */
void delete_mj_method_body(mj_method_body *mb);

#endif /* INCLUDE_jrv_mj_method_body_h__ */
