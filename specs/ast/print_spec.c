#include "expectations.h"
#include "ast.h"

begin_example(print, should_have_print_as_type)
    print *p;

    should_pass(new_print(NULL, (ast **) &p))
    should_eq_int(SYSTEM_OUT_PRINT, p->type)
    
    free(p);
end_example

begin_example(print, should_have_the_given_expression_as_member)
    ast *id;
    print *p;

    should_pass(new_identifier("foo", &id))
    should_pass(new_print(id, (ast **) &p))
    should_eq_ptr(id, p->expression);

    free(id);
    free(p);
end_example

begin_description(print)
    add_example(should_have_print_as_type)
    add_example(should_have_the_given_expression_as_member)
end_description
