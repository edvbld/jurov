#include "stddef.h"
#include "stdlib.h"
#include "CuTest.h"
#include "ast.h"
#include "errors.h"

static identifier* create(CuTest *tc, char *name)
{
    ast *id;
    int res = new_identifier(name, &id);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
    return (identifier *) id;
}

void should_assert_that_name_is_not_empty(CuTest *tc)
{
    ast *id;
    int ret = new_identifier("", &id);
    CuAssertIntEquals(tc, JRV_INVALID_STRING, ret);
}

void should_have_an_id_member(CuTest *tc)
{
    char *name = "name";
    identifier *node = create(tc, name);
    CuAssertStrEquals(tc, name, node->name);
    free(node);
}

void should_have_identifier_as_type(CuTest *tc)
{
    identifier *node = create(tc, "name");
    CuAssertIntEquals(tc, IDENTIFIER, node->type);
    free(node);
}

CuSuite* ast_test_identifier()
{
    CuSuite *identifier = CuSuiteNew();

    SUITE_ADD_TEST(identifier, should_have_an_id_member);
    SUITE_ADD_TEST(identifier, should_have_identifier_as_type);
    SUITE_ADD_TEST(identifier, should_assert_that_name_is_not_empty);

    return identifier;
}
