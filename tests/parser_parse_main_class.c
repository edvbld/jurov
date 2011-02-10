#include "CuTest.h"
#include "jurov.tab.h"
#include "lex.yy.h"

void should_parse_a_program_consisting_of_only_main_class(CuTest *tc)
{
    char *program = 
        "class Main {\n"
        "public static void main(String[] args) {\n"
        "}}";
    int err = 0;
    YY_BUFFER_STATE b = yy_scan_string(program);
    yy_switch_to_buffer(b);
    err = yyparse();
    yylex_destroy();
    CuAssertIntEquals(tc, 0, err);
}

CuSuite* parser_parse_main_class_test_suite()
{
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, should_parse_a_program_consisting_of_only_main_class);

    return suite;
}
