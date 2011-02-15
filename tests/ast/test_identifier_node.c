#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

void should_have_an_id_member(CuTest *tc)
{
    char *name = "name";
    struct ast* node = new_identifier_node(name);
    struct identifier_node* id_node = (struct identifier_node *) node;
    CuAssertStrEquals(tc, name, id_node->name);
    free(id_node);
}

CuSuite* ast_test_identifier_node()
{
    CuSuite *identifier_node = CuSuiteNew();

    SUITE_ADD_TEST(identifier_node, should_have_an_id_member);

    return identifier_node;
}
