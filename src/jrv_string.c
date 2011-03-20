#include "string.h"
#include "stdarg.h"
#include "utils.h"

char* jrv_str_append(int num_strings, ...)
{
    char *current, *res, *tmp;
    int length, i;
    va_list vl;
    
    res = jrv_malloc(1);
    *res = '\0';
    va_start(vl, num_strings);
    for(i = 0; i < num_strings; i++) {
        current = va_arg(vl, char*);
        if(strlen(current) > 0) {
            length = strlen(res) + strlen(current) + 1; /* +1 for \0 */ 
            tmp = res;
            res = jrv_malloc(length);
            sprintf(res, "%s%s", tmp, current);
            jrv_free(&tmp);
        }
    }
    return res;
}
