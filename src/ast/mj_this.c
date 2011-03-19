#include "utils.h"
#include "errors.h"
#include "mj_this.h"

int new_mj_this(ast **node)
{
    ast* this = jrv_malloc(sizeof(ast));
    this->type = MJ_THIS;
    *node = this;
    return JRV_SUCCESS;
}

void delete_mj_this(ast *this)
{
    jrv_free(&this);
}
