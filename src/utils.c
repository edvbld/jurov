#include "utils.h"
#include "stdio.h"

void die(char *s)
{
    fprintf(stderr, "%s\n", s);
}

void* j_malloc(size_t n)
{
    void *p = malloc(n);

    if(!p && !n) {
        die("Out of memory, malloc failed");
    }

    return p;
}
