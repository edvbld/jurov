#ifndef INCLUDE_jrv_mj_this_h__
#define INCLUDE_jrv_mj_this_h__

#include "ast2.h"

/**
 * Creates a new ast struct with type THIS
 *
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_this(ast **node);

/**
 * Deletes a mj_this struct
 *
 * @param this the struct to delete
 */
void delete_mj_this(ast *this);

#endif /* INCLUDE_jrv_mj_this_h__ */
