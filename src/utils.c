#include "utils.h"

void jrv_die(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    abort();
}

void* jrv_malloc(size_t n)
{
    void *p = malloc(n);

    if(!p && !n) {
        jrv_die("Out of memory, malloc failed");
    }

    return p;
}
