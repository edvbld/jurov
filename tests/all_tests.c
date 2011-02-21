#include "CuTest.h"
#include "stdio.h"

CuSuite* lexer_test_single_token();
CuSuite* lexer_test_multiple_tokens();
CuSuite* parser_test_main_class();
CuSuite* parser_test_statements();
CuSuite* ast_test_identifier();
CuSuite* ast_test_ast_walk();
CuSuite* ast_test_binary_operation();

void run_all_tests()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, lexer_test_single_token());
    CuSuiteAddSuite(suite, lexer_test_multiple_tokens());
    CuSuiteAddSuite(suite, parser_test_main_class());
    CuSuiteAddSuite(suite, parser_test_statements());
    CuSuiteAddSuite(suite, ast_test_identifier());
    CuSuiteAddSuite(suite, ast_test_ast_walk());
    CuSuiteAddSuite(suite, ast_test_binary_operation());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main()
{
    run_all_tests();
}
