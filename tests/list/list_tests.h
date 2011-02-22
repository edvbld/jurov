#ifndef __LIST_TESTS_H__
#define __LIST_TESTS_H__

CuSuite* list_test_new();

CuSuite* list_tests()
{
    CuSuite* list_tests = CuSuiteNew();

    CuSuiteAddSuite(list_tests, list_test_new());

    return list_tests;
}

#endif /* __LIST_TESTS_H__ */
