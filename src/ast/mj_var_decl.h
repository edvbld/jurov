#ifndef INCLUDE_jrv_mj_var_decl_h__
#define INCLUDE_jrv_mj_var_decl_h__

#include "ast2.h"
#include "mj_type.h"
#include "mj_identifier.h"

/**
 * Represents a variable declaration in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_VAR_DECL) */
    nodetype type;

    /** The MiniJava type of the variable */
    mj_type *mj_type;

    /** The identifier of the variable */
    mj_identifier *id;
} mj_var_decl;

/**
 * Creates a new variable declaration in the MiniJava language
 *
 * @param[in] type The type of the variable
 * @param[in] id The identifier of the variable
 * @param[out] node The address of the pointer that the created node 
 *                  will be assigned to
 * @return The result of the function
 */
int new_mj_var_decl(ast *type, ast *id, ast **node);

/**
 * Deletes a mj_var_decl struct
 *
 * @param vd The struct to delete
 */
void delete_mj_var_decl(mj_var_decl *vd);

#endif /* INCLUDE_jrv_mj_var_decl_h__ */
