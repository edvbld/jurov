#include "errors.h"
#include "utils.h"
#include "stddef.h"

static struct {
    int error;
    char *msg;
} error_descriptions[] = {
    {JRV_ERROR, "Unspecified error"},
    {JRV_INVALID_TYPE, "The object did not have the expected type"},
    {JRV_INVALID_STRING, "The string is empty or NULL"}
};

char *jrv_error_description(int error)
{
    size_t i;
    for(i = 0; i < jrv_array_size(error_descriptions); i++) {
        if(error == error_descriptions[i].error) {
            return error_descriptions[i].msg;
        }
    }
    return "Unknown error";
}
