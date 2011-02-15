#include "ast.h"
#include "utils.h"

struct ast* new_identifier_node(char *name)
{
    struct identifier_node* id_node = j_malloc(sizeof(struct identifier_node));
    id_node->name = name; 
    return (struct ast*) id_node;
}

struct ast* new_ast(struct ast* left, struct ast* right)
{
    struct ast* node = j_malloc(sizeof(struct ast));
    node->left = left;
    node->right = right;
    return node;
}
