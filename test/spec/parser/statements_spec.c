#include "string.h"
#include "expectations.h"
#include "parser.h"

int parse_statements(char *statements, ast **tree)
{
    int res = 0;
    char *main_function_opening =
        "class Main {\n"
        "public static void main(String[] args) {\n";
    char *main_function_closening =
        "}}";
    int length = strlen(main_function_opening) +
                 strlen(statements) +
                 strlen(main_function_closening) + 1;
    char *program = malloc(length);
    sprintf(program, "%s%s%s", main_function_opening,
                               statements,
                               main_function_closening);
    res = parse_string(program, tree);
    free(program);
    return res;
}

begin_example(statement_parser, should_parse_the_empty_statement)
    char *statement = "{}";
    ast *tree;
    should_pass(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_fail_when_missing_rigth_curly_bracket)
    char *statement = "{";
    ast *tree;
    should_fail(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_fail_when_missing_left_curly_bracket)
    char *statement = "}";
    ast *tree;
    should_fail(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_parse_nested_statements)
    char *statement = "{{{}}}";
    ast *tree;
    should_pass(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_parse_a_print_statement)
    char *statement = "System.out.println(true);";
    ast *tree;
    should_pass(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_fail_if_trying_to_print_a_statement)
    char *statement = "System.out.println({});";
    ast *tree;
    should_fail(parse_statements(statement, &tree))
    delete_parser(tree);
end_example

begin_example(statement_parser, should_parse_several_mixed_statements)
    char *statements =
        "System.out.println(true);\n"
        "{System.out.println(false);}";
    ast *tree;
    should_pass(parse_statements(statements, &tree))
    delete_parser(tree);
end_example

begin_description(statement_parser)
    add_example(should_parse_the_empty_statement)
    add_example(should_fail_when_missing_rigth_curly_bracket)
    add_example(should_fail_when_missing_left_curly_bracket)
    add_example(should_parse_nested_statements)
    add_example(should_parse_a_print_statement)
    add_example(should_fail_if_trying_to_print_a_statement)
    add_example(should_parse_several_mixed_statements)
end_description
