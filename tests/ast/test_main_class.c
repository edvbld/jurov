#include "spectacular.h"
#include "ast.h"

static main_class* create(ast *class_id, ast *parameter_id,
                          ast *statement)
{
    return (main_class *) new_main_class(class_id, parameter_id, statement);
}

begin_spec(main_class, should_have_main_class_as_type)
    main_class *mc = create(NULL, NULL, NULL);
    should_eq_int(MAIN_CLASS, mc->type)
    free(mc);
end_spec

begin_spec(main_class, should_have_the_given_parameters_as_members)
    ast* class_id;
    ast* param_id;
    ast* statement;

    should_pass(new_identifier("args", &param_id))
    should_pass(new_identifier("Main", &class_id))
    statement = new_print(NULL);
    main_class *mc = create(class_id, param_id, statement);
    should_eq_ptr(class_id, mc->class_id)
    should_eq_ptr(param_id, mc->parameter_id)
    should_eq_ptr(statement, mc->statement) 

    free(class_id);
    free(param_id);
    free(statement);
    free(mc);
end_spec

begin_description(main_class)
    add_spec(should_have_main_class_as_type)
    add_spec(should_have_the_given_parameters_as_members)
end_description
