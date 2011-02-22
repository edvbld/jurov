#include "CuTest.h"
#include "ast.h"
#include "stddef.h"
#include "stdlib.h"

static main_class* create(identifier *class_id, identifier *parameter_id,
                          ast *statement)
{
    return (main_class *) new_main_class(class_id, parameter_id, statement);
}

void should_have_main_class_as_type(CuTest *tc)
{
    main_class *mc = create(NULL, NULL, NULL);
    CuAssertIntEquals(tc, MAIN_CLASS, mc->type);
    free(mc);
}

void should_have_the_given_parameters_as_members(CuTest *tc)
{
    identifier* class_id = (identifier *) new_identifier("Main");
    identifier* param_id = (identifier *) new_identifier("args");
    ast* statement = new_print(NULL);
    main_class *mc = create(class_id, param_id, statement);
    CuAssertPtrEquals(tc, class_id, mc->class_id);
    CuAssertPtrEquals(tc, param_id, mc->parameter_id);
    CuAssertPtrEquals(tc, statement, mc->statement);
    free(class_id);
    free(param_id);
    free(statement);
    free(mc);
}

CuSuite* ast_test_main_class()
{
    CuSuite *main_class = CuSuiteNew();

    SUITE_ADD_TEST(main_class, should_have_main_class_as_type);
    SUITE_ADD_TEST(main_class, should_have_the_given_parameters_as_members);

    return main_class;
}
