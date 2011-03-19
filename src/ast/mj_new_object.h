#ifndef INCLUDE_jrv_mj_new_object_h__
#define INCLUDE_jrv_mj_new_object_h__

#include "ast.h"
#include "mj_identifier.h"

/**
 * Represents a new object operation in the AST
 */
typedef struct {
    /** The type of the node (MJ_NEW_OBJECT) */
    nodetype type;

    /** The id of the class of the object */
    mj_identifier *class_id;
} mj_new_object;

/**
 * Creates a new new_object with the given id.
 *
 * @param[in] id The identifier of the class of the object
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_new_object(ast *class_id, ast **node);

/**
 * Deletes a mj_new_object struct
 *
 * @param no The new_object_struct to delete
 */
void delete_mj_new_object(mj_new_object *no);

#endif /* INCLUDE_jrv_mj_new_object_h__ */
