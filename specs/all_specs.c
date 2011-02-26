#include "spectacular.h"

begin_description(ast)
    use_description(ast_list)
    use_description(binary_operation)
    use_description(ast_walk)
    use_description(boolean)
    use_description(call)
    use_description(identifier)
    use_description(integer)
    use_description(main_class)
    use_description(new_object)
    use_description(print)
    use_description(this)
    use_description(unary_operation)

    add_description(ast_list)
    add_description(binary_operation)
    add_description(ast_walk)
    add_description(boolean)
    add_description(call)
    add_description(identifier)
    add_description(integer)
    add_description(main_class)
    add_description(new_object)
    add_description(print)
    add_description(this)
    add_description(unary_operation)
end_description

begin_description(lexer)
    use_description(single_token_lexer)
    use_description(multiple_token_lexer)

    add_description(single_token_lexer)
    add_description(multiple_token_lexer)
end_description

begin_description(parser)
    use_description(main_class_parser)
    use_description(statement_parser)

    add_description(main_class_parser)
    add_description(statement_parser)
end_description

begin_description(jurov)
    use_description(list)
    use_description(errors)

    add_description(ast)
    add_description(lexer)
    add_description(parser)
    add_description(list)
    add_description(errors)
end_description

int main()
{
    return run_description(jurov)
}
