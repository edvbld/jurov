#ifndef INCLUDE_jrv_mj_boolean_h__
#define INCLUDE_jrv_mj_boolean_h__

#include "ast2.h"

/**
 * Represents a boolean in the AST
 */
typedef struct {
    /** The type of the node (nodetype.BOOL) */
    nodetype type;
    /** The value of the boolean */
    int value;
} mj_boolean;

/**
 * Creates a new boolean with the given value.
 *
 * @param[in] value The value of the boolean expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_boolean(int value, ast **node);

/**
 * Deletes a minijava boolean
 *
 * @param b The mj boolean to delete
 */
void delete_mj_boolean(mj_boolean *b);

#endif /* INCLUDE_jrv_mj_boolean_h__ */
