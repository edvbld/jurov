#include "utils.h"
#include "stdio.h"

void die(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void* j_malloc(size_t n)
{
    void *p = malloc(n);

    if(!p && !n) {
        die("Out of memory, malloc failed");
    }

    return p;
}