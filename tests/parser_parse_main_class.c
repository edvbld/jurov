#include "CuTest.h"
#include "jurov.tab.h"
#include "lex.yy.h"

/*
 * Helper function for parsing a string.
 *
 * :param program: A string representing the program to parse
 * :returns: An integer, the return code from bison
 */
int parse_program(char *program)
{
    int res = 0;
    YY_BUFFER_STATE b = yy_scan_string(program);
    yy_switch_to_buffer(b);
    res = yyparse();
    yylex_destroy();
    return res;
}

void should_parse_a_program_consisting_of_only_main_class(CuTest *tc)
{
    char *program = 
        "class Main {\n"
        "public static void main(String[] args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 0, res);
}

void should_fail_when_missing_main_function(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public static void start(String[] args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_static_in_main_function(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public void main(String[] args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_public_in_main_function(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "static void main(String[] args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_not_taking_string_array_as_argument(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public static void main(String args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_right_parenthesis_around_main_function(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public static void main(String args {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_left_parenthesis_around_main_function(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public static void main String args) {\n"
        "}}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_main_function_body(CuTest *tc)
{
    char *program =
        "class Main {\n"
        "public static void main(String args) \n"
        "}";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

void should_fail_when_missing_class_around_main_function(CuTest *tc)
{
    char *program =
        "public static void main(String args) \n";
    int res = parse_program(program);
    CuAssertIntEquals(tc, 1, res);
}

CuSuite* parser_parse_main_class_test_suite()
{
    CuSuite *the_parser = CuSuiteNew();

    SUITE_ADD_TEST(the_parser, 
            should_parse_a_program_consisting_of_only_main_class);
    SUITE_ADD_TEST(the_parser, should_fail_when_missing_main_function);
    SUITE_ADD_TEST(the_parser, 
            should_fail_when_missing_static_in_main_function);
    SUITE_ADD_TEST(the_parser, 
            should_fail_when_missing_public_in_main_function);
    SUITE_ADD_TEST(the_parser,
            should_fail_when_not_taking_string_array_as_argument);
    SUITE_ADD_TEST(the_parser,
            should_fail_when_missing_right_parenthesis_around_main_function);
    SUITE_ADD_TEST(the_parser,
            should_fail_when_missing_left_parenthesis_around_main_function);
    SUITE_ADD_TEST(the_parser, should_fail_when_missing_main_function_body);
    SUITE_ADD_TEST(the_parser, 
            should_fail_when_missing_class_around_main_function);

    return the_parser;
}
