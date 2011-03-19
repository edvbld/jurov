#ifndef INCLUDE_jrv_mj_method_decl_h__
#define INCLUDE_jrv_mj_method_decl_h__

#include "ast.h"
#include "mj_identifier.h"
#include "mj_type.h"
#include "ast_list.h"
#include "mj_method_body.h"

/**
 * Represents a method declaration and definition in the MJ language
 */
typedef struct {
    /** The type of the node (MJ_METHOD_DECL) */
    nodetype type;

    /** The return type of the method */
    mj_type *return_type;

    /** The identifier (name) of the method */
    mj_identifier *id;
    
    /** The argument list */
    mj_ast_list *arguments;

    /** The body of the method */
    mj_method_body *body;

    /** The expression yielding the return value */
    ast *return_expression;
} mj_method_decl;

/**
 * Creates a new method declaration in MJ
 *
 * @param[in] return_type The MJ type the method returns
 * @param[in] id The identifier (name) of the method
 * @param[in] arguments A list of the arguments to the method
 * @param[in] var_declarations A list of the variable declaration in the 
 *                             method body
 * @param[in] statements A list of the statements in the method body
 * @param[in] return_expression The expression yielding the return value
 * @param[out] node The address of the pointer the created node will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_method_decl(ast *return_type, ast *id, ast *arguments,
                       ast *body, ast *return_expression, ast **node);

/**
 * Deletes a mj_method_decl struct
 *
 * @param m The struct to delete
 */
void delete_mj_method_decl(mj_method_decl *m);

#endif /* INCLUDE_jrv_mj_method_decl_h__ */
