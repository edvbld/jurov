#include "CuTest.h"
#include "stdio.h"
#include "ast/ast_tests.h"
#include "list/list_tests.h"
#include "lexer/lexer_tests.h"
#include "parser/parser_tests.h"

void run_all_tests()
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, ast_tests());
    CuSuiteAddSuite(suite, list_tests());
    CuSuiteAddSuite(suite, lexer_tests());
    CuSuiteAddSuite(suite, parser_tests());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main()
{
    run_all_tests();
}
