#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static integer* create(int value)
{
    return (integer *) new_integer(value);
}

void should_have_integer_as_type(CuTest *tc)
{
    integer *node = create(0);
    CuAssertIntEquals(tc, INTEGER, node->type);
    free(node);
}

void should_have_the_give_value(CuTest *tc)
{
    int value = 5;
    integer *node = create(value);
    CuAssertIntEquals(tc, value, node->value);
    free(node);
}

CuSuite* ast_test_integer()
{
    CuSuite *integer = CuSuiteNew();

    SUITE_ADD_TEST(integer, should_have_integer_as_type);
    SUITE_ADD_TEST(integer, should_have_the_give_value);

    return integer;
}

