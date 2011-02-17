#include "ast.h"
#include "utils.h"

ast* new_identifier(char *name)
{
    identifier* id_node = j_malloc(sizeof(identifier));
    id_node->name = name; 
    return (ast*) id_node;
}

ast* new_ast(ast* left, ast* right)
{
    ast* node = j_malloc(sizeof(ast));
    node->left = left;
    node->right = right;
    return node;
}
