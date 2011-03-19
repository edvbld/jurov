#ifndef INCLUDE_jrv_mj_type_h__
#define INCLUDE_jrv_mj_type_h__

#include "ast.h"
#include "mj_identifier.h"

/**
 * Represents a type in the MiniJava language, such as int or boolean
 */
typedef struct {
    /** The type of the node (MJ_TYPE) */
    nodetype type;

    /** The MiniJava type */
    minijava_type mj_type;

    /** The identifier if it's a user defined type */
    mj_identifier *id;
} mj_type;

/**
 * Creates a new type in the MiniJava language
 *
 * @parameter[in] type The type to construct
 * @parameter[in] id The id if it's a user defined type
 * @parameter[out] node The address of the pointer that the created node 
 *                      pointer will be assigned to
 * @return The result of the function
 */
int new_mj_type(minijava_type type, ast *identifier, ast **node);

/**
 * Deletes a mj_type struct
 *
 * @param t The struct to delete
 */
void delete_mj_type(mj_type *t);

#endif /* INCLUDE_jrv_mj_type_h__ */
