#ifndef INCLUDE_jrv_ast_walker_h__
#define INCLUDE_jrv_ast_walker_h__

#include "ast.h"
#include "mj_identifier.h"
#include "mj_unary_operation.h"
#include "mj_binary_operation.h"
#include "mj_integer.h"
#include "mj_boolean.h"
#include "mj_new_object.h"
#include "ast_list.h"
#include "mj_call.h"
#include "mj_this.h"
#include "mj_print.h"
#include "mj_main_class.h"
#include "mj_class.h"
#include "mj_type.h"
#include "mj_var_decl.h"
#include "mj_method_arg.h"
#include "mj_method_body.h"
#include "mj_method_decl.h"
#include "mj_if.h"
#include "mj_while.h"
#include "mj_assignment.h"
#include "mj_array_assignment.h"

/**
 * This struct stores the callbacks for the ast_walk function. Each time the 
 * ast_walk function encounters a node of a given type, the corresponding 
 * callback will be called.
 *
 * For example, if ast_walk function encounters a identifier node, 
 * the function pointer in the member on_identifier will be 
 * dereferenced and called.
 */
typedef struct {
    /** The callback for an identifier node */
    void (*on_mj_identifier)(mj_identifier *node, void *result);
    
    /** The callback for the addition binary operation */
    void (*on_mj_addition)(mj_binary_operation *node, void *result);
    
    /** The callback for the subtraction binary operation */
    void (*on_mj_subtraction)(mj_binary_operation *node, void *result);
    
    /** The callback for the division binary operation */
    void (*on_mj_division)(mj_binary_operation *node, void *result);

    /** The callback for the multiplication binary operation */
    void (*on_mj_multiplication)(mj_binary_operation *node, void *result);

    /** The callback for the logical and binary operation */
    void (*on_mj_and)(mj_binary_operation *node, void *result);

    /** The callback for the less than binary operation */
    void (*on_mj_less_than)(mj_binary_operation *node, void *result);
    
    /** The callback for the array lookup unary operation */
    void (*on_mj_array_lookup)(mj_binary_operation *node, void *result);

    /** The callback for the array length unary operation */
    void (*on_mj_array_length)(mj_unary_operation *node, void *result);
    
    /** The callback for the logical not unary operation */
    void (*on_mj_not)(mj_unary_operation *node, void *result);
   
    /** The callback for the new array unary operation */
    void (*on_mj_new_array)(mj_unary_operation *node, void *result);

    /** The callback for an integer */
    void (*on_mj_integer)(mj_integer *node, void *result);

    /** The callback for a this object */
    void (*on_mj_this)(ast *node, void *result);

    /** The callback for a boolean */
    void (*on_mj_boolean)(mj_boolean *node, void *result);

    /** The callback for an ast_list */
    void (*on_mj_ast_list)(mj_ast_list *node, void *result);

    /** The callback for a new_object operation */
    void (*on_mj_new_object)(mj_new_object *node, void *result);

    /** The callback for a call operation */
    void (*on_mj_call)(mj_call *node, void *result);

    /** The callback for a print statement */
    void (*on_mj_print)(mj_print *node, void *result);

    /** The callback for a main_class */
    void (*on_mj_main_class)(mj_main_class *node, void *result);

    /** The callback for a class */
    void (*on_mj_class)(mj_class *node, void *result);

    /** The callback for a type */
    void (*on_mj_type)(mj_type *node, void *result);
    
    /** The callback for a variable declaration */
    void (*on_mj_var_decl)(mj_var_decl *node, void *result);

    /** The callback for a method argument */
    void (*on_mj_method_arg)(mj_method_arg *node, void *result);

    /** The callback for a method body */
    void (*on_mj_method_body)(mj_method_body *node, void *result);

    /** The callback for a method declaration */
    void (*on_mj_method_decl)(mj_method_decl *node, void *result);

    /** The callback for an if-else statement */
    void (*on_mj_if)(mj_if *node, void *result);

    /** The callback for a while statement */
    void (*on_mj_while)(mj_while *node, void *result);

    /** The callback for an assignment statement */
    void (*on_mj_assignment)(mj_assignment *node, void *result);

    /** The callback for an array assignment statement */
    void (*on_mj_array_assignment)(mj_array_assignment *node, void *result);
} ast_callbacks;

/**
 * This function walks an AST depth-first, left to right. 
 * Each time a node is encountered, the registered callback in 
 * the parameter callback will be called.
 *
 * @param[in] tree The AST to walk
 * @param[in] callbacks All the callbacks to call upon encountering nodes of 
 *                      specific types
 * @param[out] result A pointer to the result of the walk
 */
void ast_walk(ast* tree, ast_callbacks callbacks, void *result);

/**
 * This function visits the given node, that is, it calls the
 * callback that is registered for the nodes type.
 * This function should typically be called from the callback functions
 * in order to evaluate child nodes.
 *
 * @param[in] node The node to visit
 * @param[out] result The result from the visit
 */
void ast_visit(ast* node, void *result);

#endif /* INCLUDE_jrv_ast_walker_h__ */
