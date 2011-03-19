#include "expectations.h"
#include "ast/ast_list.h"
#include "ast/mj_identifier.h"
#include "ast/mj_integer.h"
#include "ast/mj_class.h"

begin_example(mj_class, should_have_mj_class_as_type)
    mj_class *c;

    should_pass(new_mj_class(NULL, NULL, NULL, (ast **) &c))
    should_eq_int(MJ_CLASS, c->type)
    
    free(c);
end_example

begin_example(mj_class, should_have_the_given_parameters_as_members)
    mj_class *c;
    ast *id;
    ast *vars;
    ast *methods;

    should_pass(new_mj_identifier("Foo", &id))
    should_pass(empty_mj_ast_list(&vars))
    should_pass(empty_mj_ast_list(&methods))
    should_pass(new_mj_class(id, vars, methods, (ast **) &c))
    should_eq_ptr(id, c->id)
    should_eq_ptr(vars, c->var_declarations)
    should_eq_ptr(methods, c->method_declarations)

    delete_ast(vars);
    delete_ast(methods);
    free(id);
    free(c);
end_example

begin_example(mj_class, should_return_error_when_given_bad_type)
    mj_class *c;
    ast *num;

    should_pass(new_mj_integer(6, &num))
    should_eq_error(JRV_INVALID_TYPE, 
                    new_mj_class(num, NULL, NULL, (ast **) &c))
    should_eq_ptr(NULL, c)
    should_eq_error(JRV_INVALID_TYPE, 
                    new_mj_class(NULL, num, NULL, (ast **) &c))
    should_eq_ptr(NULL, c)
    should_eq_error(JRV_INVALID_TYPE, 
                    new_mj_class(NULL, NULL, num, (ast **) &c))
    should_eq_ptr(NULL, c)

    free(num);
    free(c);
end_example

begin_description(mj_class)
    add_example(should_have_mj_class_as_type)
    add_example(should_have_the_given_parameters_as_members)
    add_example(should_return_error_when_given_bad_type)
end_description
