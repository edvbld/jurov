#ifndef INCLUDE_jrv_ast2_h__
#define INCLUDE_jrv_ast2_h__

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
    /** Logical and, a binary opeartion */
    MJ_AND,
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
    MJ_ASSIGNMENT,
    /** Represents an array assignment in MJ */
    MJ_ARRAY_ASSIGNMENT
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
 * Deletes an AST and all the nodes in the AST. 
 * NOTE: it also frees the char* in an mj_identifier, so make sure that you 
 * have copied this pointer if you use it elsewhere.
 *
 * @parameter tree The tree to delete
 */
void delete_ast(ast* tree);

#endif /* INCLUDE_jrv_ast2_h__ */
