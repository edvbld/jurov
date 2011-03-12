#include "expectations.h"
#include "ast.h"

begin_example(mj_type, should_have_mj_type_as_type)
    mj_type *t;

    should_pass(new_mj_type(MJ_TYPE_INTEGER, NULL, (ast **) &t))
    should_eq_int(MJ_TYPE, t->type)

    free(t);
end_example

begin_example(mj_type, should_have_null_as_id_when_builtin_type)
    mj_type *t;
    ast *i;
    
    should_pass(new_mj_identifier("Foo", &i))
    should_pass(new_mj_type(MJ_TYPE_INTEGER, i, (ast **) &t))
    should_eq_ptr(NULL, t->id)
    free(t);

    should_pass(new_mj_type(MJ_TYPE_BOOLEAN, i, (ast **) &t))
    should_eq_ptr(NULL, t->id)
    free(t);
    
    should_pass(new_mj_type(MJ_TYPE_INT_ARRAY, i, (ast **) &t))
    should_eq_ptr(NULL, t->id)
    free(t);

    free(i);
end_example

begin_example(mj_type, should_have_given_id_as_member)
    mj_type *t;
    ast *i;
    
    should_pass(new_mj_identifier("Foo", &i))
    should_pass(new_mj_type(MJ_TYPE_USER_DEFINED, i, (ast **) &t))
    should_eq_ptr(i, t->id)

    free(i);
    free(t);
end_example

begin_example(mj_type, should_have_given_mj_type_as_mj_type)
    mj_type *t;
    
    should_pass(new_mj_type(MJ_TYPE_BOOLEAN, NULL, (ast **) &t))
    should_eq_int(MJ_TYPE_BOOLEAN, t->mj_type)

    free(t);
end_example

begin_description(mj_type)
    add_example(should_have_mj_type_as_type)
    add_example(should_have_null_as_id_when_builtin_type)
    add_example(should_have_given_id_as_member)
    add_example(should_have_given_mj_type_as_mj_type)
end_description
