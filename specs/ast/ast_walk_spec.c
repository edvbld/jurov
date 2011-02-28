#include "expectations.h"
#include "ast.h"

static void on_add(mj_binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left + right;
}

static void on_sub(mj_binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left - right;
}

static void on_mul(mj_binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left * right;
}

static void on_div(mj_binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left / right;
}

static void on_int(mj_integer *i, void *result)
{
    *((int *) result) = i->value;
}

begin_example(ast_walk, should_handle_addition_and_integer_nodes)
    int result;
    ast *tree;
    ast *two;
    ast *three;
    
    ast_callbacks callbacks;
    callbacks.on_mj_addition = &on_add;
    callbacks.on_mj_integer = &on_int;
    
    should_pass(new_mj_integer(2, &two))
    should_pass(new_mj_integer(3, &three))
    should_pass(new_mj_binary_operation(MJ_ADDITION, two, three, &tree))
    ast_walk(tree, callbacks, &result);
    should_eq_int(5, result)

    free(two);
    free(three);
    free(tree);
end_example

begin_example(ast_walk, should_handle_all_arithmetic_nodes)
    int result = 0;
    ast *op0;
    ast *op1;
    ast *op2;
    ast *op3;
    ast *op4;

    ast *one;
    ast *five;
    ast *two;
    ast *ten;
    
    ast_callbacks callbacks;
    callbacks.on_mj_addition = &on_add;
    callbacks.on_mj_subtraction = &on_sub;
    callbacks.on_mj_multiplication = &on_mul;
    callbacks.on_mj_division = &on_div;
    callbacks.on_mj_integer = &on_int;

    /* (+ (* (- 5 2) (+ 1 1)) (/ 10 2)) */
    should_pass(new_mj_integer(1, &one))
    should_pass(new_mj_integer(5, &five))
    should_pass(new_mj_integer(2, &two))
    should_pass(new_mj_integer(10, &ten))
    should_pass(new_mj_binary_operation(MJ_ADDITION, one, one, &op4))
    should_pass(new_mj_binary_operation(MJ_SUBTRACTION, five, two, &op3)) 
    should_pass(new_mj_binary_operation(MJ_DIVISION, ten, two, &op2))
    should_pass(new_mj_binary_operation(MJ_MULTIPLICATION, op3, op4, &op1))
    should_pass(new_mj_binary_operation(MJ_ADDITION, op1, op2, &op0))
    ast_walk(op0, callbacks, &result);
    should_eq_int(11, result)

    free(one);
    free(five);
    free(two);
    free(ten);
    free(op4);
    free(op3);
    free(op2);
    free(op1);
    free(op0);
end_example

begin_description(ast_walk)
    add_example(should_handle_addition_and_integer_nodes)
    add_example(should_handle_all_arithmetic_nodes)
end_description
