#include "ast.h"
#include "utils.h"
ast* new_identifier(char *name)
{
    identifier *id = j_malloc(sizeof(identifier));
    id->name = name; 
    id->type = IDENTIFIER;
    return (ast*) id;
}

ast* new_binary_operation(nodetype type, ast *left_operand, ast *right_operand)
{
    binary_operation *op = j_malloc(sizeof(binary_operation));
    op->type = type;
    op->left_operand = left_operand;
    op->right_operand = right_operand;
    return (ast*) op;
}

ast* new_unary_operation(nodetype type, ast *operand)
{
    unary_operation *op = j_malloc(sizeof(unary_operation));
    op->type = type;
    op->operand = operand;
    return (ast *) op;
}

ast* new_integer(int value)
{
    integer *i = j_malloc(sizeof(integer));
    i->value = value;
    i->type = INTEGER;
    return (ast *) i;
}

ast* new_boolean(int value)
{
    boolean *b = j_malloc(sizeof(boolean));
    b->type = BOOL;
    b->value = value;
    return (ast *) b;
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
        case IDENTIFIER: 
            if(_callbacks.on_identifier != NULL) {
                _callbacks.on_identifier((identifier *) node, result);
            }
            break;
        case ADDITION:
            if(_callbacks.on_addition != NULL) {
                _callbacks.on_addition((binary_operation *) node, result);
            }
            break;
        case SUBTRACTION:
            if(_callbacks.on_subtraction != NULL) {
                _callbacks.on_subtraction((binary_operation *) node, result);
            }
            break;
        case DIVISION:
            if(_callbacks.on_division != NULL) {
                _callbacks.on_division((binary_operation *) node, result);
            }
            break;
        case MULTIPLICATION:
            if(_callbacks.on_multiplication != NULL) {
                _callbacks.on_multiplication((binary_operation *) node, result);
            }
            break;
        case LESS_THAN:
            if(_callbacks.on_less_than != NULL) {
                _callbacks.on_less_than((binary_operation *) node, result);
            }
            break;
        case ARRAY_LOOKUP:
            if(_callbacks.on_array_lookup != NULL) {
                _callbacks.on_array_lookup((unary_operation *) node, result);
            }
            break;
        case ARRAY_LENGTH:
            if(_callbacks.on_array_length != NULL) {
                _callbacks.on_array_length((unary_operation *) node, result);
            }
            break;
        case NOT:
            if(_callbacks.on_not != NULL) {
                _callbacks.on_not((unary_operation *) node, result);
            }
            break;
        case NEW_ARRAY:
            if(_callbacks.on_new_array != NULL) {
                _callbacks.on_new_array((unary_operation *) node, result);
            }
            break;
        case INTEGER:
            if(_callbacks.on_integer != NULL) {
                _callbacks.on_integer((integer *) node, result);
            }
            break;
        default:
            die("Unknown AST node found");
    }
}
