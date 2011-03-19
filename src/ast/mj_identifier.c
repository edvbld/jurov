#include "string.h"
#include "utils.h"
#include "errors.h"
#include "mj_identifier.h"

int new_mj_identifier(char *name, ast **node)
{
    mj_identifier *id;

    if(name == NULL || strlen(name) == 0) {
        *node = NULL;
        return JRV_INVALID_STRING;
    }

    id = jrv_malloc(sizeof(mj_identifier));
    id->name = name; 
    id->type = MJ_IDENTIFIER;
    *node = (ast *) id;
    return JRV_SUCCESS;
}

void delete_mj_identifier(mj_identifier *id)
{
    jrv_free(&id->name);
    jrv_free(&id);
}
