#ifndef INCLUDE_jrv_ast_h__
#define INCLUDE_jrv_ast_h__
#include "list.h"

/**
 * Represents all different kinds of nodes that can exists in the AST
 */
typedef enum {
    /** An identifier struct */
    MJ_IDENTIFIER,
    /** Addition, a binary_operation struct */
    MJ_ADDITION,
    /** Subtraction, a binary_operation struct */
    MJ_SUBTRACTION,
    /** Division, a binary_operation struct */
    MJ_DIVISION,
    /** Multiplication, a binary_operation struct */
    MJ_MULTIPLICATION,
    /** Less than, a binary_operation struct */
    MJ_LESS_THAN,
    /** Array lookup, a binary_operation struct */
    MJ_ARRAY_LOOKUP,
    /** Array length, an unary_operation struct */
    MJ_ARRAY_LENGTH,
    /** Logical not, an unary_operation struct */
    MJ_NOT,
    /** New array, an unary_operation struct */
    MJ_NEW_ARRAY,
    /** An integer struct */
    MJ_INTEGER,
    /** A boolean struct */
    MJ_BOOLEAN,
    /** A new_object struct */
    MJ_NEW_OBJECT,
    /** Represents the this type */
    MJ_THIS,
    /** Represents an ast_list struct */
    MJ_AST_LIST,
    /** Represents a call struct */
    MJ_CALL,
    /** Represents a print struct */
    MJ_PRINT,
    /** Represents a main_class struct */
    MJ_MAIN_CLASS,
    /** Represents a class in MJ */
    MJ_CLASS,
    /** Represents a type in MJ */
    MJ_TYPE,
    /** Represents a variable declaration in MJ */
    MJ_VAR_DECL,
    /** Represents a method argument in MJ */
    MJ_METHOD_ARG,
    /** Represents a method declaration in MJ */
    MJ_METHOD_DECL,
    /** Represents the body of a method in MJ */
    MJ_METHOD_BODY,
    /** Represents an if expression in MJ */
    MJ_IF,
    /** Represents a while loop in MJ */
    MJ_WHILE,
    /** Represents an assignment in MJ */
    MJ_ASSIGNMENT
} nodetype;

typedef enum {
    /** Represents the integer type in MJ */
    MJ_TYPE_INTEGER,
    /** Represents the boolean type in MJ */
    MJ_TYPE_BOOLEAN,
    /** Represents the integer array type in MJ */
    MJ_TYPE_INT_ARRAY,
    /** Represents a user define type in MJ */
    MJ_TYPE_USER_DEFINED
} minijava_type;

/**
 * Represents an abstract syntax tree (AST). 
 */
typedef struct ast_ {
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
} mj_identifier;

/**
 * Creates a new identifier with the given name.
 *
 * @param[in] name The name of the identifier
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_identifier(char *name, ast **node);

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

} mj_binary_operation;

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
int new_mj_binary_operation(nodetype type, ast* left_operand, 
                            ast* right_operand, ast **node);

/**
 * Represents an unary operation (such as .length, new, not) node in the AST
 */
typedef struct {
    /** The type of the node */
    nodetype type;
    /** The argument to the operation */
    ast *operand;
} mj_unary_operation;

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
int new_mj_unary_operation(nodetype type, ast* operand, ast **node);

/**
 * Represents an integer node in the AST
 */
typedef struct {
    /** the type of the integer (nodetype.INTEGER) */
    nodetype type;
    /** the value of the integer */
    int value;
} mj_integer;

/**
 * Creates a new integer with the given value.
 *
 * @param[in] value The value of the integer
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_integer(int value, ast **node);

/**
 * Represents a boolean in the AST
 */
typedef struct {
    /** The type of the node (nodetype.BOOL) */
    nodetype type;
    /** The value of the boolean */
    int value;
} mj_boolean;

/**
 * Creates a new boolean with the given value.
 *
 * @param[in] value The value of the boolean expression
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_boolean(int value, ast **node);
 
/**
 * Represents a new object operation in the AST
 */
typedef struct {
    /** The type of the node (nodetype.NEW_OBJECT) */
    nodetype type;

    /** The id of the class of the object */
    mj_identifier *class_id;
} mj_new_object;

