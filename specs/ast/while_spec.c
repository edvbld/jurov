#include "expectations.h"
#include "ast.h"

begin_example(mj_while, should_have_mj_while_as_type)
    mj_while *w;

    should_pass(new_mj_while(NULL, NULL, (ast **) &w))
    should_eq_int(MJ_WHILE, w->type)

    free(w);
end_example

begin_example(mj_while, should_have_the_given_parameters_as_members)
    mj_while *w;
    ast *cond, *stmt;

    should_pass(new_mj_boolean(1, &cond))
    should_pass(new_mj_boolean(0, &stmt))
    should_pass(new_mj_while(cond, stmt, (ast **) &w))
    should_eq_ptr(cond, w->condition)
    should_eq_ptr(stmt, w->statement)

    free(cond);
    free(stmt);
    free(w);
end_example

begin_description(mj_while)
    add_example(should_have_mj_while_as_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
