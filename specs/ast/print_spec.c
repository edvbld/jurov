#include "expectations.h"
#include "ast.h"

static print* create(ast *expression)
{
    return (print *) new_print(expression);
}

begin_example(print, should_have_print_as_type)
    print *p = create(NULL);
    should_eq_int(SYSTEM_OUT_PRINT, p->type)
    free(p);
end_example

begin_example(print, should_have_the_given_expression_as_member)
    ast *id;
    print *p;

    should_pass(new_identifier("foo", &id))
    p = create(id);
    should_eq_ptr(id, p->expression);

    free(id);
    free(p);
end_example

begin_description(print)
    add_example(should_have_print_as_type)
    add_example(should_have_the_given_expression_as_member)
end_description
