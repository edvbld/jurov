#include "expectations.h"
#include "ast.h"

begin_example(mj_type, should_have_mj_type_as_type)
    mj_type *t;

    should_pass(new_mj_type(MJ_TYPE_INTEGER, NULL, (ast **) &t))
    should_eq_int(MJ_TYPE, t->type)

    free(t);
end_example

begin_description(mj_type)
    add_example(should_have_mj_type_as_type)
end_description
