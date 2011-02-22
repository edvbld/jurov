#ifndef __PARSER_TESTS_H__
#define __PARSER_TESTS_H__

CuSuite* parser_test_main_class();
CuSuite* parser_test_statements();

CuSuite* parser_tests()
{
    CuSuite *parser_tests = CuSuiteNew();

    CuSuiteAddSuite(parser_tests, parser_test_main_class());
    CuSuiteAddSuite(parser_tests, parser_test_statements());

    return parser_tests;
}

#endif /* __PARSER_TESTS_H_ */
