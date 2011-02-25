#include "spectacular.h"
#include "ast.h"

static boolean* create(int value)
{
    return (boolean *) new_boolean(value);
}

begin_spec(boolean, should_have_boolean_as_type)
    boolean *node = create(0);
    should_eq_int(BOOL, node->type)
    free(node);
end_spec

begin_spec(boolean, should_have_the_given_parameter_as_value)
    int value = 0;
    boolean *node = create(value);
    should_eq_int(value, node->value)
    free(node);
end_spec

begin_description(boolean)
    add_spec(should_have_boolean_as_type)
    add_spec(should_have_the_given_parameter_as_value)
end_description
