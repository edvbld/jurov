#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static boolean* create(int value)
{
    return (boolean *) new_boolean(value);
}

void should_have_boolean_as_type(CuTest *tc)
{
    boolean *node = create(0);
    CuAssertIntEquals(tc, BOOL, node->type);
    free(node);
}

void should_have_the_given_parameter_as_value(CuTest *tc)
{
    int value = 0;
    boolean *node = create(value);
    CuAssertIntEquals(tc, value, node->value);
    free(node);
}

CuSuite* ast_test_boolean()
{
    CuSuite *boolean = CuSuiteNew();

    SUITE_ADD_TEST(boolean, should_have_boolean_as_type);
    SUITE_ADD_TEST(boolean, should_have_the_given_parameter_as_value);

    return boolean;
}


