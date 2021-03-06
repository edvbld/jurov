#include "expectations.h"
#include "list.h"

begin_example(list, should_have_size_zero_when_created)
    list* l;
    
    should_pass(new_list(&l))
    should_eq_int(0, l->size)

    free(l);
end_example

begin_example(list, should_have_null_as_beginning_and_end_when_created)
    list* l;

    should_pass(new_list(&l))
    should_eq_ptr(NULL, l->first)
    should_eq_ptr(NULL, l->last)

    free(l);
end_example

begin_example(list, should_be_able_to_have_data_appended_to_it)
    list* l;
    int x = 5;
   
    should_pass(new_list(&l))
    should_pass(list_append_ele(l, &x))
    should_eq_ptr(&x, l->first->data)
    should_eq_ptr(&x, l->last->data)
    should_eq_int(1, l->size)
    should_eq_int(x, *((int *) l->first->data))
    should_eq_int(x, *((int *) l->last->data))
    
    free(l->last);
    free(l);
end_example

begin_example(list, should_be_able_to_have_several_elements_appended_and_freed)
    list* l;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;

    should_pass(new_list(&l))
    should_pass(list_append_ele(l, a))
    should_eq_int(1, l->size)
    should_eq_ptr(a, l->first->data)
    should_eq_ptr(a, l->last->data)
    should_eq_ptr(a, l->first->data)
    should_eq_ptr(NULL, l->first->previous)
    
    should_pass(list_append_ele(l, b))
    should_eq_int(2, l->size)
    should_eq_ptr(b, l->last->data)
    should_eq_ptr(a, l->last->previous->data)
    should_eq_ptr(NULL, l->first->previous)
   
    should_pass(list_append_ele(l, c))
    should_eq_int(3, l->size)
    should_eq_ptr(c, l->last->data)
    should_eq_ptr(b, l->last->previous->data)
    should_eq_ptr(a, l->last->previous->previous->data)
    should_eq_ptr(NULL, l->first->previous)
    
    should_pass(delete_list(l))
end_example

static int num_callbacks = 0; 

void inc_callbacks(void *p)
{
    num_callbacks++;
}

begin_example(list, should_call_callback_in_delete_with_cb_for_every_element)
    list *l;
    int a, b, c;

    should_pass(new_list(&l))
    should_pass(list_append_ele(l, &a))
    should_pass(list_append_ele(l, &b))
    should_pass(list_append_ele(l, &c))
    should_pass(delete_list_cb(l, &inc_callbacks))
    should_eq_int(3, num_callbacks)

    num_callbacks = 0;
end_example

begin_example(list, should_be_able_to_have_data_prepended_to_it)
    list *l;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;
    
    should_pass(new_list(&l))

    should_pass(list_prepend_ele(l, c))
    should_eq_ptr(c, l->first->data)
    should_eq_ptr(c, l->last->data)
    should_eq_ptr(NULL, l->first->previous)
    should_eq_ptr(NULL, l->last->previous)
    should_eq_int(1, l->size)

    should_pass(list_prepend_ele(l, b))
    should_eq_ptr(b, l->first->data)
    should_eq_ptr(c, l->last->data)
    should_eq_ptr(b, l->last->previous->data)
    should_eq_ptr(NULL, l->first->previous)
    should_eq_int(2, l->size)

    should_pass(list_prepend_ele(l, a))
    should_eq_ptr(a, l->first->data)
    should_eq_ptr(c, l->last->data)
    should_eq_ptr(b, l->last->previous->data)
    should_eq_ptr(NULL, l->first->previous)
    should_eq_int(3, l->size)

    delete_list(l);
end_example

begin_example(list, should_be_able_to_append_a_list)
    list *l1;
    list *l2;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;

    should_pass(new_list(&l1))
    should_pass(new_list(&l2))
    should_pass(list_append_ele(l1, a))
    should_pass(list_append_ele(l2, b))
    should_pass(list_append_ele(l2, c))
    should_pass(list_append_list(l1, l2))

    should_eq_int(3, l1->size)
    should_eq_ptr(a, l1->first->data)
    should_eq_ptr(c, l1->last->data)
    should_eq_ptr(b, l1->last->previous->data)
    should_eq_ptr(a, l1->last->previous->previous->data)

    delete_list(l1);
end_example

begin_example(list, should_be_able_to_prepend_a_list)
    list *l1;
    list *l2;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;

    should_pass(new_list(&l1))
    should_pass(new_list(&l2))
    should_pass(list_append_ele(l1, a))
    should_pass(list_append_ele(l2, c))
    should_pass(list_append_ele(l2, b))
    should_pass(list_prepend_list(l1, l2))

    should_eq_int(3, l1->size)
    should_eq_ptr(c, l1->first->data)
    should_eq_ptr(a, l1->last->data)
    should_eq_ptr(b, l1->last->previous->data)
    should_eq_ptr(c, l1->last->previous->previous->data)

    delete_list(l1);
end_example

begin_example(list, should_return_error_for_functions_on_a_null_list)
    list *l = NULL;
    list *l2;
    int *a = malloc(sizeof(int));

    should_fail(list_append_ele(l, a))
    should_fail(list_prepend_ele(l, a))

    should_pass(new_list(&l2))
    should_pass(list_append_ele(l2, a))
    should_fail(list_append_list(l, l2))
    should_fail(list_prepend_list(l, l2))

    delete_list(l); /* should not cause memory issues */
    delete_list(l2);
end_example

begin_example(list, should_be_able_to_append_to_empty_list)
    list *l1;
    list *l2;
    int *a = malloc(sizeof(int));

    should_pass(new_list(&l1))
    should_pass(new_list(&l2))

    should_pass(list_append_list(l1, NULL))
    should_pass(list_append_list(l1, l2))
    should_pass(new_list(&l2))
    should_pass(list_append_ele(l2, a))
    should_pass(list_append_list(l1, l2))
    should_eq_int(1, l1->size)
    should_eq_ptr(a, l1->first->data)
    should_eq_ptr(a, l1->last->data)

    delete_list(l1);
end_example

begin_example(list, should_be_able_to_prepend_to_empty_list)
    list *l1;
    list *l2;
    int *a = malloc(sizeof(int));

    should_pass(new_list(&l1))
    should_pass(new_list(&l2))

    should_pass(list_prepend_list(l1, NULL))
    should_pass(list_prepend_list(l1, l2))
    should_pass(new_list(&l2))
    should_pass(list_prepend_ele(l2, a))
    should_pass(list_prepend_list(l1, l2))
    should_eq_int(1, l1->size)
    should_eq_ptr(a, l1->first->data)
    should_eq_ptr(a, l1->last->data)

    delete_list(l1);
end_example

begin_description(list)
    add_example(should_have_size_zero_when_created)
    add_example(should_have_null_as_beginning_and_end_when_created)
    add_example(should_be_able_to_have_data_appended_to_it)
    add_example(should_be_able_to_have_several_elements_appended_and_freed)
    add_example(should_call_callback_in_delete_with_cb_for_every_element)
    add_example(should_be_able_to_have_data_prepended_to_it)
    add_example(should_be_able_to_append_a_list)
    add_example(should_be_able_to_prepend_a_list)
    add_example(should_return_error_for_functions_on_a_null_list)
    add_example(should_be_able_to_append_to_empty_list)
    add_example(should_be_able_to_prepend_to_empty_list)
end_description
