#include "stdio.h"
#include "spectacular.h"

begin_description(jurov)
    use_description(ast)
    use_description(lexer)
    use_description(parser)
    use_description(list)
    use_description(errors)

    add_description(ast)
    add_description(lexer)
    add_description(parser)
    add_description(list)
    add_description(errors)
end_description

int run_all_tests()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, test_jurov());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    return suite->failCount;
}

int main()
{
    return run_all_tests();
}
