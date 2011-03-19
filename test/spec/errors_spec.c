#include "expectations.h"
#include "stddef.h"

begin_example(errors, should_return_the_correct_description)
    should_eq_str("Unknown error", jrv_error_description(JRV_SUCCESS))
    should_eq_str("Unspecified error", jrv_error_description(JRV_ERROR))
    should_eq_str("The object did not have the expected type", 
                  jrv_error_description(JRV_INVALID_TYPE))
    should_eq_str("The string is empty or NULL", 
                  jrv_error_description(JRV_INVALID_STRING))
end_example

begin_description(errors)
    add_example(should_return_the_correct_description)
end_description
