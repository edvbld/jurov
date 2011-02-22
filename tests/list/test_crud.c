#include "CuTest.h"
#include "list.h"
#include "stddef.h"
#include "stdlib.h"

void should_have_size_zero_when_created(CuTest *tc)
{
    list* l = new_list();
    CuAssertIntEquals(tc, 0, l->size);
    free(l);
}

void should_have_null_as_beginning_and_end_when_created(CuTest *tc)
{
    list* l = new_list();
    CuAssertPtrEquals(tc, NULL, l->first);
    CuAssertPtrEquals(tc, NULL, l->last);
    free(l);
}

void should_be_able_to_have_data_appended_to_it(CuTest *tc)
{
    list* l = new_list();
    int *x = malloc(sizeof(int));
    *x = 5;
    append(l, x);
    CuAssertPtrEquals(tc, x, l->first->data);
    CuAssertPtrEquals(tc, x, l->last->data);
    CuAssertIntEquals(tc, 1, l->size);
    CuAssertIntEquals(tc, *x, *((int *) l->first->data));
    CuAssertIntEquals(tc, *x, *((int *) l->last->data));
    free(x);
    free(l->last);
    free(l);
}

void should_be_able_to_have_several_elements_appended_and_freed(CuTest *tc)
{
    list* l = new_list();
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    append(l, a);
    CuAssertIntEquals(tc, 1, l->size);
    CuAssertPtrEquals(tc, a, l->first->data);
    CuAssertPtrEquals(tc, a, l->last->data);
    CuAssertPtrEquals(tc, a, l->first->data);
    CuAssertPtrEquals(tc, NULL, l->first->previous);
    
    append(l, b);
    CuAssertIntEquals(tc, 2, l->size);
    CuAssertPtrEquals(tc, b, l->last->data);
    CuAssertPtrEquals(tc, a, l->last->previous->data);
    CuAssertPtrEquals(tc, NULL, l->first->previous);
   
    append(l, c);
    CuAssertIntEquals(tc, 3, l->size);
    CuAssertPtrEquals(tc, c, l->last->data);
    CuAssertPtrEquals(tc, b, l->last->previous->data);
    CuAssertPtrEquals(tc, a, l->last->previous->previous->data);
    CuAssertPtrEquals(tc, NULL, l->first->previous);
    
    free_list(l);
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
