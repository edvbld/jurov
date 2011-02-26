#include "expectations.h"
#include "ast.h"

begin_example(integer, should_have_integer_as_type)
    integer *node;
    
    should_pass(new_integer(0, (ast **) &node))
    should_eq_int(INTEGER, node->type)
    
    free(node);
end_example

begin_example(integer, should_have_the_given_int_as_member)
    integer *node;
    int value = 5;

    should_pass(new_integer(value, (ast **) &node))
    should_eq_int(value, node->value)

    free(node);
end_example

begin_description(integer)
    add_example(should_have_integer_as_type)
    add_example(should_have_the_given_int_as_member)
end_description
