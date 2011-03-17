#include "expectations.h"
#include "ast.h"
#include "list.h"

begin_example(mj_call, should_have_mj_call_as_type)
    list *list;
    ast *params;
    ast *method;
    ast *obj;
    mj_call *c;
  
    should_pass(new_list(&list))
    should_pass(new_mj_ast_list(list, &params))
    should_pass(new_mj_identifier("bar", &obj))
    should_pass(new_mj_identifier("foo", &method))
    should_pass(new_mj_call(obj, method, params, (ast **) &c))
    should_eq_int(MJ_CALL, c->type)

    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
end_example

begin_example(mj_call, should_have_the_parameters_as_members)
    list *list;
    ast *params;
    ast *method;
    ast *obj;
    mj_call *c;
  
    should_pass(new_list(&list))
    should_pass(new_mj_ast_list(list, &params))
    should_pass(new_mj_identifier("foo", &method))
    should_pass(new_mj_identifier("bar", &obj))
    should_pass(new_mj_call(obj, method, params, (ast **) &c))
    should_eq_ptr(obj, c->object)
    should_eq_ptr(method, c->method)
    should_eq_ptr(params, c->parameters)

    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
end_example

begin_description(mj_call)
    add_example(should_have_mj_call_as_type)
    add_example(should_have_the_parameters_as_members)
end_description
