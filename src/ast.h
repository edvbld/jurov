#ifndef INCLUDE_jrv_ast_h__
#define INCLUDE_jrv_ast_h__
#include "list.h"

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
    NEW_OBJECT,
    /** Represents the this type */
    THIS_OBJECT,
    /** Represents an ast_list struct */
    AST_LIST,
    /** Represents a call struct */
    CALL,
    /** Represensts a print struct */
    SYSTEM_OUT_PRINT,
    /** Represents a main_class struct */
    MAIN_CLASS
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
 * @param[in] name The name of the identifier
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_identifier(char *name, ast **node);

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
 * @param[in] type The type of the operation
 * @param[in] left_operand The left operand of the expression
 * @param[in] right_operand The right operand of the expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_binary_operation(nodetype type, ast* left_operand, ast* right_operand, 
                         ast **node);

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
 * @param[in] type The type of the operation
 * @param[in] operand The operand of the expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_unary_operation(nodetype type, ast* operand, ast **node);

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
 * @param[in] value The value of the integer
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_integer(int value, ast **node);

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
 * @param[in] value The value of the boolean expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_boolean(int value, ast **node);
 
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
 * @param[in] id The identifier of the class of the object
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_new_object(ast *class_id, ast **node);

/**
 * This struct represents a list of ast elements
 */
typedef struct {
    /** The type of the node, this will be nodetype.AST_LIST */
    nodetype type;

    /** The actual list of ast nodes */
    list* list;
} ast_list;

/**
 * Creates a new ast list with the given list.
 *
 * @param[in] list The list of of AST nodes
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_ast_list(list* list, ast **node);

/**
 * Represents a method call in the AST
 */
typedef struct {
    /** The type of the node, this will be nodetype.CALL */
    nodetype type;
    
    /* The expression that evaluates to the object to call the method on */
    ast* object;

    /* The id of the method to invoke */
    identifier *method;

    /* The parameters to the method */
    ast_list *parameters;
} call;

/**
 * Creates a new call node for the AST with the given parameters.
 *
 * @param[in] object The object to call the method on
 * @param[in] method_id The id of the method to call
 * @param[in] parameters The parameters for the method call
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_call(ast *object, ast *method, ast_list *parameters, ast **node);

/**
 * Creates a new ast struct with type nodetype.THIS
 *
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_this(ast **node);

/**
 * This struct represents a print statement
 */
typedef struct {
    /** The type of the node (nodetype.PRINT) */
    nodetype type;

    /** The expression that will evaluate to the print argument */
    ast *expression;
} print;

/**
 * Creates a new print node with the given expression.
 *
 * @param[in] expression The expression which result will be printed
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_print(ast* expression, ast **node);

/**
 * Represents the main class of a MiniJava program
 */
typedef struct {
    /** The type of the node (nodetype.PRINT) */
    nodetype type;

    /** The id of the main class */
    identifier *class_id;

    /** The id of the String[] parameter to the main method */
    identifier *parameter_id;

    /** The statement inside the main methods body */
    ast *statement;
} main_class;

/**
 * Creates a new main_class node with the given parameters
 *
 * @param[in] class_id The identifier of the main class
 * @param[in] parameter_id The identifier of the String[] parameter to the main 
 *                     method
 * @param[in] statement The statement inside the main methods body
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_main_class(ast *class_id, ast *parameter_id, ast* statement, 
                   ast **node);

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

#endif /* INCLUDE_jrv_ast_h__ */
