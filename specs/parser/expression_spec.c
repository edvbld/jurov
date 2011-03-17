#include "string.h"
#include "expectations.h"
#include "parser.h"

int parse_expression(char *expression, ast **tree)
{
    int res = 0;
    char *main_function_opening =
        "class Main {\n"
        "public static void main(String[] args) {\n"
        "   System.out.println(";
    char *main_function_closening =
        ");}}";
    int length = strlen(main_function_opening) +
                 strlen(expression) +
                 strlen(main_function_closening) + 1;
    char *program = malloc(length);
    sprintf(program, "%s%s%s", main_function_opening,
                               expression,
                               main_function_closening);
    res = parse_string(program, tree);
    free(program);
    return res;
}

int get_expression(ast *tree, ast **exp)
{
    mj_ast_list *classes, *statements;
    mj_main_class *mc;
    mj_print *p;
    if(tree->type != MJ_AST_LIST)
        return -1;
    classes = (mj_ast_list *) tree;
    if(classes->list->size != 1)
        return -1;
    mc = classes->list->first->data;
    if(mc->type != MJ_MAIN_CLASS)
        return -1;
    statements = (mj_ast_list *) mc->statements;
    if(statements->list->size != 1)
        return -1;
    p = statements->list->first->data;
    if(p->type != MJ_PRINT)
        return -1;
    *exp = p->expression;
    return 0;
}

begin_example(exp_parser, should_handle_boolean_exp)
    ast *tree;
    mj_boolean *b;
    char *exp = "true";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &b))
    should_eq_int(MJ_BOOLEAN, b->type)
    should_eq_int(1, b->value)

    delete_parser(tree);

    exp = "false";
    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &b))
    should_eq_int(MJ_BOOLEAN, b->type)
    should_eq_int(0, b->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_integer_exp)
    ast *tree;
    mj_integer *i;
    char *exp = "9";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &i))
    should_eq_int(MJ_INTEGER, i->type)
    should_eq_int(9, i->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_this_exp)
    ast *tree;
    ast *t;
    char *exp = "this";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &t))
    should_eq_int(MJ_THIS, t->type)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_id_exp)
    ast *tree;
    mj_identifier *id;
    char *exp = "foo";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &id))
    should_eq_int(MJ_IDENTIFIER, id->type)
    should_eq_str("foo", id->name)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_new_object_exp)
    ast *tree;
    mj_new_object *o;
    char *exp = "new Foo()";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &o))
    should_eq_int(MJ_NEW_OBJECT, o->type)
    should_eq_str("Foo", o->class_id->name)

    delete_parser(tree);
end_example

begin_description(exp_parser)
    add_example(should_handle_boolean_exp)
    add_example(should_handle_integer_exp)
    add_example(should_handle_this_exp)
    add_example(should_handle_id_exp)
    add_example(should_handle_new_object_exp)
end_description
