#include "stddef.h"
#include "errors.h"
#include "utils.h"
#include "ast.h"

int invalid_type(ast **node)
{
    *node = NULL;
    return JRV_INVALID_TYPE;
}

int is_of_type(nodetype type, ast *node)
{
    if(node == NULL) {
        return -1;
    }
    return node->type == type;
}

static void del_mj_this(ast *node, void *p)
{
    delete_mj_this(node);
}

static void del_mj_boolean(mj_boolean *node, void *p)
{
    delete_mj_boolean(node);
}

static void del_mj_integer(mj_integer *node, void *p)
{
    delete_mj_integer(node);
}

static void del_mj_identifier(mj_identifier *node, void *p)
{
    delete_mj_identifier(node);
}

static void del_mj_unary_operation(mj_unary_operation *node, void *p)
{
    delete_mj_unary_operation(node);
}

static void del_mj_binary_operation(mj_binary_operation *node, void *p)
{
    delete_mj_binary_operation(node);
}

static void del_mj_new_object(mj_new_object *node, void *p)
{
    delete_mj_new_object(node);
}
static void del_mj_ast_list(mj_ast_list *list, void *p)
{
    delete_mj_ast_list(list);
}

static void del_mj_call(mj_call *node, void *p)
{
    delete_mj_call(node);
}

static void del_mj_print(mj_print *node, void *p)
{
    delete_mj_print(node);
}

static void del_mj_main_class(mj_main_class *node, void *p)
{
    delete_mj_main_class(node);
}

static void del_mj_class(mj_class *node, void *p)
{
    delete_mj_class(node);
}

static void del_mj_type(mj_type *node, void *p)
{
    delete_mj_type(node);
}

static void del_mj_var_decl(mj_var_decl *node, void *p)
{
    delete_mj_var_decl(node);
}

static void del_mj_method_arg(mj_method_arg *node, void *p)
{
    delete_mj_method_arg(node);
}

static void del_mj_method_body(mj_method_body *node, void *p)
{
    delete_mj_method_body(node);
}

static void del_mj_method_decl(mj_method_decl *node, void *p)
{
    delete_mj_method_decl(node);
}

static void del_mj_if(mj_if *node, void *p)
{
    delete_mj_if(node);
}

static void del_mj_while(mj_while *node, void *p)
{
    delete_mj_while(node);
}

static void del_mj_assignment(mj_assignment *node, void *p)
{
    delete_mj_assignment(node);
}

static void del_mj_array_assignment(mj_array_assignment *node, void *p)
{
    delete_mj_array_assignment(node);
}

void delete_ast(ast *tree)
{
    ast_callbacks callbacks;
    callbacks.on_mj_identifier = &del_mj_identifier;
    callbacks.on_mj_addition = &del_mj_binary_operation;
    callbacks.on_mj_subtraction = &del_mj_binary_operation;
    callbacks.on_mj_division = &del_mj_binary_operation;
    callbacks.on_mj_multiplication = &del_mj_binary_operation;
    callbacks.on_mj_and = &del_mj_binary_operation;
    callbacks.on_mj_less_than = &del_mj_binary_operation;
    callbacks.on_mj_array_lookup = &del_mj_binary_operation;
    callbacks.on_mj_array_length = &del_mj_unary_operation;
    callbacks.on_mj_not = &del_mj_unary_operation;
    callbacks.on_mj_new_array = &del_mj_unary_operation;
    callbacks.on_mj_integer = &del_mj_integer;
    callbacks.on_mj_this = &del_mj_this;
    callbacks.on_mj_boolean = &del_mj_boolean;
    callbacks.on_mj_ast_list = &del_mj_ast_list;
    callbacks.on_mj_new_object = &del_mj_new_object;
    callbacks.on_mj_call = &del_mj_call;
    callbacks.on_mj_print = &del_mj_print;
    callbacks.on_mj_main_class = &del_mj_main_class;
    callbacks.on_mj_class = &del_mj_class;
    callbacks.on_mj_type = &del_mj_type;
    callbacks.on_mj_var_decl = &del_mj_var_decl;
    callbacks.on_mj_method_arg = &del_mj_method_arg;
    callbacks.on_mj_method_body = &del_mj_method_body;
    callbacks.on_mj_method_decl = &del_mj_method_decl;
    callbacks.on_mj_if = &del_mj_if;
    callbacks.on_mj_while = &del_mj_while;
    callbacks.on_mj_assignment = &del_mj_assignment;
    callbacks.on_mj_array_assignment = &del_mj_array_assignment;
    ast_walk(tree, callbacks, NULL);
}

char *ast_format(ast *tree)
{
    return "";
}
