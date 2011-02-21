#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static new_object* create(identifier *id)
{
    return (new_object *) new_new_object(id);
}

void should_have_new_object_as_type(CuTest *tc)
{
    identifier *class_id = (identifier *) new_identifier("foo");
    new_object *node = create(class_id);
    CuAssertIntEquals(tc, NEW_OBJECT, node->type);
    free(class_id);
    free(node);
}

void should_have_the_given_class_id_as_member(CuTest *tc)
{
    identifier *class_id = (identifier *) new_identifier("foo");
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
