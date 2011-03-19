#include "errors.h"
#include "utils.h"
#include "ast_list.h"

int new_mj_ast_list(list *list, ast **node)
{
    mj_ast_list *al = jrv_malloc(sizeof(mj_ast_list));
    al->type = MJ_AST_LIST;
    al->list = list;
    *node = (ast *) al;
    return JRV_SUCCESS;
}

int empty_mj_ast_list(ast **node)
{
    list *l;
    mj_ast_list *al = jrv_malloc(sizeof(mj_ast_list));
    new_list(&l);
    al->type = MJ_AST_LIST;
    al->list = l;
    *node = (ast *) al;
    return JRV_SUCCESS;
}

int mj_ast_list_prepend(ast *list, ast *node)
{
    mj_ast_list *l;
    
    if(NULL == list) {
        return JRV_NULL_PTR_ERROR;
    }
    if(NULL == node) {
        return JRV_SUCCESS;
    }
    if(MJ_AST_LIST != list->type) {
        return JRV_INVALID_TYPE;
    }

    l = (mj_ast_list *) list;
    if(node->type == MJ_AST_LIST) {
        list_prepend_list(l->list, ((mj_ast_list *) node)->list);
        jrv_free(&node);
    } else {
        list_prepend_ele(l->list, node);
    }

    return JRV_SUCCESS;
}

static void delete_element(void *data)
{
    delete_ast((ast *) data);
}

void delete_mj_ast_list(mj_ast_list *list)
{
    delete_list_cb(list->list, &delete_element);
    jrv_free(&list);
}