/**
 * Creates a new new_object with the given id.
 *
 * @param[in] id The identifier of the class of the object
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_new_object(ast *class_id, ast **node);

/**
 * This struct represents a list of ast elements
 */
typedef struct {
    /** The type of the node, this will be nodetype.AST_LIST */
    nodetype type;

    /** The actual list of ast nodes */
    list* list;
} mj_ast_list;

/**
 * Creates a new ast list with the given list.
 *
 * @param[in] list The list of of AST nodes
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_ast_list(list* list, ast **node);

/**
 * Creates an empty ast list and assigns it to node
 *
 * @param[out] The address of the pointer that will point to the empty list
 * @return An integer describing the result
 */
int empty_mj_ast_list(ast **node);

/**
 * Prepends an AST node to a ast_list
 *
 * @param[in] list The list of AST nodes
 * @param[in] node The AST node to prepend
 * @return An integer describing the result of the function
 */
int mj_ast_list_prepend(ast *list, ast *node);

/**
 * Represents a method call in the AST
 */
typedef struct {
    /** The type of the node, this will be nodetype.CALL */
    nodetype type;
    
    /* The expression that evaluates to the object to call the method on */
    ast* object;

    /* The id of the method to invoke */
    mj_identifier *method;

    /* The parameters to the method */
    mj_ast_list *parameters;
} mj_call;

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
int new_mj_call(ast *object, ast *method, mj_ast_list *parameters, ast **node);

/**
 * Creates a new ast struct with type nodetype.THIS
 *
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_this(ast **node);

/**
 * This struct represents a print statement
 */
typedef struct {
    /** The type of the node (nodetype.PRINT) */
    nodetype type;

    /** The expression that will evaluate to the print argument */
    ast *expression;
} mj_print;

/**
 * Creates a new print node with the given expression.
 *
 * @param[in] expression The expression which result will be printed
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_print(ast* expression, ast **node);

/**
 * Represents the main class of a MiniJava program
 */
typedef struct {
    /** The type of the node (nodetype.MJ_MAIN_CLASS) */
    nodetype type;

    /** The id of the main class */
    mj_identifier *class_id;

    /** The id of the String[] parameter to the main method */
    mj_identifier *parameter_id;

    /** The statement inside the main methods body */
    ast *statements;
} mj_main_class;

/**
 * Creates a new main_class node with the given parameters
 *
 * @param[in] class_id The identifier of the main class
 * @param[in] parameter_id The identifier of the String[] parameter to the main 
 *                     method
 * @param[in] statements The statements inside the main methods body
 * @param[out] node The addres of the pointer that will point at the result 
 *                  of the function
 * @return An integer describing the result of the function
 */
int new_mj_main_class(ast *class_id, ast *parameter_id, ast* statements, 
                      ast **node);


/**
 * Reprents a class in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_CLASS) */
    nodetype type;

    /** The identifier (name) of the class */
    mj_identifier *id;

    /** A list of the variable declarations */
    ast *var_declarations;

    /** A list of the methods declarations */
    ast *method_declarations;
} mj_class;

/**
 * Creates new class node with the given parameters
 *
 * @param[in] id The id (name) of the class
 * @param[in] var_declarations A list of the variable declarations of the class
 * @param[in] method_declarations A list of the method declarations of the class
 * @param[out] node The address of the pointer that mj_class node will be 
 *                  assigned to
 * @return An integer describing the result
 */
int new_mj_class(ast *id, ast *var_declarations, 
                 ast *method_declarations, ast **node);

/**
 * Represents a type in the MiniJava language, such as int or boolean
 */
typedef struct {
    /** The type of the node (MJ_TYPE) */
    nodetype type;

    /** The MiniJava type */
    minijava_type mj_type;

    /** The identifier if it's a user defined type */
    mj_identifier *id;
} mj_type;


/**
 * Creates a new type in the MiniJava language
 *
 * @parameter[in] type The type to construct
 * @parameter[in] id The id if it's a user defined type
 * @parameter[out] node The address of the pointer that the created node 
 *                      pointer will be assigned to
 * @return The result of the function
 */
int new_mj_type(minijava_type type, ast *identifier, ast **node);

/**
 * Represents a variable declaration in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_VAR_DECL) */
    nodetype type;

    /** The MiniJava type of the variable */
    mj_type *mj_type;

    /** The identifier of the variable */
    mj_identifier *id;
} mj_var_decl;

