#include "expectations.h"
#include "ast.h"

static integer* create(int value)
{
    return (integer *) new_integer(value);
}

begin_example(integer, should_have_integer_as_type)
    integer *node = create(0);
    should_eq_int(INTEGER, node->type);
    free(node);
end_example

begin_example(integer, should_have_the_given_int_as_member)
    int value = 5;
    integer *node = create(value);
    should_eq_int(value, node->value);
    free(node);
end_example

begin_description(integer)
    add_example(should_have_integer_as_type)
    add_example(should_have_the_given_int_as_member)
end_description
