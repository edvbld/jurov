#include "expectations.h"
#include "ast/mj_assignment.h"
#include "ast/mj_integer.h"
#include "ast/mj_boolean.h"

begin_example(mj_assignment, should_have_mj_assignmnent_as_type)
    mj_assignment *a;

    should_pass(new_mj_assignment(NULL, NULL, (ast **) &a))
    should_eq_int(MJ_ASSIGNMENT, a->type)

    free(a);
end_example

begin_example(mj_assignment, should_return_error_when_given_bad_type)
    mj_assignment *a;
    ast *i;

    should_pass(new_mj_integer(5, &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_assignment(i, NULL, (ast **) &a))
    should_eq_ptr(NULL, a)

    free(i);
end_example

begin_example(mj_assignment, should_have_the_given_parameters_as_members)
    mj_assignment *a;
    ast *id, *b;

    should_pass(new_mj_identifier("foo", &id))
    should_pass(new_mj_boolean(1, &b))
    should_pass(new_mj_assignment(id, b, (ast **) &a))

    should_eq_ptr(id, a->id)
    should_eq_ptr(b, a->expression)

    free(id);
    free(b);
    free(a);
end_example

begin_description(mj_assignment)
    add_example(should_have_mj_assignmnent_as_type)
    add_example(should_return_error_when_given_bad_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
