#include "string.h"
#include "expectations.h"
#include "parser.h"
#include "ast.h"

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

begin_example(exp_parser, should_handle_new_array_exp)
    ast *tree;
    mj_unary_operation *na;
    mj_integer *i;
    char *exp = "new int [5]";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &na))
    should_eq_int(MJ_NEW_ARRAY, na->type)
    should_eq_int(MJ_INTEGER, na->operand->type)
    i = (mj_integer *) na->operand;
    should_eq_int(5, i->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_not_exp)
    ast *tree;
    mj_unary_operation *not;
    mj_boolean *b;
    char *exp = "!true";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &not))
    should_eq_int(MJ_NOT, not->type)
    should_eq_int(MJ_BOOLEAN, not->operand->type)
    b = (mj_boolean *) not->operand;
    should_eq_int(1, b->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_parenthesized_exp)
    ast *tree;
    mj_identifier *id;
    char *exp = "(foo)";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &id))
    should_eq_int(MJ_IDENTIFIER, id->type)
    should_eq_str("foo", id->name)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_length_exp)
    ast *tree;
    mj_unary_operation *length;
    mj_identifier *id;
    char *exp = "foo.length";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &length))
    should_eq_int(MJ_ARRAY_LENGTH, length->type)
    should_eq_int(MJ_IDENTIFIER, length->operand->type)
    id = (mj_identifier *) length->operand;
    should_eq_str("foo", id->name);

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_array_lookup)
    ast *tree;
    mj_binary_operation *b;
    mj_identifier *id;
    mj_integer *num;
    char *exp = "foo[3]";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &b))
    should_eq_int(MJ_ARRAY_LOOKUP, b->type)
    should_eq_int(MJ_IDENTIFIER, b->left_operand->type)
    id = (mj_identifier *) b->left_operand;
    should_eq_str("foo", id->name)
    should_eq_int(MJ_INTEGER, b->right_operand->type)
    num = (mj_integer *) b->right_operand;
    should_eq_int(3, num->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_logical_and)
    ast *tree;
    mj_binary_operation *and;
    mj_boolean *lhs, *rhs;
    char *exp = "true && false";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &and))
    should_eq_int(MJ_AND, and->type)
    should_eq_int(MJ_BOOLEAN, and->left_operand->type)
    lhs = (mj_boolean *) and->left_operand;
    should_eq_int(1, lhs->value)
    should_eq_int(MJ_BOOLEAN, and->right_operand->type)
    rhs = (mj_boolean *) and->right_operand;
    should_eq_int(0, rhs->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_addition)
    ast *tree;
    mj_binary_operation *add;
    mj_integer *lhs, *rhs;
    char *exp = "1 + 2";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &add))
    should_eq_int(MJ_ADDITION, add->type)
    should_eq_int(MJ_INTEGER, add->left_operand->type)
    lhs = (mj_integer *) add->left_operand;
    should_eq_int(1, lhs->value)
    should_eq_int(MJ_INTEGER, add->right_operand->type)
    rhs = (mj_integer *) add->right_operand;
    should_eq_int(2, rhs->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_subtraction)
    ast *tree;
    mj_binary_operation *sub;
    mj_integer *lhs, *rhs;
    char *exp = "1 - 2";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &sub))
    should_eq_int(MJ_SUBTRACTION, sub->type)
    should_eq_int(MJ_INTEGER, sub->left_operand->type)
    lhs = (mj_integer *) sub->left_operand;
    should_eq_int(1, lhs->value)
    should_eq_int(MJ_INTEGER, sub->right_operand->type)
    rhs = (mj_integer *) sub->right_operand;
    should_eq_int(2, rhs->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_multiplication)
    ast *tree;
    mj_binary_operation *mul;
    mj_integer *lhs, *rhs;
    char *exp = "1 * 2";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &mul))
    should_eq_int(MJ_MULTIPLICATION, mul->type)
    should_eq_int(MJ_INTEGER, mul->left_operand->type)
    lhs = (mj_integer *) mul->left_operand;
    should_eq_int(1, lhs->value)
    should_eq_int(MJ_INTEGER, mul->right_operand->type)
    rhs = (mj_integer *) mul->right_operand;
    should_eq_int(2, rhs->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_less_than)
    ast *tree;
    mj_binary_operation *lt;
    mj_integer *lhs, *rhs;
    char *exp = "1 < 2";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &lt))
    should_eq_int(MJ_LESS_THAN, lt->type)
    should_eq_int(MJ_INTEGER, lt->left_operand->type)
    lhs = (mj_integer *) lt->left_operand;
    should_eq_int(1, lhs->value)
    should_eq_int(MJ_INTEGER, lt->right_operand->type)
    rhs = (mj_integer *) lt->right_operand;
    should_eq_int(2, rhs->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_call_exp)
    ast *tree;
    mj_call *call;
    mj_identifier *obj;
    mj_integer *first, *snd;
    mj_identifier *method;
    char *exp = "foo.double(1,2)";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &call))
    should_eq_int(MJ_CALL, call->type)
    should_eq_int(MJ_IDENTIFIER, call->object->type)
    obj = (mj_identifier *) call->object;
    should_eq_str("foo", obj->name)
    should_eq_int(MJ_IDENTIFIER, call->method->type)
    method = (mj_identifier *) call->method;
    should_eq_str("double", method->name);
    should_eq_int(MJ_AST_LIST, call->parameters->type)
    should_eq_int(2, call->parameters->list->size)
    first = call->parameters->list->first->data;
    should_eq_int(1, first->value)
    snd = call->parameters->list->last->data;
    should_eq_int(2, snd->value)

    delete_parser(tree);
end_example

begin_example(exp_parser, should_handle_new_object_and_method_call)
    ast *tree;
    mj_call *call;
    mj_new_object *fac;
    mj_integer *arg;
    char *exp = "new Fac().ComputeFac(10)";

    should_pass(parse_expression(exp, &tree))
    should_pass(get_expression(tree, (ast **) &call))
    should_eq_int(MJ_CALL, call->type)
    should_eq_int(MJ_NEW_OBJECT, call->object->type)
    fac = (mj_new_object *) call->object;
    should_eq_str("Fac", fac->class_id->name)
    should_eq_str("ComputeFac", call->method->name)
    should_eq_int(1, call->parameters->list->size)
    arg = call->parameters->list->first->data;
    should_eq_int(MJ_INTEGER, arg->type)
    should_eq_int(10, arg->value)


    delete_parser(tree);
end_example

begin_description(exp_parser)
    add_example(should_handle_boolean_exp)
    add_example(should_handle_integer_exp)
    add_example(should_handle_this_exp)
    add_example(should_handle_id_exp)
    add_example(should_handle_new_object_exp)
    add_example(should_handle_new_array_exp)
    add_example(should_handle_not_exp)
    add_example(should_handle_parenthesized_exp)
    add_example(should_handle_length_exp)
    add_example(should_handle_array_lookup)
    add_example(should_handle_logical_and)
    add_example(should_handle_addition)
    add_example(should_handle_subtraction)
    add_example(should_handle_multiplication)
    add_example(should_handle_less_than)
    add_example(should_handle_call_exp)
    add_example(should_handle_new_object_and_method_call)
end_description
