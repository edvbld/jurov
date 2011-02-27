#ifndef INCLUDE_spectacular_h__
#define INCLUDE_spectacular_h__

#include "stdlib.h"
#include "CuTest.h"

#define begin_example(object, property) static void _##property(CuTest *tc) {

#define end_example }

#define should_eq_int(exp, act) CuAssertIntEquals(tc, exp, act);
#define should_neq_int(exp, act) CuAssertIntNotEquals(tc, exp, act);
#define should_eq_str(exp, act) CuAssertStrEquals(tc, exp, act);
#define should_eq_ptr(exp, act) CuAssertPtrEquals(tc, exp, act);
#define should_neq_ptr(exp, act) CuAssertPtrNotEquals(tc, exp, act);

#define begin_description(name) CuSuite* test_##name() { \
    CuSuite *suite = CuSuiteNew();

#define add_example(property) SUITE_ADD_TEST(suite, _##property);

#define end_description return suite; }

#define use_description(d) CuSuite* test_##d();
#define add_description(d) CuSuiteAddSuite(suite, test_##d());

int run_desc(CuSuite *desc);
#define run_description(d) run_desc(test_##d());

#endif /* INCLUDE_spectacular_h__ */
