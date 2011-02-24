#ifndef INCLUDE_jrv_errors_test_h__
#define INCLUDE_jrv_errors_test_h__

CuSuite *errors_tests()
{
    CuSuite *errors_test_errors();
    CuSuite *tests = CuSuiteNew();

    CuSuiteAddSuite(tests, errors_test_errors());

    return tests;
}

#endif /* INCLUDE_jrv_errors_test_h__ */
