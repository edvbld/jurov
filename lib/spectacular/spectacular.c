#include "stdio.h"
#include "spectacular.h"

void add_suite(CuSuite *suite, CuSuite *suite2)
{
    CuSuiteAddSuite(suite, suite2);
    free(suite2);
}

int run_desc(CuSuite *desc)
{
    int failed = 0;
    CuString *output = CuStringNew();
    CuSuiteRun(desc);
    CuSuiteSummary(desc, output);
    CuSuiteDetails(desc, output);
    printf("%s\n", output->buffer);
    failed = desc->failCount;
    CuStringDelete(output);
    CuSuiteDelete(desc);
    return failed;
}
