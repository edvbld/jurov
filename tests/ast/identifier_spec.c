#include "spectacular.h"
#include "ast.h"

begin_example(identifier, should_fail_if_name_is_empty_or_null)
    ast *id;
    should_eq_error(JRV_INVALID_STRING, new_identifier("", &id))
    should_eq_error(JRV_INVALID_STRING, new_identifier(NULL, &id))
end_example

begin_example(identifier, should_have_the_given_string_as_member)
    char *name = "name";
    identifier *node;
   
    should_pass(new_identifier(name, (ast **) &node))
    should_eq_str(name, node->name)

    free(node);
end_example

begin_example(identifier, should_have_identifier_as_type)
    identifier *node;
    
    should_pass(new_identifier("name", (ast **) &node))
    should_eq_int(IDENTIFIER, node->type)

    free(node);
end_example

begin_description(identifier)
    add_example(should_fail_if_name_is_empty_or_null)
    add_example(should_have_the_given_string_as_member)
    add_example(should_have_identifier_as_type)
end_description
