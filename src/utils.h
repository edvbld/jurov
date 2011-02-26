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
 * Print a message to stderr and the exits with exit code 1.
 *
 * @param msg The message to print to stderr
 */
void die(char *msg);

/**
 * Allocates memory and performs additional checks if the computer has run out 
 * of memory. This should be used in the same way (and instead of) malloc. 
 *
 * @param n The amount of memory to allocate
 */
void* j_malloc(size_t n);

#endif /* INCLUDE_jrv_utils_h__ */
