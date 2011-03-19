#ifndef INCLUDE_jrv_ast_list_h__
#define INCLUDE_jrv_ast_list_h__

#include "list.h"
#include "ast2.h"

/**
 * This struct represents a list of ast elements
 */
typedef struct {
    /** The type of the node (AST_LIST) */
    nodetype type;

    /** The actual list of ast nodes */
    list* list;
} mj_ast_list;

/**
 * Creates a new ast list with the given list.
 *
 * @param[in] list The list of of AST nodes
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_ast_list(list* list, ast **node);

/**
 * Creates an empty ast list and assigns it to node
 *
 * @param[out] The address of the pointer that will point to the empty list
 * @return An integer describing the result
 */
int empty_mj_ast_list(ast **node);

/**
 * Prepends an AST node to a ast_list
 *
 * @param[in] al The list of AST nodes
 * @param[in] node The AST node to prepend
 * @return An integer describing the result of the function
 */
int mj_ast_list_prepend(ast *al, ast *node);

/** 
 * Deletes an ast list
 *
 * @param al The list to delete
 */
void delete_mj_ast_list(mj_ast_list *al);

#endif /* INCLUDE_jrv_ast_list_h__ */
