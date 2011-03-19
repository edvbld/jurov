#ifndef INCLUDE_mj_class_h__
#define INCLUDE_mj_class_h__

#include "ast.h"
#include "mj_identifier.h"
#include "ast_list.h"

/**
 * Reprents a class in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_CLASS) */
    nodetype type;

    /** The identifier (name) of the class */
    mj_identifier *id;

    /** A list of the variable declarations */
    mj_ast_list *var_declarations;

    /** A list of the methods declarations */
    mj_ast_list *method_declarations;
} mj_class;

/**
 * Creates new class node with the given parameters
 *
 * @param[in] id The id (name) of the class
 * @param[in] var_declarations A list of the variable declarations of the class
 * @param[in] method_declarations A list of the method declarations of the class
 * @param[out] node The address of the pointer that mj_class node will be 
 *                  assigned to
 * @return An integer describing the result
 */
int new_mj_class(ast *id, ast *var_declarations, 
                 ast *method_declarations, ast **node);

/**
 * Deletes a mj_class struct
 *
 * @param c The struct to delete
 */
void delete_mj_class(mj_class *c);

#endif /* INCLUDE_mj_class_h__ */
