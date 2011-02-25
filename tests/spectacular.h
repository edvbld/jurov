#ifndef INCLUDE_spectacular_h__
#define INCLUDE_spectacular_h__

#include "stddef.h"
#include "stdlib.h"
#include "CuTest.h"
#include "errors.h"

#define begin_spec(object, property) void _##property(CuTest *tc) {

#define end_spec }

#define should_eq_int(exp, act) CuAssertIntEquals(tc, exp, act);
#define should_eq_str(exp, act) CuAssertStrEquals(tc, exp, act);
#define should_eq_ptr(exp, act) CuAssertPtrEquals(tc, exp, act);
#define should_pass(act) CuAssertIntEquals(tc, JRV_SUCCESS, act);
#define should_eq_error(exp, act) CuAssertIntEquals(tc, exp, act);

#define begin_blueprint(name) CuSuite* test_##name() { \
    CuSuite *suite = CuSuiteNew();

#define add_spec(property) SUITE_ADD_TEST(suite, _##property);

#define end_blueprint return suite; }

#define use_blueprint(bp) CuSuite* test_##bp();
#define add_blueprint(bp) CuSuiteAddSuite(suite, test_##bp());

#endif /* INCLUDE_spectacular_h__ */
