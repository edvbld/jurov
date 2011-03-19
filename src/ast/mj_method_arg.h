#ifndef INCLUDE_jrv_mj_method_arg_h__
#define INCLUDE_jrv_mj_method_arg_h__

#include "ast.h"
#include "mj_type.h"
#include "mj_identifier.h"

/**
 * Represents an argument to a method in MiniJava
 */
typedef struct {
    /** The type of the node (MJ_METHOD_ARG) */
    nodetype type;

    /** The type of the argument */
    mj_type *mj_type;

    /** The identifier (name) of the argument */
    mj_identifier *id;
} mj_method_arg;

/**
 * Creates a new method argument in the MiniJava language
 *
 * @param[in] mj_type The MiniJava type of the argument
 * @param[in] id The identifier of the argument
 * @param[out] node The address of the pointer that the newly created 
 *                  mj_method_arg will be assigned to
 * @return The result of the function
 */
int new_mj_method_arg(ast *type, ast *id, ast **node);

/**
 * Deletes a mj_method_arg struct
 *
 * @param m The struct to delete
 */
void delete_mj_method_arg(mj_method_arg *m);

#endif /* INCLUDE_jrv_mj_method_arg_h__ */
