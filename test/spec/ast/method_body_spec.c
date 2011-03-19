#include "expectations.h"
#include "ast/ast_list.h"
#include "ast/mj_print.h"
#include "ast/mj_var_decl.h"
#include "ast/mj_identifier.h"
#include "ast/mj_method_body.h"

begin_example(mj_method_body, should_have_mj_method_body_as_type)
    mj_method_body *b;

    should_pass(new_mj_method_body(NULL, NULL, (ast **) &b))
    should_eq_int(MJ_METHOD_BODY, b->type)

    free(b);
end_example

begin_example(mj_method_body, should_return_error_when_given_bad_types)
    mj_method_body *b;
    ast *i;

    should_pass(new_mj_identifier("foo", &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_body(i, NULL, (ast **) &b))
    should_eq_ptr(NULL, b)
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_body(NULL, i, (ast **) &b))
    should_eq_ptr(NULL, b)

    free(i);
end_example

begin_example(mj_method_body, should_have_the_given_parameters_as_members)
    mj_method_body *b;
    ast *vars, *stmts;

    should_pass(empty_mj_ast_list(&vars))
    should_pass(empty_mj_ast_list(&stmts))
    should_pass(new_mj_method_body(vars, stmts, (ast **) &b))
    should_eq_ptr(vars, b->var_declarations)
    should_eq_ptr(stmts, b->statements)

    delete_ast(vars);
    delete_ast(stmts);
    free(b);
end_example

begin_example(mj_method_body, should_be_able_to_add_statement_to_body)
    mj_method_body *b;
    ast *stmts, *print;

    should_pass(empty_mj_ast_list(&stmts))
    should_pass(new_mj_method_body(NULL, stmts, (ast **) &b))
    should_pass(new_mj_print(NULL, &print))
    should_pass(mj_method_body_add_statement(print, (ast *) b))
    should_eq_int(1, b->statements->list->size)
    should_eq_ptr(print, b->statements->list->first->data)

    delete_ast(stmts);
    free(b);
end_example

begin_example(mj_method_body, should_be_able_to_add_var_decl_to_body)
    mj_method_body *b;
    ast *vars, *decl;

    should_pass(empty_mj_ast_list(&vars))
    should_pass(new_mj_method_body(vars, NULL, (ast **) &b))
    should_pass(new_mj_var_decl(NULL, NULL, &decl))
    should_pass(mj_method_body_add_var_decl(decl, (ast *) b))
    should_eq_int(1, b->var_declarations->list->size)
    should_eq_ptr(decl, b->var_declarations->list->first->data)

    delete_ast(vars);
    free(b);
end_example

begin_description(mj_method_body)
    add_example(should_have_mj_method_body_as_type)
    add_example(should_return_error_when_given_bad_types)
    add_example(should_have_the_given_parameters_as_members)
    add_example(should_be_able_to_add_statement_to_body)
    add_example(should_be_able_to_add_var_decl_to_body)
end_description
