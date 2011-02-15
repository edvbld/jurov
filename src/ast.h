#ifndef __AST_H__
#define __AST_H__

/*
 * Represents all different kinds of nodes that can exists in the AST
 */
enum nodetype {
    AST = 0,
    IDENTIFIER 
};

/*
 * Represents an abstract syntax tree (AST). 
 *
 * :member type: The type of the node (AST)
 * :member left: The left branch of the AST
 * :member right: The right branch of the AST
 */
struct ast {
    enum nodetype type;
    struct ast* left;
    struct ast* right;
};

/*
 * Creates an AST with the given left branch and the given right branch.
 *
 * :param left: The left branch
 * :param right: The right branch
 * :returns: A pointer to the newly created ast node
 */
struct ast* new_ast(struct ast* left, struct ast*right);

/*
 * Represents an identifier node in the AST.
 *
 * :member type: The type of the node (IDENTIFIER)
 * :member name: The name of the indentifier
 */
struct identifier_node {
    enum nodetype type;
    char *name;
};

/*
 * Creates a new indentifier node with the given id.
 *
 * :param id: The name of the indentifier
 * :returns: A pointer to an ast struct
 */
struct ast* new_identifier_node(char *name);

/*
 * The result from the parser. After calling yyparse(), this variable will hold 
 * the generated AST.
 */
struct ast* ast_parser_result;

/*
 * This struct is together with the ast_walk function. Each time the 
 * ast_walk function encounters a node of a given type, the corresponding 
 * callback will be called.
 *
 * For example, if ast_walk function encounters a indentifier node, 
 * the the function pointer in member identifier_node will be 
 * dereferenced and called.
 *
 * :member identifier_node: The callback for an identifier node
 * :member ast: The callback for an ast node
 */
struct walker_callbacks {
    void (*identifier_node)(struct identifier_node *node);
    void (*ast)(struct ast *tree);
};

/*
 * This function walks an AST depth-first, left to right. 
 * Each time a node is encountered, the registered callback in 
 * the paramter callback will be called.
 *
 * :param tree: The AST to walk
 * :type tree: struct ast*
 * :param callbacks: All the callbacks to call upon encontering nodes of 
 *                   specific types
 * :type callback: struct walker_callbacks*
 */
void ast_walker(struct ast* tree, struct walker_callbacks* callbacks);

#endif // __AST_H__
