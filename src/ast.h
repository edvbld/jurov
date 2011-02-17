#ifndef __AST_H__
#define __AST_H__

/**
 * Represents all different kinds of nodes that can exists in the AST
 */
typedef enum {
    /** An ast struct */
    AST = 0, 
    /** An indentifier_node struct */
    IDENTIFIER
} nodetype;

/**
 * Represents an abstract syntax tree (AST). 
 */
typedef struct ast {
    /**  The type of the node */
    nodetype type; 
    /** The left branch of the tree */
    struct ast* left; 
    /** The right branch of the tree */
    struct ast* right;
} ast;

/**
 * Creates an AST with the given left branch and the given right branch.
 *
 * @param left  The left branch
 * @param right The right branch
 * @return A pointer to the newly created ast node
 */
ast* new_ast(ast* left, ast* right);

/**
 * Represents an identifier node in the AST.
 */
typedef struct {
    /** The type of the node (nodetype.INDENTIFIER) */
    nodetype type;
    /** The name of the indentifier */
    char *name;
} identifier;

/**
 * Creates a new indentifier with the given id.
 *
 * @param name The name of the indentifier
 * @return A pointer to an ast struct
 */
ast* new_identifier(char *name);

/**
 * The result from the parser. After calling yyparse(), this variable will hold 
 * the generated AST.
 */
ast* ast_parser_result;

/**
 * This struct is used together with the ast_walk function. Each time the 
 * ast_walk function encounters a node of a given type, the corresponding 
 * callback will be called.
 *
 * For example, if ast_walk function encounters a indentifier node, 
 * the the function pointer in member identifier_node will be 
 * dereferenced and called.
 */
typedef struct {
    /** The callback for an identifier node */
    void (*on_identifier)(identifier *node);
    /** The callback for an ast node */
    void (*on_ast)(ast *tree);
} ast_callbacks;

/**
 * This function walks an AST depth-first, left to right. 
 * Each time a node is encountered, the registered callback in 
 * the paramter callback will be called.
 *
 * @param tree The AST to walk
 * @param callbacks All the callbacks to call upon encontering nodes of 
 *                  specific types
 */
void ast_walker(ast* tree, ast_callbacks* callbacks);

#endif // __AST_H__
