#ifndef INCLUDE_jrv_expectation_h__
#define INCLUDE_jrv_expectation_h__

#include "stddef.h"
#include "spectacular.h"
#include "errors.h"

#define should_pass(act) should_eq_int(JRV_SUCCESS, act)
#define should_fail(act) should_neq_int(JRV_SUCCESS, act)
#define should_eq_error(error, act) should_eq_int(error, act)

#endif /* INCLUDE_jrv_expectation_h__ */
