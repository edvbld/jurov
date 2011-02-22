#include "CuTest.h"
#include "ast.h"
#include "utils.h"
#include "stddef.h"
#include "stdlib.h"

static int j_abort_called = 0;

void update_j_abort_called()
{
    j_abort_called = 1;
}

static identifier* create(char *name)
{
    return (identifier *) new_identifier(name);
}

void should_assert_that_name_is_not_empty(CuTest *tc)
{
    j_abort = &update_j_abort_called;
    identifier *node = create("");
    CuAssertIntEquals(tc, 1, j_abort_called);
    j_abort_called = 0;
    free(node);
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
    SUITE_ADD_TEST(identifier, should_assert_that_name_is_not_empty);

    return identifier;
}
