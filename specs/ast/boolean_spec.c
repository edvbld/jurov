#include "expectations.h"
#include "ast/mj_boolean.h"

begin_example(mj_boolean, should_have_mj_boolean_as_type)
    mj_boolean *node;

    should_pass(new_mj_boolean(0, (ast **) &node))
    should_eq_int(MJ_BOOLEAN, node->type)

    free(node);
end_example

begin_example(mj_boolean, should_have_the_given_parameter_as_value)
    int value = 0;
    mj_boolean *node;

    should_pass(new_mj_boolean(value, (ast **) &node))
    should_eq_int(value, node->value)
    
    free(node);
end_example

begin_description(mj_boolean)
    add_example(should_have_mj_boolean_as_type)
    add_example(should_have_the_given_parameter_as_value)
end_description
