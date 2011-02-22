#include "CuTest.h"
#include "list.h"
#include "stddef.h"

void should_have_size_zero_when_created(CuTest *tc)
{
    list* list = new_list();
    CuAssertIntEquals(tc, 0, list->size);
    free(list);
}

void should_have_null_as_beginning_and_end_when_created(CuTest *tc)
{
    list* list = new_list();
    CuAssertPtrEquals(tc, NULL, list->first);
    CuAssertPtrEquals(tc, NULL, list->last);
}

CuSuite* list_test_new()
{
    CuSuite *a_new_list = CuSuiteNew();

    SUITE_ADD_TEST(a_new_list, should_have_size_zero_when_created);
    SUITE_ADD_TEST(a_new_list, 
            should_have_null_as_beginning_and_end_when_created);

    return a_new_list;
}
