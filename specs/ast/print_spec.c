#include "expectations.h"
#include "ast.h"

begin_example(mj_print, should_have_mj_print_as_type)
    mj_print *p;

    should_pass(new_mj_print(NULL, (ast **) &p))
    should_eq_int(MJ_PRINT, p->type)
    
    free(p);
end_example

begin_example(mj_print, should_have_the_given_expression_as_member)
    ast *id;
    mj_print *p;

    should_pass(new_mj_identifier("foo", &id))
    should_pass(new_mj_print(id, (ast **) &p))
    should_eq_ptr(id, p->expression);

    free(id);
    free(p);
end_example

begin_description(mj_print)
    add_example(should_have_mj_print_as_type)
    add_example(should_have_the_given_expression_as_member)
end_description
