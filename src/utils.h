#ifndef __UTILS_H__
#define __UTILS_H__

#include "stdlib.h"

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
