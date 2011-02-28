#include "expectations.h"
#include "ast.h"

begin_example(mj_integer, should_have_mj_integer_as_type)
    mj_integer *node;
    
    should_pass(new_mj_integer(0, (ast **) &node))
    should_eq_int(MJ_INTEGER, node->type)
    
    free(node);
end_example

begin_example(mj_integer, should_have_the_given_int_as_member)
    mj_integer *node;
    int value = 5;

    should_pass(new_mj_integer(value, (ast **) &node))
    should_eq_int(value, node->value)

    free(node);
end_example

begin_description(mj_integer)
    add_example(should_have_mj_integer_as_type)
    add_example(should_have_the_given_int_as_member)
end_description
