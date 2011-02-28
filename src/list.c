#include "stddef.h"
#include "utils.h"
#include "errors.h"
#include "types.h"
#include "list.h"

int new_list(list **l)
{
    list *tmp = jrv_malloc(sizeof(list));
    tmp->size = 0;
    tmp->first = NULL;
    tmp->last = NULL;
    *l = tmp;
    return JRV_SUCCESS;
}

int append(list* l, void *data)
{
    list_element *ele = jrv_malloc(sizeof(list_element));
    ele->data = data;
    ele->previous = l->last;
    if(0 == l->size) {
        l->first = ele;
    }
    l->last = ele;
    l->size += 1;
    return JRV_SUCCESS;
}

int delete_list_cb(list *l, void (*callback)(void *p))
{
    list_element *current = l->last;
    list_element *tmp;

    /* free all the elements */
    while(NULL != current) {
        tmp = current->previous;
        callback(current->data); 
        jrv_free(&current);
        current = tmp;
    }

    /* free the list itself */
    jrv_free(&l);
    return JRV_SUCCESS;
}

void free_element(void *p)
{
    jrv_free(&p);
}

int delete_list(list* l)
{
    return delete_list_cb(l, &free_element);
}

