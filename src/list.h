#ifndef __LIST_H__
#define __LIST_H__

/**
 * This struct represents an element in a list
 */
typedef struct list_element {
    /* The data of the element */
    void *data;

    /* The next element in the list */
    struct list_element *next;
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
 * @returns A pointer to the newly created list
 */
list* new_list();

/** 
 * Appends an element to the list 
 *
 * @param list The list to append the element to
 * @param data The data to append
 */
void append(list *list, void *data);

/**
 * Deletes (frees) all the list and all its elements
 *
 * @param list The list to delete
 */
void delete(list *list);

#endif /* __LIST_H__ */
