#include "stddef.h"
#include "stdlib.h"
#include "CuTest.h"
#include "ast.h"
#include "errors.h"

void should_have_the_given_type(CuTest *tc)
{
    binary_operation *op;
    int res = new_binary_operation(ADDITION, NULL, NULL, (ast **) &op);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
    CuAssertIntEquals(tc, ADDITION, op->type);
    free(op);
}

void should_have_the_given_operands(CuTest *tc)
{
    ast *left = new_integer(5);
    ast *right = new_integer(7);
    binary_operation *op;
    int res = new_binary_operation(ADDITION, left, right, (ast **) &op);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
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

