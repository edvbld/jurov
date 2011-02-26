#include "expectations.h"
#include "ast.h"

begin_example(main_class, should_have_main_class_as_type)
    main_class *mc;

    should_pass(new_main_class(NULL, NULL, NULL, (ast **) &mc))
    should_eq_int(MAIN_CLASS, mc->type)

    free(mc);
end_example

begin_example(main_class, should_have_the_given_parameters_as_members)
    ast* class_id;
    ast* param_id;
    ast* statement;
    main_class *mc;

    should_pass(new_identifier("args", &param_id))
    should_pass(new_identifier("Main", &class_id))
    should_pass(new_print(NULL, &statement))
    should_pass(new_main_class(class_id, param_id, statement, (ast **) &mc))
    should_eq_ptr(class_id, mc->class_id)
    should_eq_ptr(param_id, mc->parameter_id)
    should_eq_ptr(statement, mc->statement) 

    free(class_id);
    free(param_id);
    free(statement);
    free(mc);
end_example

begin_description(main_class)
    add_example(should_have_main_class_as_type)
    add_example(should_have_the_given_parameters_as_members)
end_description
