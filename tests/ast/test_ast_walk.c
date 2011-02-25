#include "stddef.h"
#include "CuTest.h"
#include "ast.h"
#include "errors.h"

void add(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left + right;
}

void sub(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left - right;
}

void mul(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left * right;
}

void div(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left / right;
}

void return_the_value(integer *i, void *result)
{
    *((int *) result) = i->value;
}

void should_handle_addition_and_integer_nodes(CuTest *tc)
{
    int result;
    ast* tree;
    
    ast_callbacks callbacks;
    callbacks.on_addition = &add;
    callbacks.on_integer = &return_the_value;

    int res = new_binary_operation(ADDITION, new_integer(2), new_integer(3), 
                                   &tree);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
    ast_walk(tree, callbacks, &result);
    CuAssertIntEquals(tc, 5, result);
}

void should_handle_all_arithmetic_nodes(CuTest *tc)
{
    int result = 0;
    ast *op0;
    ast *op1;
    ast *op2;
    ast *op3;
    ast *op4;
    
    ast_callbacks callbacks;
    callbacks.on_addition = &add;
    callbacks.on_subtraction = &sub;
    callbacks.on_multiplication = &mul;
    callbacks.on_division = &div;
    callbacks.on_integer = &return_the_value;

    /* (+ (* (- 5 2) (+ 1 1)) (/ 10 2)) */
    new_binary_operation(ADDITION, new_integer(1), new_integer(1), &op4);
    new_binary_operation(SUBTRACTION, new_integer(5), new_integer(2), &op3);
    new_binary_operation(DIVISION, new_integer(10), new_integer(2), &op2);
    new_binary_operation(MULTIPLICATION, op3, op4, &op1);
    new_binary_operation(ADDITION, op1, op2, &op0);

    ast_walk(op0, callbacks, &result);
    CuAssertIntEquals(tc, 11, result);
}

CuSuite* ast_test_ast_walk()
{
    CuSuite *ast_walk = CuSuiteNew();

    SUITE_ADD_TEST(ast_walk, should_handle_addition_and_integer_nodes);
    SUITE_ADD_TEST(ast_walk, should_handle_all_arithmetic_nodes);

    return ast_walk;
}

