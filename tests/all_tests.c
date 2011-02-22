#include "CuTest.h"
#include "stdio.h"

CuSuite* lexer_test_single_token();
CuSuite* lexer_test_multiple_tokens();

CuSuite* parser_test_main_class();
CuSuite* parser_test_statements();

CuSuite* ast_test_identifier();
CuSuite* ast_test_ast_walk();
CuSuite* ast_test_binary_operation();
CuSuite* ast_test_integer();
CuSuite* ast_test_unary_operation();
CuSuite* ast_test_boolean();
CuSuite* ast_test_new_object();
CuSuite* ast_test_new_array();

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
    CuSuiteAddSuite(suite, ast_test_integer());
    CuSuiteAddSuite(suite, ast_test_unary_operation());
    CuSuiteAddSuite(suite, ast_test_boolean());
    CuSuiteAddSuite(suite, ast_test_new_object());
    CuSuiteAddSuite(suite, ast_test_new_array());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main()
{
    run_all_tests();
}
