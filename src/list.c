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
