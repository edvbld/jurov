#ifndef INCLUDE_jrv_mj_while_h__
#define INCLUDE_jrv_mj_while_h__

#include "ast2.h"

/**
 * Reprents a while loop in the MiniJava programming language
 */
typedef struct {
    /** The type of the node (MJ_WHILE) */
    nodetype type;

    /** The condition of the while loop */
    ast *condition;

    /** The statement of the while loop */
    ast *statement;
} mj_while;

/**
 * Creates a new while loop in the MiniJava language
 *
 * @param[in] condition The condition for the while loop
 * @param[in] statement The statement in the body of the while loop
 * @param[out] node The address of the pointer that the result will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_while(ast *condition, ast *statement, ast **node);

/**
 * Deletes a mj_while struct
 *
 * @param w The struct to delete
 */
void delete_mj_while(mj_while *w);

#endif /* INCLUDE_jrv_mj_while_h__ */
