#include "expectations.h"
#include "ast/mj_integer.h"
#include "ast/mj_var_decl.h"

begin_example(mj_var_decl, should_have_mj_var_decl_as_type)
    mj_var_decl *d;
    
    should_pass(new_mj_var_decl(NULL, NULL, (ast **) &d))
    should_eq_int(MJ_VAR_DECL, d->type)

    free(d);
end_example

begin_example(mj_var_decl, should_return_error_when_given_bad_types)
    mj_var_decl *d;
    ast *i;

    should_pass(new_mj_integer(5, &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_var_decl(i, NULL, (ast **) &d))
    should_eq_ptr(NULL, d)
    should_eq_error(JRV_INVALID_TYPE, new_mj_var_decl(NULL, i, (ast **) &d))
    should_eq_ptr(NULL, d)

    free(i);
end_example

begin_example(mj_var_decl, should_have_the_given_parameters_as_members)
    mj_var_decl *d;
    ast *type;
    ast *id;

    should_pass(new_mj_type(MJ_TYPE_INTEGER, NULL, &type))
    should_pass(new_mj_identifier("Foo", &id))
    should_pass(new_mj_var_decl(type, id, (ast **) &d))
    should_eq_ptr(type, d->mj_type)
    should_eq_ptr(id, d->id)

    free(type);
    free(id);
    free(d);
end_example

begin_description(mj_var_decl)
    add_example(should_have_mj_var_decl_as_type)
    add_example(should_return_error_when_given_bad_types)
    add_example(should_have_the_given_parameters_as_members)
end_description
