#ifndef __LEXER_TESTS_H__
#define __LEXER_TESTS_H__

CuSuite* lexer_test_single_token();
CuSuite* lexer_test_multiple_tokens();

CuSuite* lexer_tests()
{
    CuSuite* lexer_tests = CuSuiteNew();

    CuSuiteAddSuite(lexer_tests, lexer_test_single_token());
    CuSuiteAddSuite(lexer_tests, lexer_test_multiple_tokens());

    return lexer_tests;
}

#endif /* __LEXER_TESTS_H__*/
