#include "stddef.h"
#include "stdlib.h"
#include "CuTest.h"
#include "ast.h"
#include "errors.h"

static new_object* create(ast *id)
{
    return (new_object *) new_new_object(id);
}

void should_have_new_object_as_type(CuTest *tc)
{
    ast *class_id;
    int res = new_identifier("foo", &class_id);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
    new_object *node = create(class_id);
    CuAssertIntEquals(tc, NEW_OBJECT, node->type);
    free(class_id);
    free(node);
}

void should_have_the_given_class_id_as_member(CuTest *tc)
{
    ast *class_id;
    int res = new_identifier("foo", &class_id);
    CuAssertIntEquals(tc, JRV_SUCCESS, res);
    new_object *node = create(class_id);
    CuAssertPtrEquals(tc, class_id, node->class_id);
    free(class_id);
    free(node);
}

CuSuite* ast_test_new_object()
{
    CuSuite *new_object = CuSuiteNew();

    SUITE_ADD_TEST(new_object, should_have_new_object_as_type);
    SUITE_ADD_TEST(new_object, should_have_the_given_class_id_as_member);

    return new_object;
}
