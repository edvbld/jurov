#include "spectacular.h"
#include "lex.yy.h"

int parse_statements(char *statements)
{
    int res = 0;
    char *main_function_opening = 
        "class Main {\n"
        "public static void main(String[] args) {\n";
    char *main_function_closening = 
        "}}";
    char *program = malloc(strlen(main_function_opening) + 
                           strlen(statements) + 
                           strlen(main_function_closening) + 1);
    sprintf(program, "%s%s%s", main_function_opening, 
                               statements, 
                               main_function_closening);
    yy_scan_string(program);
    res = yyparse();
    yylex_destroy();
    free(program);
    return res;
}

begin_spec(statement_parser, should_parse_the_empty_statement)
    char *statement = "{}";
    should_pass(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_fail_when_missing_rigth_curly_bracket)
    char *statement = "{";
    should_fail(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_fail_when_missing_left_curly_bracket)
    char *statement = "}";
    should_fail(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_parse_nested_statements)
    char *statement = "{{{}}}";
    should_pass(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_parse_a_print_statement)
    char *statement = "System.out.println(true);";
    should_pass(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_fail_if_trying_to_print_a_statement)
    char *statement = "System.out.println({});"; 
    should_fail(parse_statements(statement))
end_spec

begin_spec(statement_parser, should_parse_several_mixed_statements)
    char *statements = 
        "System.out.println(true);\n"
        "{System.out.println(false);}";
    should_pass(parse_statements(statements))
end_spec

begin_description(statement_parser)
    add_spec(should_parse_the_empty_statement)
    add_spec(should_fail_when_missing_rigth_curly_bracket)
    add_spec(should_fail_when_missing_left_curly_bracket)
    add_spec(should_parse_nested_statements)
    add_spec(should_parse_a_print_statement)
    add_spec(should_fail_if_trying_to_print_a_statement)
    add_spec(should_parse_several_mixed_statements)
end_description
