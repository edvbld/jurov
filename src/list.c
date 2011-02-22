#include "list.h"
#include "stddef.h"
#include "utils.h"

list* new_list()
{
    list *l = j_malloc(sizeof(list));
    l->size = 0;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void append(list* l, void *data)
{
    list_element *ele = j_malloc(sizeof(list_element));
    ele->data = data;
    ele->previous = l->last;
    if(0 == l->size) {
        l->first = ele;
    }
    l->last = ele;
    l->size += 1;
}

void free_list(list* l)
{
    list_element *current = l->last;
    list_element *tmp;

    /* free all the elements */
    while(NULL != current) {
        tmp = current->previous;
        free(current->data);
        free(current);
        current = tmp;
    }

    /* free the list itself */
    free(l);
}
