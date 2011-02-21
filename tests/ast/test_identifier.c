#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static identifier* create(char *name)
{
    return (identifier *) new_identifier(name);
}

void should_have_an_id_member(CuTest *tc)
{
    char *name = "name";
    identifier *node = create(name);
    CuAssertStrEquals(tc, name, node->name);
    free(node);
}

void should_have_identifier_as_type(CuTest *tc)
{
    identifier *node = create("name");
    CuAssertIntEquals(tc, IDENTIFIER, node->type);
    free(node);
}

CuSuite* ast_test_identifier()
{
    CuSuite *identifier = CuSuiteNew();

    SUITE_ADD_TEST(identifier, should_have_an_id_member);
    SUITE_ADD_TEST(identifier, should_have_identifier_as_type);

    return identifier;
}
