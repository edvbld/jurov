#include "errors.h"
#include "utils.h"
#include "mj_integer.h"

int new_mj_integer(int value, ast **node)
{
    mj_integer *i = jrv_malloc(sizeof(mj_integer));
    i->value = value;
    i->type = MJ_INTEGER;
    *node = (ast *) i;
    return JRV_SUCCESS;
}

void delete_mj_integer(mj_integer *i)
{
    jrv_free(&i);
}
