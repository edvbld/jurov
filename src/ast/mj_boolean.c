#include "utils.h"
#include "errors.h"
#include "mj_boolean.h"

int new_mj_boolean(int value, ast **node)
{
    mj_boolean *b = jrv_malloc(sizeof(mj_boolean));
    b->type = MJ_BOOLEAN;
    b->value = value;
    *node = (ast *) b;
    return JRV_SUCCESS;
}

void delete_mj_boolean(mj_boolean *b)
{
    jrv_free(&b);
}
