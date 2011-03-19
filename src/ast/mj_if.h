#ifndef INCLUDE_jrv_mj_if_h__
#define INCLUDE_jrv_mj_if_h__

#include "ast2.h"

/**
 * Represents an if-else expression in MiniJava
 */
typedef struct {
    /** The type of the node (MJ_IF) */
    nodetype type;

    /** The expression to evaulate to a boolean value */
    ast *condition;

    /** The statement(s) to execute if the condition is true */
    ast *true_statement;

    /** The statement(s) to execute if the condition is false */
    ast *false_statement;
} mj_if;

/**
 * Creates a new if-else statement in the MiniJava language
 *
 * @param[in] condition The expression to evaluate as the condition for the 
 *                      if statement
 * @param[in] true_statement The statement(s) to run if the condition is true
 * @param[in] false_statement The statement(s) to run if the condition is false
 * @param[out] node The address of the pointer that the pointer to the created 
 *                  node will be assigned to
 * @return The result of the function
 */
int new_mj_if(ast *condition, ast *true_statement, ast *false_statement, 
              ast **node);

/** 
 * Deletes a mj_if struct
 *
 * @param i The struct to delete
 */
void delete_mj_if(mj_if *i);

#endif /* INCLUDE_jrv_mj_if_h__ */
