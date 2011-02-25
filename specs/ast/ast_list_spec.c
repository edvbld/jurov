#include "spectacular.h"
#include "ast.h"
#include "list.h"

static ast_list* create(list *list)
{
    return (ast_list *) new_ast_list(list);
}

begin_example(ast_list, should_have_ast_list_as_type)
    list *list = new_list();
    ast_list *al = create(list);

    should_eq_int(AST_LIST, al->type);

    free(al);
    free(list);
end_example

begin_example(ast_list, should_have_the_given_list_as_member)
    list *list = new_list();
    ast_list *al = create(list);

    should_eq_ptr(list, al->list);

    free(al);
    free(list);
end_example

begin_description(ast_list)
    add_example(should_have_ast_list_as_type)
    add_example(should_have_the_given_list_as_member)
end_description
