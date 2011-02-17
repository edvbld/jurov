#include "ast.h"
#include "utils.h"

ast* new_ast(ast* left, ast* right)
{
    ast *node = j_malloc(sizeof(ast));
    node->left = left;
    node->right = right;
    return node;
}

ast* new_identifier(char *name)
{
    identifier *id_node = j_malloc(sizeof(identifier));
    id_node->name = name; 
    return (ast*) id_node;
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

ast_callbacks _callbacks;

void ast_walk(ast* tree, ast_callbacks callbacks, void *result)
{
    _callbacks = callbacks;
    ast_descend(tree, result);
}

void ast_descend(ast *tree, void *result)
{
    if(tree == NULL) {
        return;
    }
    switch(tree->type) {
        case IDENTIFIER: 
            _callbacks.on_identifier((identifier *) tree, result);
            break;
        case ADDITION:
            _callbacks.on_addition((binary_operation *) tree, result);
            break;
        case SUBTRACTION:
            _callbacks.on_subtraction((binary_operation *) tree, result);
            break;
        case DIVISION:
            _callbacks.on_division((binary_operation *) tree, result);
            break;
        case MULTIPLICATION:
            _callbacks.on_multiplication((binary_operation *) tree, result);
            break;
        case LESS_THAN:
            _callbacks.on_less_than((binary_operation *) tree, result);
            break;
        case ARRAY_LOOKUP:
            _callbacks.on_array_lookup((unary_operation *) tree, result);
            break;
        case ARRAY_LENGTH:
            _callbacks.on_array_length((unary_operation *) tree, result);
            break;
        case NOT:
            _callbacks.on_not((unary_operation *) tree, result);
            break;
        case NEW_ARRAY:
            _callbacks.on_new_array((unary_operation *) tree, result);
            break;
        case INTEGER:
            _callbacks.on_integer((integer *) tree, result);
            break;
        default:
            die("Unknown AST node found");
    }
}
