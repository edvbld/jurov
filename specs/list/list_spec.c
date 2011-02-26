#include "expectations.h"
#include "list.h"

begin_example(list, should_have_size_zero_when_created)
    list* l = new_list();

    should_eq_int(0, l->size)

    free(l);
end_example

begin_example(list, should_have_null_as_beginning_and_end_when_created)
    list* l = new_list();

    should_eq_ptr(NULL, l->first)
    should_eq_ptr(NULL, l->last)

    free(l);
end_example

begin_example(list, should_be_able_to_have_data_appended_to_it)
    list* l = new_list();
    int x = 5;
    
    append(l, &x);
    should_eq_ptr(&x, l->first->data)
    should_eq_ptr(&x, l->last->data)
    should_eq_int(1, l->size)
    should_eq_int(x, *((int *) l->first->data))
    should_eq_int(x, *((int *) l->last->data))
    
    free(l->last);
    free(l);
end_example

begin_example(list, should_be_able_to_have_several_elements_appended_and_freed)
    list* l = new_list();
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;

    append(l, a);
    should_eq_int(1, l->size)
    should_eq_ptr(a, l->first->data)
    should_eq_ptr(a, l->last->data)
    should_eq_ptr(a, l->first->data)
    should_eq_ptr(NULL, l->first->previous)
    
    append(l, b);
    should_eq_int(2, l->size)
    should_eq_ptr(b, l->last->data)
    should_eq_ptr(a, l->last->previous->data)
    should_eq_ptr(NULL, l->first->previous)
   
    append(l, c);
    should_eq_int(3, l->size)
    should_eq_ptr(c, l->last->data)
    should_eq_ptr(b, l->last->previous->data)
    should_eq_ptr(a, l->last->previous->previous->data)
    should_eq_ptr(NULL, l->first->previous)
    
    free_list(l);
end_example

begin_description(list)
    add_example(should_have_size_zero_when_created)
    add_example(should_have_null_as_beginning_and_end_when_created)
    add_example(should_be_able_to_have_data_appended_to_it)
    add_example(should_be_able_to_have_several_elements_appended_and_freed)
end_description
