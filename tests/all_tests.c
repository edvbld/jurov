#include "stdio.h"
#include "spectacular.h"
#include "list/list_tests.h"
#include "errors/errors_tests.h"

begin_blueprint(jurov)
    use_blueprint(ast)
    use_blueprint(lexer)
    use_blueprint(parser)

    add_blueprint(ast)
    add_blueprint(lexer)
    add_blueprint(parser)
end_blueprint

int run_all_tests()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, test_jurov());
    CuSuiteAddSuite(suite, list_tests());
    CuSuiteAddSuite(suite, errors_tests());
    
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
