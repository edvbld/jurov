#ifndef INCLUDE_jrv_mj_call_h__
#define INCLUDE_jrv_mj_call_h__

#include "ast.h"
#include "mj_identifier.h"
#include "ast_list.h"

/**
 * Represents a method call in the AST
 */
typedef struct {
    /** The type of the node, this will be nodetype.CALL */
    nodetype type;
    
    /* The expression that evaluates to the object to call the method on */
    ast* object;

    /* The id of the method to invoke */
    mj_identifier *method;

    /* The parameters to the method */
    mj_ast_list *parameters;
} mj_call;

/**
 * Creates a new call node for the AST with the given parameters.
 *
 * @param[in] object The object to call the method on
 * @param[in] method_id The id of the method to call
 * @param[in] parameters The parameters for the method call
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_call(ast *object, ast *method, ast *parameters, ast **node);

/**
 * Deletes a mj_call struct
 *
 * @param call The mj_call struct to delete
 */
void delete_mj_call(mj_call *call);
#endif /* INCLUDE_jrv_mj_call_h__ */
