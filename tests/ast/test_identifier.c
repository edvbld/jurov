#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

void should_have_an_id_member(CuTest *tc)
{
    char *name = "name";
    ast* node = new_identifier(name);
    identifier* id = (identifier *) node;
    CuAssertStrEquals(tc, name, id->name);
    free(id);
}

CuSuite* ast_test_identifier_node()
{
    CuSuite *identifier_node = CuSuiteNew();

    SUITE_ADD_TEST(identifier_node, should_have_an_id_member);

    return identifier_node;
}
