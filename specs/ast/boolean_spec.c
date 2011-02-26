#include "expectations.h"
#include "ast.h"

begin_example(boolean, should_have_boolean_as_type)
    boolean *node;

    should_pass(new_boolean(0, (ast **) &node))
    should_eq_int(BOOL, node->type)

    free(node);
end_example

begin_example(boolean, should_have_the_given_parameter_as_value)
    int value = 0;
    boolean *node;

    should_pass(new_boolean(value, (ast **) &node))
    should_eq_int(value, node->value)
    
    free(node);
end_example

begin_description(boolean)
    add_example(should_have_boolean_as_type)
    add_example(should_have_the_given_parameter_as_value)
end_description
