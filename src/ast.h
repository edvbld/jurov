#ifndef __AST_H__
#define __AST_H__

/**
 * Represents all different kinds of nodes that can exists in the AST
 */
typedef enum {
    /** An identifier struct */
    IDENTIFIER,
    /** Addition, a binary_operation struct */
    ADDITION,
    /** Subtraction, a binary_operation struct */
    SUBTRACTION,
    /** Division, a binary_operation struct */
    DIVISION,
    /** Multiplication, a binary_operation struct */
    MULTIPLICATION,
    /** Less than, a binary_operation struct */
    LESS_THAN,
    /** Array lookup, a binary_operation struct */
    ARRAY_LOOKUP,
    /** Array length, an unary_operation struct */
    ARRAY_LENGTH,
    /** Logical not, an unary_operation struct */
    NOT,
    /** New array, an unary_operation struct */
    NEW_ARRAY,
    /** An integer struct */
    INTEGER,
    /** A boolean struct */
    BOOL,
    /** A new_object struct */
    NEW_OBJECT
} nodetype;

/**
 * Represents an abstract syntax tree (AST). 
 */
typedef struct ast {
    /**  The type of the node */
    nodetype type; 
} ast;

/**
 * Represents an identifier node in the AST.
 */
typedef struct {
    /** The type of the node (nodetype.IDENTIFIER) */
    nodetype type;
    /** The name of the identifier */
    char *name;
} identifier;

/**
 * Creates a new identifier with the given name.
 *
 * @param name The name of the identifier
 * @return A pointer to an ast struct
 */
ast* new_identifier(char *name);

/**
 * Represents a binary operation (such as +,-,*,< etc.) node in the AST
 */
typedef struct {
    /** The type of the node */
    nodetype type;
    /** The left operand to the operation */
    ast *left_operand;
    /** The right operand to the operation */
    ast *right_operand;

} binary_operation;

/**
 * Creates a new binary operation with the given type and 
 * operands.
 *
 * @param type The type of the operation
 * @param left_operand The left operand of the expression
 * @param right_operand The right operand of the expression
 * @return A point to an ast struct
 */
ast* new_binary_operation(nodetype type, ast* left_operand, ast* right_operand);

/**
 * Represents an unary operation (such as .length, new, not) node in the AST
 */
typedef struct {
    /** The type of the node */
    nodetype type;
    /** The argument to the operation */
    ast *operand;
} unary_operation;

/**
 * Creates a new unary operation with the given type and 
 * operand.
 *
 * @param type The type of the operation
 * @param operand The operand of the expression
 * @return A point to an ast struct
 */
ast* new_unary_operation(nodetype type, ast* operand);

/**
 * Represents an integer node in the AST
 */
typedef struct {
    /** the type of the integer (nodetype.INTEGER) */
    nodetype type;
    /** the value of the integer */
    int value;
} integer;

/**
 * Creates a new integer with the given value.
 *
 * @param value The value of the integer
 * @return A pointer to an AST representation of the integer
 */
ast* new_integer(int value);

/**
 * Represents a boolean in the AST
 */
typedef struct {
    /** The type of the node (nodetype.BOOL) */
    nodetype type;
    /** The value of the boolean */
    int value;
} boolean;

/**
 * Creates a new boolean with the given value.
 *
 * @param value The value of the boolean expression
 * @return A pointer to an AST representation of the integer
 */
ast* new_boolean(int value);
 
/**
 * Represents a new object operation in the AST
 */
typedef struct {
    /** The type of the node (nodetype.NEW_OBJECT) */
    nodetype type;

    /** The id of the class of the object */
    identifier *class_id;
} new_object;

/**
 * Creates a new new_object with the given id.
 *
 * @param id The identifier of the class of the object
 * @return A pointer to an AST representation of the new object operation
 */
ast* new_new_object(identifier *class_id);

/**
 * The result from the parser. After calling yyparse(), this variable will hold 
 * the generated AST.
 */
ast* ast_parser_result;

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
    void (*on_identifier)(identifier *node, void *result);
    
    /** The callback for the addition binary operation */
    void (*on_addition)(binary_operation *node, void *result);
    
    /** The callback for the subtraction binary operation */
    void (*on_subtraction)(binary_operation *node, void *result);
    
    /** The callback for the division binary operation */
    void (*on_division)(binary_operation *node, void *result);

    /** The callback for the multiplication binary operation */
    void (*on_multiplication)(binary_operation *node, void *result);

    /** The callback for the logical and binary operation */
    void (*on_and)(binary_operation *node, void *result);

    /** The callback for the less than binary operation */
    void (*on_less_than)(binary_operation *node, void *result);
    
    /** The callback for the array lookup unary operation */
    void (*on_array_lookup)(unary_operation *node, void *result);

    /** The callback for the array length unary operation */
    void (*on_array_length)(unary_operation *node, void *result);
    
    /** The callback for the logical not unary operation */
    void (*on_not)(unary_operation *node, void *result);
   
    /** The callback for the new array unary operation */
    void (*on_new_array)(unary_operation *node, void *result);

    /** The callback for an integer */
    void (*on_integer)(integer *node, void *result);
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

#endif // __AST_H__
