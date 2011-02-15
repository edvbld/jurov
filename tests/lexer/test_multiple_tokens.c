#include "CuTest.h"
#include "jurov.tab.h"
#include "lex.yy.h"

void should_lex_two_tokens_separated_by_space(CuTest *tc)
{
    yy_scan_string("public class");
    CuAssertIntEquals(tc, PUBLIC, yylex());
    CuAssertIntEquals(tc, CLASS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_public_static_void_main_with_different_spaces(CuTest *tc)
{
    char *test_str =
        " \t\npublic \n\t\n   \t  public \t \n"
        "\t  \tstatic\n void\t\n   \n main "
        "public\nclass \t\n";
    yy_scan_string(test_str);
    CuAssertIntEquals(tc, PUBLIC, yylex());
    CuAssertIntEquals(tc, MAIN, yylex());
    CuAssertIntEquals(tc, PUBLIC, yylex());
    CuAssertIntEquals(tc, CLASS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_multiple_different_parentheses(CuTest *tc)
{
    char *test_str = " )} {}\n{({}\t)[] {({][]{(";
    yy_scan_string(test_str);
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, LSQUARE, yylex());
    CuAssertIntEquals(tc, RSQUARE, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, RSQUARE, yylex());
    CuAssertIntEquals(tc, LSQUARE, yylex());
    CuAssertIntEquals(tc, RSQUARE, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_a_small_program_with_print(CuTest *tc)
{
    char *test_str =
        "public class Program\n"
        "{\n"
        "    public static void main(String[] args)\n"
        "    {\n"
        "        if(false) {\n"
        "            System.out.println(42);\n"
        "        } else {\n"
        "            System.out.println(1337);\n"
        "        }\n"
        "    }\n"
        "}";
            
    yy_scan_string(test_str);
    /* public class Program {*/
    CuAssertIntEquals(tc, PUBLIC, yylex());
    CuAssertIntEquals(tc, CLASS, yylex());
    CuAssertIntEquals(tc, ID, yylex());
    CuAssertStrEquals(tc, "Program", yylval.id);
    CuAssertIntEquals(tc, LCURLY, yylex());
    /* public static void main(String[] args) */
    CuAssertIntEquals(tc, MAIN, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, STRING, yylex());
    CuAssertIntEquals(tc, LSQUARE, yylex());
    CuAssertIntEquals(tc, RSQUARE, yylex());
    CuAssertIntEquals(tc, ID, yylex());
    CuAssertStrEquals(tc, "args", yylval.id);
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    /* if(false) { */
    CuAssertIntEquals(tc, IF, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, FALSE, yylex());
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    /* System.out.println(42); */
    CuAssertIntEquals(tc, PRINT, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, NUMBER, yylex());
    CuAssertIntEquals(tc, 42, yylval.number);
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, SEMICOLON, yylex());
    /* } else { */
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, ELSE, yylex());
    CuAssertIntEquals(tc, LCURLY, yylex());
    /* System.out.println(1337); */
    CuAssertIntEquals(tc, PRINT, yylex());
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, NUMBER, yylex());
    CuAssertIntEquals(tc, 1337, yylval.number);
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, SEMICOLON, yylex());
    /* }}} */
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}


CuSuite* lexer_test_multiple_tokens()
{
    CuSuite *the_lexer = CuSuiteNew();

    SUITE_ADD_TEST(the_lexer, should_lex_two_tokens_separated_by_space);
    SUITE_ADD_TEST(the_lexer, 
                   should_lex_public_static_void_main_with_different_spaces);
    SUITE_ADD_TEST(the_lexer, should_lex_multiple_different_parentheses);
    SUITE_ADD_TEST(the_lexer, should_lex_a_small_program_with_print);

    return the_lexer;
}
