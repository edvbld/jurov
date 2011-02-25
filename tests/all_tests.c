#include "stdio.h"
#include "spectacular.h"

begin_blueprint(jurov)
    use_blueprint(ast)
    use_blueprint(lexer)
    use_blueprint(parser)
    use_blueprint(list)
    use_blueprint(errors)

    add_blueprint(ast)
    add_blueprint(lexer)
    add_blueprint(parser)
    add_blueprint(list)
    add_blueprint(errors)
end_blueprint

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
