#include "expectations.h"
#include "ast.h"
#include "list.h"

begin_example(mj_ast_list, should_have_mj_ast_list_as_type)
    list *list;
    mj_ast_list *al;

    should_pass(new_list(&list))
    should_pass(new_mj_ast_list(list, (ast **) &al))
    should_eq_int(MJ_AST_LIST, al->type);

    free(al);
    free(list);
end_example

begin_example(mj_ast_list, should_have_the_given_list_as_member)
    list *list;
    mj_ast_list *al;

    should_pass(new_list(&list))
    should_pass(new_mj_ast_list(list, (ast **) &al))
    should_eq_ptr(list, al->list);

    free(al);
    free(list);
end_example

begin_description(mj_ast_list)
    add_example(should_have_mj_ast_list_as_type)
    add_example(should_have_the_given_list_as_member)
end_description
