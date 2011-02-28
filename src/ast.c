#include "stdio.h"
#include "stddef.h"
#include "string.h"
#include "errors.h"
#include "ast.h"
#include "utils.h"

int new_mj_identifier(char *name, ast **node)
{
    mj_identifier *id;

    if(name == NULL || strlen(name) == 0) {
        *node = NULL;
        return JRV_INVALID_STRING;
    }

    id = jrv_malloc(sizeof(mj_identifier));
    id->name = name; 
    id->type = MJ_IDENTIFIER;
    *node = (ast *) id;
    return JRV_SUCCESS;
}

int new_mj_binary_operation(nodetype type, ast *left_operand, 
                            ast *right_operand, ast **node)
{
    mj_binary_operation *op = jrv_malloc(sizeof(mj_binary_operation));
    op->type = type;
    op->left_operand = left_operand;
    op->right_operand = right_operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

int new_mj_unary_operation(nodetype type, ast *operand, ast **node)
{
    mj_unary_operation *op = jrv_malloc(sizeof(mj_unary_operation));
    op->type = type;
    op->operand = operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

int new_mj_integer(int value, ast **node)
{
    mj_integer *i = jrv_malloc(sizeof(mj_integer));
    i->value = value;
    i->type = MJ_INTEGER;
    *node = (ast *) i;
    return JRV_SUCCESS;
}

int new_mj_boolean(int value, ast **node)
{
    mj_boolean *b = jrv_malloc(sizeof(mj_boolean));
    b->type = MJ_BOOLEAN;
    b->value = value;
    *node = (ast *) b;
    return JRV_SUCCESS;
}

int new_mj_new_object(ast *class_id, ast **node)
{
    mj_new_object *no;
    
    if(class_id != NULL && class_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    no = jrv_malloc(sizeof(mj_new_object));
    no->type = MJ_NEW_OBJECT;
    no->class_id = (mj_identifier *) class_id;
    *node = (ast *) no;
    return JRV_SUCCESS;
}

int new_mj_ast_list(list *list, ast **node)
{
    mj_ast_list *al = jrv_malloc(sizeof(mj_ast_list));
    al->type = MJ_AST_LIST;
    al->list = list;
    *node = (ast *) al;
    return JRV_SUCCESS;
}

int new_mj_call(ast *object, ast *method, mj_ast_list *parameters, ast **node)
{
    mj_call *c;
    
    if(method != NULL && method->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    c = jrv_malloc(sizeof(mj_call));
    c->type = MJ_CALL;
    c->object = object;
    c->method = (mj_identifier *) method;
    c->parameters = parameters;
    *node = (ast *) c;
    return JRV_SUCCESS;
}

int new_mj_this(ast **node)
{
    ast* this = jrv_malloc(sizeof(ast));
    this->type = MJ_THIS;
    *node = this;
    return JRV_SUCCESS;
}

int new_mj_print(ast* expression, ast **node)
{
    mj_print *p = jrv_malloc(sizeof(mj_print));
    p->type = MJ_PRINT;
    p->expression = expression;
    *node = (ast *) p;
    return JRV_SUCCESS;
}

int new_mj_main_class(ast *class_id, ast *parameter_id, ast* statement, 
                      ast **node)
{
    mj_main_class *mc;
    
    if(class_id != NULL && class_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }
    
    if(parameter_id != NULL && parameter_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }
    
    mc = jrv_malloc(sizeof(mj_main_class));
    mc->type = MJ_MAIN_CLASS;
    mc->class_id = (mj_identifier *) class_id;
    mc->parameter_id = (mj_identifier *) parameter_id;
    mc->statement = statement;
    *node = (ast *) mc;
    return JRV_SUCCESS;
}

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
                _callbacks.on_mj_array_lookup((mj_unary_operation *) node, 
                                              result);
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
        default:
            jrv_die("Unknown AST node found");
    }
}

int delete_ast(ast *tree)
{
    return JRV_SUCCESS;
}

void delete_mj_this(ast *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_boolean(mj_boolean *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_integer(mj_integer *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_identifier(mj_identifier *node, void *p)
{
    jrv_free(&node->name);
    jrv_free(&node);
}

void delete_mj_unary_operation(mj_unary_operation *node, void *p)
{
    ast_visit(node->operand, p);
    jrv_free(&node);
}

void delete_mj_binary_operation(mj_binary_operation *node, void *p)
{
    ast_visit(node->left_operand, p);
    ast_visit(node->right_operand, p);
    jrv_free(&node);
}

void delete_mj_new_object(mj_new_object *node, void *p)
{
    delete_mj_identifier(node->class_id, NULL);
    jrv_free(&node);
}

void delete_mj_ast_list_element(void *data)
{
    ast_visit((ast *) data, NULL);
}

void delete_mj_ast_list(mj_ast_list *node, void *p)
{
    if(node != NULL) {
        delete_list_cb(node->list, &delete_mj_ast_list_element);
        jrv_free(&node);
    }
}

void delete_mj_call(mj_call *node, void *p)
{
    ast_visit(node->object, p);
    delete_mj_identifier(node->method, p);
    delete_mj_ast_list(node->parameters, p);
    jrv_free(&node);
}

void delete_mj_print(mj_print *node, void *p)
{
    ast_visit(node->expression, p);
    jrv_free(&node);
}

void delete_mj_main_class(mj_main_class *node, void *p)
{
    delete_mj_identifier(node->class_id, p);
    delete_mj_identifier(node->parameter_id, p);
    ast_visit(node->statement, p);
    jrv_free(&node);
}
