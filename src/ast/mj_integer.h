#ifndef INCLUDE_jrv_mj_integer_h__
#define INCLUDE_jrv_mj_integer_h__

#include "ast2.h"

/**
 * Represents an integer node in t
 * he AST
 */
typedef struct {
    /** the type of the integer (nodetype.INTEGER) */
    nodetype type;
    /** the value of the integer */
    int value;
} mj_integer;

/**
 * Creates a new integer with the given value.
 *
 * @param[in] value The value of the integer
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_integer(int value, ast **node);

/**
 * Deletes a minijava integer
 *
 * @param i The integer to delete
 */
void delete_mj_integer(mj_integer *i);


#endif /* INCLUDE_jrv_mj_integer_h__ */
