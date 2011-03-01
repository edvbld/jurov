#ifndef INCLUDE_jrv_list_h__
#define INCLUDE_jrv_list_h__

/**
 * This struct represents an element in a list
 */
typedef struct list_element {
    /* The data of the element */
    void *data;

    /* The previous element in the list */
    struct list_element *previous;
} list_element;

/**
 * This struct represensts a list of elements
 */
typedef struct {
    /** The size of the list */
    int size;

    /** The first element of the list */
    list_element *first;

    /** The last element of the list */
    list_element *last;
} list;

/** 
 * Creates a new list.
 * 
 * @param[out] l The addres of the pointer that will point at the result 
 *               of the function
 * @return An integer describing the result of the function
 */
int new_list(list **l);

/** 
 * Appends an element to the list 
 *
 * @param l The list to append the element to
 * @param data The data to append
 * @return An integer describing the result of the function
 */
int list_append_ele(list *l, void *data);

/**
 * Prepends an element to the list
 *
 * @param l The list to prepend the element to
 * @param data The data to prepend to the list
 * @return An integer describing the result of the function
 */
int list_prepend_ele(list *l, void *data);

/**
 * Appends all the elements of the second list to the first list.
 * NOTE: list2 is freed in this operation, do not use this pointer afterwards!
 *
 * @param list1 The list to append list2 to
 * @param list2 The list to append to list1
 * @return An integer describing the result of the function
 */
int list_append_list(list *list1, list *list2);

/**
 * Prepends all the elements of the second list to the first list.
 * NOTE: list2 is freed in this operation, do not use this pointer afterwards!
 *
 * @param list1 The list to prepend list2 to
 * @param list2 The list to prepend to list1
 * @return An integer describing the result of the function
 */
int list_prepend_list(list *list1, list *list2);

/**
 * Frees the list and all the list_element. For the data pointer in each 
 * list_element, the supplied callback will be called to handle the freeing of 
 * the data.
 *
 * @param list The list to delete
 * @param callback The function to call to free the data pointer in each element
 * @return An integer describing the result of the function
 */
int delete_list_cb(list *l, void (*callback)(void *data));

/**
 * Frees the list and all its elements. Frees the element by just freeing 
 * the void pointer. If you need more control of how the elements are freed, 
 * see delete_list_cb.
 *
 * @param list The list to delete
 * @return An integer describing the result of the function
 */
int delete_list(list *l);

#endif /* INCLUDE_jrv_list_h__ */
