#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"
#include "list.h"

static ast_list* create(list *list)
{
    return (ast_list *) new_ast_list(list);
}

void should_have_ast_list_as_type(CuTest *tc)
{
    list *list = new_list();
    ast_list *al = create(list);
    CuAssertIntEquals(tc, AST_LIST, al->type);
    free(al);
    free(list);
}

void should_have_the_given_list_as_member(CuTest *tc)
{
    list *list = new_list();
    ast_list *al = create(list);
    CuAssertPtrEquals(tc, list, al->list);
    free(al);
    free(list);
}

CuSuite* ast_test_ast_list()
{
    CuSuite *ast_list = CuSuiteNew();
    
    SUITE_ADD_TEST(ast_list, should_have_ast_list_as_type);
    SUITE_ADD_TEST(ast_list, should_have_the_given_list_as_member);

    return ast_list;
}

