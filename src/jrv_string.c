#include "string.h"
#include "stdarg.h"
#include "utils.h"

char* jrv_str_append(int num_strings, ...)
{
    char *current;
    char *res, *p;
    int i, length, total_length;
    va_list vl;
    
    va_start(vl, num_strings);
    for(i = 0; i < num_strings; i++) {
        current = va_arg(vl, char*);
        total_length += strlen(current);
    }
    
    total_length += 1; /* +1 for '\0' */
    res = jrv_malloc(total_length);
    
    va_start(vl, num_strings);
    p = res;
    for(i = 0; i < num_strings; i++) {
        current = va_arg(vl, char*);
        length = strlen(current);
        if(length > 0) {
            memcpy(p, current, length);
            p += length;
        }
    }
    memcpy(p, "\0", 1);
    return res;
}
