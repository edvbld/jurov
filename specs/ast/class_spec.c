#include "expectations.h"
#include "ast.h"

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

begin_description(mj_class)
    add_example(should_have_mj_class_as_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
