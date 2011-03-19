#include "expectations.h"
#include "ast/mj_identifier.h"

begin_example(mj_identifier, should_fail_if_name_is_empty_or_null)
    ast *id;
    should_eq_error(JRV_INVALID_STRING, new_mj_identifier("", &id))
    should_eq_ptr(NULL, id)
    should_eq_error(JRV_INVALID_STRING, new_mj_identifier(NULL, &id))
    should_eq_ptr(NULL, id)
end_example

begin_example(mj_identifier, should_have_the_given_string_as_member)
    char *name = "name";
    mj_identifier *node;
   
    should_pass(new_mj_identifier(name, (ast **) &node))
    should_eq_str(name, node->name)

    free(node);
end_example

begin_example(mj_identifier, should_have_mj_identifier_as_type)
    mj_identifier *node;
    
    should_pass(new_mj_identifier("name", (ast **) &node))
    should_eq_int(MJ_IDENTIFIER, node->type)

    free(node);
end_example

begin_description(mj_identifier)
    add_example(should_fail_if_name_is_empty_or_null)
    add_example(should_have_the_given_string_as_member)
    add_example(should_have_mj_identifier_as_type)
end_description
