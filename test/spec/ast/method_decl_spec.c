#include "expectations.h"
#include "ast/mj_integer.h"
#include "ast/mj_method_decl.h"

begin_example(mj_method_decl, should_have_mj_method_decl_as_type)
    mj_method_decl *m;

    should_pass(new_mj_method_decl(NULL, NULL, NULL, NULL, NULL, (ast **) &m))
    should_eq_int(MJ_METHOD_DECL, m->type)

    free(m);
end_example

begin_example(mj_method_decl, should_return_error_when_given_bad_types)
    mj_method_decl *m;
    ast *i;

    should_pass(new_mj_integer(5, &i))
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_decl(i, NULL, NULL, NULL, 
                                                         NULL, (ast **) &m))
    should_eq_ptr(NULL, m)
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_decl(NULL, i, NULL, NULL, 
                                                         NULL, (ast **) &m))
    should_eq_ptr(NULL, m)
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_decl(NULL, NULL, i, NULL, 
                                                         NULL, (ast **) &m))
    should_eq_ptr(NULL, m)
    should_eq_error(JRV_INVALID_TYPE, new_mj_method_decl(NULL, NULL, NULL, i,
                                                         NULL, (ast **) &m))
    should_eq_ptr(NULL, m)

    free(i);
end_example

begin_example(mj_method_decl, should_have_the_given_parameters_as_members)
    mj_method_decl *m;
    ast *ret_type, *id, *args, *vars, *stmts, *body, *ret_exp;

    should_pass(new_mj_type(MJ_TYPE_INTEGER, NULL, &ret_type))
    should_pass(new_mj_identifier("double", &id))
    should_pass(empty_mj_ast_list(&args))
    should_pass(empty_mj_ast_list(&vars))
    should_pass(empty_mj_ast_list(&stmts))
    should_pass(new_mj_method_body(vars, stmts, &body))
    should_pass(new_mj_integer(5, &ret_exp))
    should_pass(new_mj_method_decl(ret_type, id, args, body, ret_exp,
                                   (ast **) &m))
    should_eq_ptr(ret_type, m->return_type)
    should_eq_ptr(id, m->id)
    should_eq_ptr(args, m->arguments)
    should_eq_ptr(body, m->body)
    should_eq_ptr(ret_exp, m->return_expression)
    
    free(ret_type);
    free(id);
    delete_ast(args);
    delete_ast(vars);
    delete_ast(stmts);
    free(body);
    free(ret_exp);
    free(m);
end_example

begin_description(mj_method_decl)
    add_example(should_have_mj_method_decl_as_type)
    add_example(should_return_error_when_given_bad_types)
    add_example(should_have_the_given_parameters_as_members)
end_description
