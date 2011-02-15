#include "CuTest.h"
#include "lex.yy.h"

/*
 * Helper function for parsing a string.
 *
 * :param program: A string representing the program to parse
 * :returns: An integer, the return code from bison
 */
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

void should_parse_the_empty_statement(CuTest *tc)
{
    char *statement = "{}";
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 0, res);
}

void should_fail_when_missing_rigth_curly_bracket(CuTest *tc)
{
    char *statement = "{";
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_left_curly_bracket(CuTest *tc)
{
    char *statement = "}";
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 1, res);
}

void should_parse_nested_statements(CuTest *tc)
{
    char *statement = "{{{}}}";
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 0, res);
}

void should_parse_a_print_statement(CuTest *tc)
{
    char *statement = "System.out.println(true);";
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 0, res);
}

void should_fail_if_trying_to_print_a_statement(CuTest *tc)
{
    char *statement = "System.out.println({});"; 
    int res = parse_statements(statement);
    CuAssertIntEquals(tc, 1, res);
}

void should_parse_several_mixed_statements(CuTest *tc)
{
    char *statements = 
        "System.out.println(true);\n"
        "{System.out.println(false);}";
    int res = parse_statements(statements);
    CuAssertIntEquals(tc, 0, res);
}

CuSuite* parser_test_statements()
{
    CuSuite *the_parser = CuSuiteNew();

    SUITE_ADD_TEST(the_parser, should_parse_the_empty_statement);
    SUITE_ADD_TEST(the_parser, should_fail_when_missing_rigth_curly_bracket);
    SUITE_ADD_TEST(the_parser, should_fail_when_missing_left_curly_bracket);
    SUITE_ADD_TEST(the_parser, should_parse_nested_statements);
    SUITE_ADD_TEST(the_parser, should_parse_a_print_statement);
    SUITE_ADD_TEST(the_parser, should_fail_if_trying_to_print_a_statement);
    SUITE_ADD_TEST(the_parser, should_parse_several_mixed_statements);

    return the_parser;
}
