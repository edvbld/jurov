#include "expectations.h"
#include "ast/mj_print.h"
#include "ast/mj_boolean.h"
#include "ast/mj_if.h"

begin_example(mj_if, should_have_mj_if_as_type)
    mj_if *mi;

    should_pass(new_mj_if(NULL, NULL, NULL, (ast **) &mi))
    should_eq_int(MJ_IF, mi->type)

    free(mi);
end_example

begin_example(mj_if, should_have_the_given_parameters_as_members)
    mj_if *mi;
    ast *cond;
    ast *ts, *fs;
    
    should_pass(new_mj_boolean(1, &cond))
    should_pass(new_mj_print(NULL, &ts))
    should_pass(new_mj_print(NULL, &fs))
    should_pass(new_mj_if(cond, ts, fs, (ast **) &mi))

    should_eq_ptr(cond, mi->condition)
    should_eq_ptr(ts, mi->true_statement)
    should_eq_ptr(fs, mi->false_statement)

    free(cond);
    free(ts);
    free(fs);
    free(mi);
end_example

begin_description(mj_if)
    add_example(should_have_mj_if_as_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
