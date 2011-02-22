#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static ast* create()
{
    return new_this();
}

void should_have_this_object_as_type(CuTest *tc)
{
    ast *node = create();
    CuAssertIntEquals(tc, THIS_OBJECT, node->type);
    free(node);
}

CuSuite* ast_test_this()
{
    CuSuite *this = CuSuiteNew();

    SUITE_ADD_TEST(this, should_have_this_object_as_type);

    return this;
}



