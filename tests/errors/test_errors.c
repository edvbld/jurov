#include "CuTest.h"
#include "errors.h"
#include "stddef.h"

void should_return_the_correct_description(CuTest *tc)
{
    CuAssertStrEquals(tc, "Unknown error", 
                      jrv_error_description(JRV_SUCCESS));
    CuAssertStrEquals(tc, "Unspecified error",
                      jrv_error_description(JRV_ERROR));
    CuAssertStrEquals(tc, "The object did not have the expected type",
                      jrv_error_description(JRV_INVALID_TYPE));
    CuAssertStrEquals(tc, "The string is empty or NULL",
                      jrv_error_description(JRV_INVALID_STRING));
}

CuSuite* errors_test_errors()
{
    CuSuite *errors = CuSuiteNew();

    SUITE_ADD_TEST(errors, should_return_the_correct_description);

    return errors;
}
