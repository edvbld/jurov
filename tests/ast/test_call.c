#include "stddef.h"
#include "stdlib.h"
#include "CuTest.h"
#include "ast.h"
#include "list.h"
#include "errors.h"

static call* create(ast *object, ast *method, ast_list *parameters)
{
    return (call *) new_call(object, method, parameters);
}

void should_have_call_as_type(CuTest *tc)
{
    list *list = new_list();
    ast_list *params = (ast_list *) new_ast_list(list);
    ast *method;
    int res1 = new_identifier("foo", &method);
    ast *obj;
    int res2 = new_identifier("bar", &obj);
    call *c = create(obj, method, params);
    CuAssertIntEquals(tc, JRV_SUCCESS, res1);
    CuAssertIntEquals(tc, JRV_SUCCESS, res2);
    CuAssertIntEquals(tc, CALL, c->type);
    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
}

void should_have_the_parameters_as_members(CuTest *tc)
{
    list *list = new_list();
    ast_list *params = (ast_list *) new_ast_list(list);
    ast *method;
    new_identifier("foo", &method);
    ast *obj;
    new_identifier("bar", &obj);
    call *c = create(obj, method, params);
    CuAssertPtrEquals(tc, obj, c->object);
    CuAssertPtrEquals(tc, method, c->method);
    CuAssertPtrEquals(tc, params, c->parameters);
    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
}

CuSuite* ast_test_call()
{
    CuSuite *call = CuSuiteNew();

    SUITE_ADD_TEST(call, should_have_call_as_type);
    SUITE_ADD_TEST(call, should_have_the_parameters_as_members);

    return call;
}
