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

int list_append_ele(list* l, void *data)
{
    list_element *ele;
    
    if(NULL == l) {
        return JRV_NULL_PTR_ERROR;
    }

    ele = jrv_malloc(sizeof(list_element));
    ele->data = data;
    ele->previous = l->last;
    if(0 == l->size) {
        l->first = ele;
    }
    l->last = ele;
    l->size += 1;
    return JRV_SUCCESS;
}

int list_prepend_ele(list *l, void *data)
{
    list_element *ele;
    
    if(NULL == l) {
        return JRV_NULL_PTR_ERROR;
    }

    ele = jrv_malloc(sizeof(list_element));
    ele->data = data;
    ele->previous = NULL;
    if(0 == l->size) {
        l->last = ele;
    } else {
        l->first->previous = ele;
    }
    l->first = ele;
    l->size += 1;
    return JRV_SUCCESS;
}

int copy_list(list *list1, list *list2)
{
    list1->first = list2->first;
    list1->last = list2->last;
    list1->size = list2->size;
    jrv_free(&list2);
    return JRV_SUCCESS;
}

int list_append_list(list *list1, list *list2)
{
    if(NULL == list1) {
        return JRV_NULL_PTR_ERROR;
    }
    if(NULL == list2) {
        return JRV_SUCCESS;
    }
    if(0 == list2->size) {
        jrv_free(&list2);
        return JRV_SUCCESS;
    }
    if(0 == list1->size) {
        return copy_list(list1, list2);
    }
    list2->first->previous = list1->last;
    list1->last = list2->last;
    list1->size += list2->size;
    
    jrv_free(&list2);
    return JRV_SUCCESS;
}

int list_prepend_list(list *list1, list *list2)
{
    if(NULL == list1) {
        return JRV_NULL_PTR_ERROR;
    }
    if(NULL == list2) {
        return JRV_SUCCESS;
    }
    if(0 == list2->size) {
        jrv_free(&list2);
        return JRV_SUCCESS;
    }
    if(0 == list1->size) {
        return copy_list(list1, list2);
    }
    list1->first->previous = list2->last;
    list1->first = list2->first;
    list1->size += list2->size;

    jrv_free(&list2);
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