/**
 * Creates a new variable declaration in the MiniJava language
 *
 * @param[in] type The type of the variable
 * @param[in] id The identifier of the variable
 * @param[out] node The address of the pointer that the created node 
 *                  will be assigned to
 * @return The result of the function
 */
int new_mj_var_decl(ast *type, ast *id, ast **node);

/**
 * Represents an argument to a method in MiniJava
 */
typedef struct {
    /** The type of the node (MJ_METHOD_ARG) */
    nodetype type;

    /** The type of the argument */
    mj_type *mj_type;

    /** The identifier (name) of the argument */
    mj_identifier *id;
} mj_method_arg;

/**
 * Creates a new method argument in the MiniJava language
 *
 * @param[in] mj_type The MiniJava type of the argument
 * @param[in] id The identifier of the argument
 * @param[out] node The address of the pointer that the newly created 
 *                  mj_method_arg will be assigned to
 * @return The result of the function
 */
int new_mj_method_arg(ast *type, ast *id, ast **node);

/**
 * Reperesents a method body in MJ
 */
typedef struct {
    /** The type of the node */
    nodetype type;

    /** The variable declarations in the method body */
    mj_ast_list *var_declarations;

    /** The statements in the method */
    mj_ast_list *statements;
} mj_method_body;

/**
 * Creates a new method body in the MiniJava language
 *
 * @param[in] var_declarations The variable declarations in the method body
 * @param[in] statements The statements in the method body
 * @param[out] node The address of the pointer that the result will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_method_body(ast *var_declarations, ast *statements, ast **node);

/**
 * Adds a statement to a method body
 *
 * @param[in] statement The statement to add to the method_body
 * @param[in] method_body The method_body to add the statement to
 * @return The result of the function
 */
int mj_method_body_add_statement(ast *statement, ast *method_body);

/**
 * Adds a variable declaration to a method body
 *
 * @param[in] var_decl The variable declaration to add
 * @param[in] method_body The method to add the variable declaration to
 * @return The result of the function
 */
int mj_method_body_add_var_decl(ast *var_decl, ast *method_body);

/**
 * Represents a method declaration and definition in the MJ language
 */
typedef struct {
    /** The type of the node (MJ_METHOD_DECL) */
    nodetype type;

    /** The return type of the method */
    mj_type *return_type;

    /** The identifier (name) of the method */
    mj_identifier *id;
    
    /** The argument list */
    mj_ast_list *arguments;

    /** The body of the method */
    mj_method_body *body;

    /** The expression yielding the return value */
    ast *return_expression;
} mj_method_decl;

/**
 * Creates a new method declaration in MJ
 *
 * @param[in] return_type The MJ type the method returns
 * @param[in] id The identifier (name) of the method
 * @param[in] arguments A list of the arguments to the method
 * @param[in] var_declarations A list of the variable declaration in the 
 *                             method body
 * @param[in] statements A list of the statements in the method body
 * @param[in] return_expression The expression yielding the return value
 * @param[out] node The address of the pointer the created node will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_method_decl(ast *return_type, ast *id, ast *arguments,
                       ast *body, ast *return_expression, ast **node);

/**
 * Represents an if-else expression in MiniJava
 */
typedef struct {
    /** The type of the node (MJ_IF) */
    nodetype type;

    /** The expression to evaulate to a boolean value */
    ast *condition;

    /** The statement(s) to execute if the condition is true */
    ast *true_statement;

    /** The statement(s) to execute if the condition is false */
    ast *false_statement;
} mj_if;

/**
 * Creates a new if-else statement in the MiniJava language
 *
 * @param[in] condition The expression to evaluate as the condition for the 
 *                      if statement
 * @param[in] true_statement The statement(s) to run if the condition is true
 * @param[in] false_statement The statement(s) to run if the condition is false
 * @param[out] node The address of the pointer that the pointer to the created 
 *                  node will be assigned to
 * @return The result of the function
 */
int new_mj_if(ast *condition, ast *true_statement, ast *false_statement, 
              ast **node);
    
/**
 * Reprents a while loop in the MiniJava programming language
 */
typedef struct {
    /** The type of the node (MJ_WHILE) */
    nodetype type;

    /** The condition of the while loop */
    ast *condition;

    /** The statement of the while loop */
    ast *statement;
} mj_while;

