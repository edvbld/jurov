#include "string.h"
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

char* jrv_str_append(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *res = jrv_malloc(len1 + len2 + 1); /* + 1 for \0 */
    sprintf(res, "%s%s", str1, str2);
    return res;
}
