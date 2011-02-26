#include "stdio.h"
#include "spectacular.h"

int run_desc(CuSuite *desc)
{
    CuString *output = CuStringNew();
    CuSuiteRun(desc);
    CuSuiteSummary(desc, output);
    CuSuiteDetails(desc, output);
    printf("%s\n", output->buffer);
    return desc->failCount;
}
