#ifndef INCLUDE_jrv_mj_array_assignment_h__
#define INCLUDE_jrv_mj_array_assignment_h__

#include "ast.h"
#include "mj_identifier.h"

/**
 * Represents an array assignment in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_ARRAY_ASSIGNMENT) */
    nodetype type;

    /** The id of the array */
    mj_identifier *id;

    /** The expression to yield the array index */
    ast *index_exp;

    /** The expression to assign to the array index */
    ast *value_exp;
} mj_array_assignment;

/**
 * Creates a new array assignment statement in MiniJava
 *
 * @param[in] id The identifier of the array
 * @param[in] index_exp The expression that yields the index to assign to
 * @param[in] value_exp The expression that yields the value to assign to 
 *                      the object at the index
 * @param[out] node The address of the pointer that the result will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_array_assignment(ast *id, ast *index_exp, ast *value_exp,
                            ast **node);

/**
 * Deletes a mj_array_assignment struct
 *
 * @param aa The struct to delete
 */
void delete_mj_array_assignment(mj_array_assignment *aa);

#endif /* INCLUDE_jrv_mj_array_assignment_h__ */
