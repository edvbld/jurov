#ifndef INCLUDE_jrv_mj_main_class_h__
#define INCLUDE_jrv_mj_main_class_h__

#include "ast2.h"
#include "mj_identifier.h"
#include "ast_list.h"

/**
 * Represents the main class of a MiniJava program
 */
typedef struct {
    /** The type of the node (nodetype.MJ_MAIN_CLASS) */
    nodetype type;

    /** The id of the main class */
    mj_identifier *class_id;

    /** The id of the String[] parameter to the main method */
    mj_identifier *parameter_id;

    /** The statement inside the main methods body */
    mj_ast_list *statements;
} mj_main_class;

/**
 * Creates a new main_class node with the given parameters
 *
 * @param[in] class_id The identifier of the main class
 * @param[in] parameter_id The identifier of the String[] parameter to the main 
 *                     method
 * @param[in] statements The statements inside the main methods body
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_main_class(ast *class_id, ast *parameter_id, ast* statements, 
                      ast **node);

/**
 * Deletes a mj_main_class struct
 *
 * @param mc The struct to delete
 */
void delete_mj_main_class(mj_main_class *mc);
#endif /* INCLUDE_jrv_mj_main_class_h__ */
