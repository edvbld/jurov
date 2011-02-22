#include "list.h"
#include "stddef.h"
#include "utils.h"

list* new_list()
{
    list *list = j_malloc(sizeof(list));
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void append(list* list, void *data)
{
    list_element *ele = j_malloc(sizeof(list_element));
    ele->data = data;
    ele->previous = list->last;
    if(0 == list->size) {
        list->first = ele;
    }
    list->last = ele;
    list->size += 1;
}

void free_list(list* list)
{
    list_element *current = list->last;
    list_element *tmp;

    /* free all the elements */
    while(NULL != current) {
        tmp = current->previous;
        free(current->data);
        free(current);
        current = tmp;
    }

    /* free the list itself */
    free(list);
}
