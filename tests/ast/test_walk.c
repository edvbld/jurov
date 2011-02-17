#include "CuTest.h"
#include "ast.h"
#include "stddef.h"

void add(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_descend(op->left_operand, &left);
    ast_descend(op->right_operand, &right);
    *((int *) result) = left + right;
}

void sub(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_descend(op->left_operand, &left);
    ast_descend(op->right_operand, &right);
    *((int *) result) = left - right;
}

void mul(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_descend(op->left_operand, &left);
    ast_descend(op->right_operand, &right);
    *((int *) result) = left * right;
}

void div(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_descend(op->left_operand, &left);
    ast_descend(op->right_operand, &right);
    *((int *) result) = left / right;
}

void return_the_value(integer *i, void *result)
{
    *((int *) result) = i->value;
}

void should_call_the_correct_callbacks(CuTest *tc)
{
    int result;
    ast* tree;
    
    ast_callbacks callbacks;
    callbacks.on_addition = &add;
    callbacks.on_integer = &return_the_value;

    tree = new_binary_operation(ADDITION, new_integer(2), new_integer(3));
    ast_walk(tree, callbacks, &result);
    CuAssertIntEquals(tc, 5, result);
}

CuSuite* ast_test_walk()
{
    CuSuite *ast_walk = CuSuiteNew();

    SUITE_ADD_TEST(ast_walk, should_call_the_correct_callbacks);

    return ast_walk;
}

