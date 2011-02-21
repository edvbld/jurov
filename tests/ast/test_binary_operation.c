#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static binary_operation* create(nodetype type, ast* left, ast* right)
{
    return (binary_operation *) new_binary_operation(type, left, right);
}

void should_have_the_given_type(CuTest *tc)
{
    binary_operation *op = create(ADDITION, NULL, NULL);
    CuAssertIntEquals(tc, ADDITION, op->type);
    free(op);
}

void should_have_the_given_operands(CuTest *tc)
{
    ast *left = new_integer(5);
    ast *right = new_integer(7);
    binary_operation *op = create(ADDITION, left, right);
    CuAssertPtrEquals(tc, left, op->left_operand);
    CuAssertPtrEquals(tc, right, op->right_operand);
    free(left);
    free(right);
    free(op);
}

CuSuite* ast_test_binary_operation()
{
    CuSuite *binary_operation = CuSuiteNew();

    SUITE_ADD_TEST(binary_operation, should_have_the_given_type);
    SUITE_ADD_TEST(binary_operation, should_have_the_given_operands);

    return binary_operation;
}

