#include "expectations.h"
#include "ast/mj_array_assignment.h"
#include "ast/mj_identifier.h"
#include "ast/mj_integer.h"

begin_example(mj_array_assignment, should_have_mj_array_assignment_as_type)
    mj_array_assignment *aa;

    should_pass(new_mj_array_assignment(NULL, NULL, NULL, (ast **) &aa))
    should_eq_int(MJ_ARRAY_ASSIGNMENT, aa->type)

    free(aa);
end_example

begin_example(mj_array_assignment, should_return_error_when_given_bad_type)
    mj_array_assignment *aa;
    ast *i;

    should_pass(new_mj_integer(5, &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_array_assignment(i, NULL, NULL,
                                                              (ast **) &aa))
    should_eq_ptr(NULL, aa)

    free(i);
end_example

begin_example(mj_array_assignment, should_have_the_given_parameters_as_members)
    mj_array_assignment *aa;
    ast *id, *index, *value;

    should_pass(new_mj_identifier("foo", &id))
    should_pass(new_mj_integer(4, &index))
    should_pass(new_mj_integer(3, &value))
    should_pass(new_mj_array_assignment(id, index, value, (ast **) &aa))
    should_eq_ptr(id, aa->id)
    should_eq_ptr(index, aa->index_exp)
    should_eq_ptr(value, aa->value_exp)

    free(id);
    free(index);
    free(value);
    free(aa);
end_example

begin_description(mj_array_assignment)
    add_example(should_have_mj_array_assignment_as_type)
    add_example(should_return_error_when_given_bad_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
