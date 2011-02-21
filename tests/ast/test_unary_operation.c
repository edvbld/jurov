#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static unary_operation* create(nodetype type, ast *operand)
{
    return (unary_operation *) new_unary_operation(type, operand);
}

void should_have_unary_operation_as_type(CuTest *tc)
{
    unary_operation *node = create(NOT, NULL);
    CuAssertIntEquals(tc, NOT, node->type);
    free(node);
}

void should_have_the_given_operand(CuTest *tc)
{
    ast *i = new_integer(5); // there is no semantics, just syntax
    unary_operation *node = create(NOT, i);
    CuAssertPtrEquals(tc, i, node->operand);
    free(i);
    free(node);
}

CuSuite* ast_test_unary_operation()
{
    CuSuite *unary_operation = CuSuiteNew();

    SUITE_ADD_TEST(unary_operation, should_have_unary_operation_as_type);
    SUITE_ADD_TEST(unary_operation, should_have_the_given_operand);

    return unary_operation;
}


