#ifndef INCLUDE_jrv_mj_identifier_h__
#define INCLUDE_jrv_mj_identifier_h__

#include "ast2.h"

/**
 * Represents an identifier node in the AST.
 */
typedef struct {
    /** The type of the node (nodetype.IDENTIFIER) */
    nodetype type;
    /** The name of the identifier */
    char *name;
} mj_identifier;

/**
 * Creates a new identifier with the given name.
 *
 * @param[in] name The name of the identifier
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_identifier(char *name, ast **node);

/**
 * Deletes the identifier
 *
 * @param id The identifier to delete
 */
void delete_mj_identifier(mj_identifier *id);

#endif /* INCLUDE_jrv_mj_identifier_h__ */
