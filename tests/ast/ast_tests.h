#ifndef __AST_TESTS_H__
#define __AST_TESTS_H__

CuSuite* ast_test_identifier();
CuSuite* ast_test_integer();
CuSuite* ast_test_unary_operation();
CuSuite* ast_test_boolean();
CuSuite* ast_test_new_object();
CuSuite* ast_test_this();
CuSuite* ast_test_call();
CuSuite* ast_test_print();
CuSuite* ast_test_main_class();

CuSuite *ast_tests()
{
    CuSuite* test_ast_list();
    CuSuite* test_binary_operation();
    CuSuite* test_ast_walk();
    
    CuSuite* ast_tests = CuSuiteNew();

    CuSuiteAddSuite(ast_tests, test_ast_list());
    CuSuiteAddSuite(ast_tests, test_binary_operation());
    CuSuiteAddSuite(ast_tests, test_ast_walk());
    CuSuiteAddSuite(ast_tests, ast_test_identifier());
    CuSuiteAddSuite(ast_tests, ast_test_integer());
    CuSuiteAddSuite(ast_tests, ast_test_unary_operation());
    CuSuiteAddSuite(ast_tests, ast_test_boolean());
    CuSuiteAddSuite(ast_tests, ast_test_new_object());
    CuSuiteAddSuite(ast_tests, ast_test_this());
    CuSuiteAddSuite(ast_tests, ast_test_call());
    CuSuiteAddSuite(ast_tests, ast_test_print());
    CuSuiteAddSuite(ast_tests, ast_test_main_class());

    return ast_tests;
}

#endif /* __AST_TESTS_H__ */
