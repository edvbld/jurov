#include "CuTest.h"
#include "stdio.h"

CuSuite* lexer_lex_single_token_test_suite();
CuSuite* lexer_lex_multiple_tokens_test_suite();
CuSuite* parser_parse_main_class_test_suite();

void run_all_tests()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, lexer_lex_single_token_test_suite());
    CuSuiteAddSuite(suite, lexer_lex_multiple_tokens_test_suite());
    CuSuiteAddSuite(suite, parser_parse_main_class_test_suite());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main()
{
    run_all_tests();
}
