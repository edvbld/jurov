#include "expectations.h"
#include "ast.h"
#include "list.h"

begin_example(call, should_have_call_as_type)
    list *list = new_list();
    ast_list *params;
    ast *method;
    ast *obj;
    call *c;
   
    should_pass(new_ast_list(list, (ast **) &params))
    should_pass(new_identifier("bar", &obj))
    should_pass(new_identifier("foo", &method))
    should_pass(new_call(obj, method, params, (ast **) &c))
    should_eq_int(CALL, c->type)

    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
end_example

begin_example(call, should_have_the_parameters_as_members)
    list *list = new_list();
    ast_list *params;
    ast *method;
    ast *obj;
    call *c;
   
    should_pass(new_ast_list(list, (ast **) &params))
    should_pass(new_identifier("foo", &method))
    should_pass(new_identifier("bar", &obj))
    should_pass(new_call(obj, method, params, (ast **) &c))
    should_eq_ptr(obj, c->object)
    should_eq_ptr(method, c->method)
    should_eq_ptr(params, c->parameters)

    free(list);
    free(params);
    free(method);
    free(obj);
    free(c);
end_example

begin_description(call)
    add_example(should_have_call_as_type)
    add_example(should_have_the_parameters_as_members)
end_description
