#ifndef __AST_TESTS_H__
#define __AST_TESTS_H__

CuSuite* ast_test_unary_operation();
CuSuite* ast_test_this();

CuSuite *ast_tests()
{
    CuSuite* test_ast_list();
    CuSuite* test_binary_operation();
    CuSuite* test_ast_walk();
    CuSuite* test_boolean();
    CuSuite* test_call();
    CuSuite* test_identifier();
    CuSuite* test_integer();
    CuSuite* test_main_class();
    CuSuite* test_new_object();
    CuSuite* test_print();
    
    CuSuite* suite = CuSuiteNew();

    CuSuiteAddSuite(suite, test_ast_list());
    CuSuiteAddSuite(suite, test_binary_operation());
    CuSuiteAddSuite(suite, test_ast_walk());
    CuSuiteAddSuite(suite, test_boolean());
    CuSuiteAddSuite(suite, test_call());
    CuSuiteAddSuite(suite, test_identifier());
    CuSuiteAddSuite(suite, test_integer());
    CuSuiteAddSuite(suite, test_main_class());
    CuSuiteAddSuite(suite, test_new_object());
    CuSuiteAddSuite(suite, test_print());
    CuSuiteAddSuite(suite, ast_test_unary_operation());
    CuSuiteAddSuite(suite, ast_test_this());

    return suite;
}

#endif /* __AST_TESTS_H__ */
