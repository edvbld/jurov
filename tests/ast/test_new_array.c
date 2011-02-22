#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static new_array* create(ast *exp)
{
    return (new_array *) new_new_array(exp);
}

void should_have_new_array_as_type(CuTest *tc)
{
    new_array *node = create(NULL);
    CuAssertIntEquals(tc, NEW_ARRAY, node->type);
    free(node);
}

void should_have_the_given_size_expression_as_member(CuTest *tc)
{
    ast *size_exp = new_integer(4);
    new_array *node = create(size_exp);
    CuAssertPtrEquals(tc, size_exp, node->size_expression);
    free(size_exp);
    free(node);
}

CuSuite* ast_test_new_array()
{
    CuSuite *new_array = CuSuiteNew();

    SUITE_ADD_TEST(new_array, should_have_new_array_as_type);
    SUITE_ADD_TEST(new_array, should_have_the_given_size_expression_as_member);

    return new_array;
}
