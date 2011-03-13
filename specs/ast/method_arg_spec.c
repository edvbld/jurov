#include "expectations.h"
#include "ast.h"

begin_example(mj_method_arg, should_have_mj_method_arg_as_type)
    mj_method_arg *a;

    should_pass(new_mj_method_arg(NULL, NULL, (ast **) &a))
    should_eq_int(MJ_METHOD_ARG, a->type)

    free(a);
end_example

begin_example(mj_method_arg, should_return_error_when_given_bad_types)
    mj_method_arg *a;
    ast *i;

    should_pass(new_mj_integer(5, &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_arg(i, NULL, (ast **) &a))
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_arg(NULL, i, (ast **) &a))

    free(i);
end_example

begin_example(mj_method_arg, should_have_the_given_parameters_as_members)
    mj_method_arg *a;
    ast *i;
    ast *t;

    should_pass(new_mj_identifier("foo", &i))
    should_pass(new_mj_type(MJ_TYPE_INTEGER, NULL, &t))
    should_pass(new_mj_method_arg(t, i, (ast **) &a))
    should_eq_ptr(i, a->id)
    should_eq_ptr(t, a->mj_type)

    free(i);
    free(t);
    free(a);
end_example

begin_description(mj_method_arg)
    add_example(should_have_mj_method_arg_as_type)
    add_example(should_return_error_when_given_bad_types)
    add_example(should_have_the_given_parameters_as_members)
end_description
