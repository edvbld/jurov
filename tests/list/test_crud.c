#include "CuTest.h"
#include "list.h"
#include "stddef.h"
#include "stdlib.h"

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

void should_be_able_to_have_data_appended_to_it(CuTest *tc)
{
    list* list = new_list();
    int *x = malloc(sizeof(int));
    *x = 5;
    append(list, x);
    CuAssertPtrEquals(tc, x, list->first->data);
    CuAssertPtrEquals(tc, x, list->last->data);
    CuAssertIntEquals(tc, 1, list->size);
    CuAssertIntEquals(tc, *x, *((int *) list->first->data));
    CuAssertIntEquals(tc, *x, *((int *) list->last->data));
    free(x);
    free(list->last);
    free(list);
}

void should_be_able_to_have_several_elements_appended_and_freed(CuTest *tc)
{
    list* list = new_list();
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    append(list, a);
    CuAssertIntEquals(tc, 1, list->size);
    CuAssertPtrEquals(tc, a, list->first->data);
    CuAssertPtrEquals(tc, a, list->last->data);
    CuAssertPtrEquals(tc, a, list->first->data);
    CuAssertPtrEquals(tc, NULL, list->first->previous);
    
    append(list, b);
    CuAssertIntEquals(tc, 2, list->size);
    CuAssertPtrEquals(tc, b, list->last->data);
    CuAssertPtrEquals(tc, a, list->last->previous->data);
    CuAssertPtrEquals(tc, NULL, list->first->previous);
   
    append(list, c);
    CuAssertIntEquals(tc, 3, list->size);
    CuAssertPtrEquals(tc, c, list->last->data);
    CuAssertPtrEquals(tc, b, list->last->previous->data);
    CuAssertPtrEquals(tc, a, list->last->previous->previous->data);
    CuAssertPtrEquals(tc, NULL, list->first->previous);
    
    free_list(list);
}

CuSuite* list_test_crud()
{
    CuSuite *a_list = CuSuiteNew();

    SUITE_ADD_TEST(a_list, should_have_size_zero_when_created);
    SUITE_ADD_TEST(a_list, should_have_null_as_beginning_and_end_when_created);
    SUITE_ADD_TEST(a_list, should_be_able_to_have_data_appended_to_it);
    SUITE_ADD_TEST(a_list, 
            should_be_able_to_have_several_elements_appended_and_freed);

    return a_list;
}