/**
 * Creates a new while loop in the MiniJava language
 *
 * @param[in] condition The condition for the while loop
 * @param[in] statement The statement in the body of the while loop
 * @param[out] node The address of the pointer that the result will be 
 *                  assigned to
 * @return The result of the function
 */
int new_mj_while(ast *condition, ast *statement, ast **node);

/**
 * Represents an assignment in the MiniJava language
 */
typedef struct {
    /** The type of the node (MJ_ASSIGNMENT) */
    nodetype type;

    /** The identifier that gets assigned */
    mj_identifier *id;

    /** The expression to assing to the indentifier */
    ast *expression;
} mj_assignment;

/**
 * Creates a new assignment statement in MiniJava
 *
 * @param[in] id The identifier that gets assigned
 * @param[in] expression The expression that yields the value to assign to 
 *                       the identifier
 * @param[out] node The address of the pointer to assign the result to
 * @return The result of the function
 */
int new_mj_assignment(ast *id, ast *expression, ast **node);

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
    void (*on_mj_identifier)(mj_identifier *node, void *result);
    
    /** The callback for the addition binary operation */
    void (*on_mj_addition)(mj_binary_operation *node, void *result);
    
    /** The callback for the subtraction binary operation */
    void (*on_mj_subtraction)(mj_binary_operation *node, void *result);
    
    /** The callback for the division binary operation */
    void (*on_mj_division)(mj_binary_operation *node, void *result);

    /** The callback for the multiplication binary operation */
    void (*on_mj_multiplication)(mj_binary_operation *node, void *result);

    /** The callback for the logical and binary operation */
    void (*on_mj_and)(mj_binary_operation *node, void *result);

    /** The callback for the less than binary operation */
    void (*on_mj_less_than)(mj_binary_operation *node, void *result);
    
    /** The callback for the array lookup unary operation */
    void (*on_mj_array_lookup)(mj_binary_operation *node, void *result);

    /** The callback for the array length unary operation */
    void (*on_mj_array_length)(mj_unary_operation *node, void *result);
    
    /** The callback for the logical not unary operation */
    void (*on_mj_not)(mj_unary_operation *node, void *result);
   
    /** The callback for the new array unary operation */
    void (*on_mj_new_array)(mj_unary_operation *node, void *result);

    /** The callback for an integer */
    void (*on_mj_integer)(mj_integer *node, void *result);

    /** The callback for a this object */
    void (*on_mj_this)(ast *node, void *result);

    /** The callback for a boolean */
    void (*on_mj_boolean)(mj_boolean *node, void *result);

    /** The callback for an ast_list */
    void (*on_mj_ast_list)(mj_ast_list *node, void *result);

    /** The callback for a new_object operation */
    void (*on_mj_new_object)(mj_new_object *node, void *result);

    /** The callback for a call operation */
    void (*on_mj_call)(mj_call *node, void *result);

    /** The callback for a print statement */
    void (*on_mj_print)(mj_print *node, void *result);

    /** The callback for a main_class */
    void (*on_mj_main_class)(mj_main_class *node, void *result);

    /** The callback for a class */
    void (*on_mj_class)(mj_class *node, void *result);

    /** The callback for a type */
    void (*on_mj_type)(mj_type *node, void *result);
    
    /** The callback for a variable declaration */
    void (*on_mj_var_decl)(mj_var_decl *node, void *result);

    /** The callback for a method argument */
    void (*on_mj_method_arg)(mj_method_arg *node, void *result);

    /** The callback for a method body */
    void (*on_mj_method_body)(mj_method_body *node, void *result);

    /** The callback for a method declaration */
    void (*on_mj_method_decl)(mj_method_decl *node, void *result);

    /** The callback for an if-else statement */
    void (*on_mj_if)(mj_if *node, void *result);

    /** The callback for a while statement */
    void (*on_mj_while)(mj_while *node, void *result);
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

/**
 * Deletes an AST and all the nodes in the AST. 
 * NOTE: it also frees the char* in an mj_identifier, so make sure that you 
 * have copied this pointer if you use it elsewhere.
 *
 * @parameter tree The tree to delete
 */
void delete_ast(ast* tree);

#endif /* INCLUDE_jrv_ast_h__ */
