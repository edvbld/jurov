#include "stddef.h"
#include "utils.h"
#include "ast_walker.h"

ast_callbacks _callbacks;
void ast_walk(ast* tree, ast_callbacks callbacks, void *result)
{
    _callbacks = callbacks;
    ast_visit(tree, result);
}

void ast_visit(ast *node, void *result)
{
    if(node == NULL) {
        return;
    }
    switch(node->type) {
        case MJ_IDENTIFIER: 
            if(_callbacks.on_mj_identifier != NULL) {
                _callbacks.on_mj_identifier((mj_identifier *) node, result);
            }
            break;
        case MJ_ADDITION:
            if(_callbacks.on_mj_addition != NULL) {
                _callbacks.on_mj_addition((mj_binary_operation *) node, result);
            }
            break;
        case MJ_SUBTRACTION:
            if(_callbacks.on_mj_subtraction != NULL) {
                _callbacks.on_mj_subtraction((mj_binary_operation *) node, 
                                             result);
            }
            break;
        case MJ_DIVISION:
            if(_callbacks.on_mj_division != NULL) {
                _callbacks.on_mj_division((mj_binary_operation *) node, 
                                          result);
            }
            break;
        case MJ_MULTIPLICATION:
            if(_callbacks.on_mj_multiplication != NULL) {
                _callbacks.on_mj_multiplication((mj_binary_operation *) node, 
                                                result);
            }
            break;
        case MJ_LESS_THAN:
            if(_callbacks.on_mj_less_than != NULL) {
                _callbacks.on_mj_less_than((mj_binary_operation *) node, 
                                           result);
            }
            break;
        case MJ_ARRAY_LOOKUP:
            if(_callbacks.on_mj_array_lookup != NULL) {
                _callbacks.on_mj_array_lookup((mj_binary_operation *) node, 
                                              result);
            }
            break;
        case MJ_AND:
            if(_callbacks.on_mj_and != NULL) {
                _callbacks.on_mj_and((mj_binary_operation *) node, result);
            }
            break;
        case MJ_ARRAY_LENGTH:
            if(_callbacks.on_mj_array_length != NULL) {
                _callbacks.on_mj_array_length((mj_unary_operation *) node, 
                                              result);
            }
            break;
        case MJ_NOT:
            if(_callbacks.on_mj_not != NULL) {
                _callbacks.on_mj_not((mj_unary_operation *) node, result);
            }
            break;
        case MJ_NEW_ARRAY:
            if(_callbacks.on_mj_new_array != NULL) {
                _callbacks.on_mj_new_array((mj_unary_operation *) node, result);
            }
            break;
        case MJ_INTEGER:
            if(_callbacks.on_mj_integer != NULL) {
                _callbacks.on_mj_integer((mj_integer *) node, result);
            }
            break;
        case MJ_THIS:
            if(_callbacks.on_mj_this != NULL) {
                _callbacks.on_mj_this((ast *) node, result);
            }
            break;
        case MJ_BOOLEAN:
            if(_callbacks.on_mj_boolean != NULL) {
                _callbacks.on_mj_boolean((mj_boolean *) node, result);
            }
            break;
        case MJ_AST_LIST:
            if(_callbacks.on_mj_ast_list != NULL) {
                _callbacks.on_mj_ast_list((mj_ast_list *) node, result);
            }
            break;
        case MJ_NEW_OBJECT:
            if(_callbacks.on_mj_new_object != NULL) {
                _callbacks.on_mj_new_object((mj_new_object *) node, result);
            }
            break;
        case MJ_CALL:
            if(_callbacks.on_mj_call != NULL) {
                _callbacks.on_mj_call((mj_call *) node, result);
            }
            break;
        case MJ_PRINT:
            if(_callbacks.on_mj_print != NULL) {
                _callbacks.on_mj_print((mj_print *) node, result);
            }
            break;
        case MJ_MAIN_CLASS:
            if(_callbacks.on_mj_main_class != NULL) {
                _callbacks.on_mj_main_class((mj_main_class *) node, result);
            }
            break;
        case MJ_CLASS:
            if(_callbacks.on_mj_class != NULL) {
                _callbacks.on_mj_class((mj_class *) node, result);
            }
            break;
        case MJ_TYPE:
            if(_callbacks.on_mj_type != NULL) {
                _callbacks.on_mj_type((mj_type *) node, result);
            }
            break;
        case MJ_VAR_DECL:
            if(_callbacks.on_mj_var_decl != NULL) {
                _callbacks.on_mj_var_decl((mj_var_decl *) node, result);
            }
            break;
        case MJ_METHOD_ARG:
            if(_callbacks.on_mj_method_arg != NULL) {
                _callbacks.on_mj_method_arg((mj_method_arg *) node, result);
            }
            break;
        case MJ_METHOD_BODY:
            if(_callbacks.on_mj_method_body != NULL) {
                _callbacks.on_mj_method_body((mj_method_body *) node, result);
            }
            break;
        case MJ_METHOD_DECL:
            if(_callbacks.on_mj_method_decl != NULL) {
                _callbacks.on_mj_method_decl((mj_method_decl *) node, result);
            }
            break;
        case MJ_IF:
            if(_callbacks.on_mj_if != NULL) {
                _callbacks.on_mj_if((mj_if *) node, result);
            }
            break;
        case MJ_WHILE:
            if(_callbacks.on_mj_while != NULL) {
                _callbacks.on_mj_while((mj_while *) node, result);
            }
            break;
        case MJ_ASSIGNMENT:
            if(_callbacks.on_mj_assignment != NULL) {
                _callbacks.on_mj_assignment((mj_assignment *) node, result);
            }
            break;
        case MJ_ARRAY_ASSIGNMENT:
            if(_callbacks.on_mj_array_assignment != NULL) {
                _callbacks.on_mj_array_assignment((mj_array_assignment *) node,
                                                  result);
            }
            break;
        default:
            jrv_die("Unknown AST node found");
    }
}
