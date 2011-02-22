#ifndef __UTILS_H__
#define __UTILS_H__

#include "stdlib.h"
#include "stdio.h"

/**
 * This is only for unit testing purposes to be able to check 
 * that abort is called
 */
extern void (*j_abort)();

/**
 * Macro for asserting statements.
 *
 * @param e The expression to check
 * @param s An message describing the error
 */
#define j_assert(e, s)  \
    ((void) ((e) ? 0 : __j_assert (s, __FILE__, __LINE__)))
#define __j_assert(s, file, line) \
    (j_abort != abort? j_abort() : \
        (void)printf ("Internal compiler error: %s [%s:%u]\n", s, file, line), \
        j_abort())


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

#endif // __UTILS_H__
