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
 * @param list The list to append the element to
 * @param data The data to append
 * @return An integer describing the result of the function
 */
int append(list *l, void *data);

/**
 * Frees the list and all its elements
 *
 * @param list The list to delete
 * @return An integer describing the result of the function
 */
int free_list(list *l);

#endif /* INCLUDE_jrv_list_h__ */
