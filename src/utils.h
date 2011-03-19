#ifndef INCLUDE_jrv_utils_h__
#define INCLUDE_jrv_utils_h__

#include "stdlib.h"
#include "stdio.h"

/**
 * Assert the expression e, otherwise abort with message s
 *
 * @param e The expression to check
 * @param s An message describing the error
 */
#define jrv_assert(e, s)  \
    ((void) ((e) ? 0 : __j_assert (s, __FILE__, __LINE__)))
#define __jrv_assert(s, file, line) \
    ((void)printf ("Internal compiler error: %s [%s:%u]\n", s, file, line), \
     abort())

/**
 * Calculates the length of an array
 *
 * @param array The array to calculcate the length for
 */
#define jrv_array_size(a) (a == NULL? 0 : (sizeof(a) / sizeof(a[0])))


/**
 * Frees the given pointer if it's not null and then sets the pointer to NULL
 *
 * @param pp A pointer to the pointer to free
 */
#define jrv_free(pp) (pp == NULL? (void) 0 : free(*pp), *pp = NULL)

/**
 * Print a message to stderr and the exits with exit code 1.
 *
 * @param msg The message to print to stderr
 */
void jrv_die(char *msg);

/**
 * Allocates memory and performs additional checks if the computer has run out 
 * of memory. This should be used in the same way (and instead of) malloc. 
 *
 * @param n The amount of memory to allocate
 */
void* jrv_malloc(size_t n);

/**
 * Appends a string to another string and returns the result
 *
 * @param str1 The string to append the second string to
 * @param str2 The string to append to the first string
 * @return A pointer to the new string
 */
char* jrv_str_append(char *str1, char *str2);

#endif /* INCLUDE_jrv_utils_h__ */
