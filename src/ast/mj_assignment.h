#ifndef INCLUDE_jrv_mj_assignment_h__
#define INCLUDE_jrv_mj_assignment_h__

#include "ast2.h"
#include "mj_identifier.h"

/**
 * Represents an assignment in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_ASSIGNMENT) */
    nodetype type;

    /** The identifier that gets assigned */
    mj_identifier *id;

    /** The expression to assing to the indentifier */
    ast *expression;
} mj_assignment;

/**
 * Creates a new assignment statement in MiniJava
 *
 * @param[in] id The identifier that gets assigned
 * @param[in] expression The expression that yields the value to assign to 
 *                       the identifier
 * @param[out] node The address of the pointer to assign the result to
 * @return The result of the function
 */
int new_mj_assignment(ast *id, ast *expression, ast **node);

/**
 * Deletes an mj_assignment struct
 *
 * @param a The struct to delete
 */
void delete_mj_assignment(mj_assignment *a);

#endif /* INCLUDE_jrv_mj_assignment_h__ */
