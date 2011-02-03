extern "C" {
#include "jurov.tab.h"
#include "lex.yy.h"
}

#include <gtest/gtest.h>
#include <string>

TEST(LexMultipleTokens, PublicClass) 
{
    yy_scan_string("public class");
    ASSERT_EQ(PUBLIC, yylex());
    ASSERT_EQ(CLASS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexMultipleTokens, MainWithSpaces) 
{
    std::string test_str =
        " \t\npublic \n\t\n   \t  public \t \n"
        "\t  \tstatic\n void\t\n   \n main "
        "public\nclass \t\n";
    yy_scan_string(test_str.c_str());
    ASSERT_EQ(PUBLIC, yylex());
    ASSERT_EQ(MAIN, yylex());
    ASSERT_EQ(PUBLIC, yylex());
    ASSERT_EQ(CLASS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexMultipleTokens, MultipleDifferentParentesis)
{
    std::string test_str =
        " )} {}\n{({}\t)[] {({][]{(";
    yy_scan_string(test_str.c_str());
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(LSQUARE, yylex());
    ASSERT_EQ(RSQUARE, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(RSQUARE, yylex());
    ASSERT_EQ(LSQUARE, yylex());
    ASSERT_EQ(RSQUARE, yylex());
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexMultipleTokens, SmallProgramWithPrint)
{
    std::string test_str =
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
            
    yy_scan_string(test_str.c_str());
    /* public class Program {*/
    ASSERT_EQ(PUBLIC, yylex());
    ASSERT_EQ(CLASS, yylex());
    ASSERT_EQ(ID, yylex());
    ASSERT_EQ(0, strcmp(yylval.id, "Program"));
    ASSERT_EQ(LCURLY, yylex());
    /* public static void main(String[] args) */
    ASSERT_EQ(MAIN, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(STRING, yylex());
    ASSERT_EQ(LSQUARE, yylex());
    ASSERT_EQ(RSQUARE, yylex());
    ASSERT_EQ(ID, yylex());
    ASSERT_EQ(0, strcmp(yylval.id, "args"));
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(LCURLY, yylex());
    /* if(false) { */
    ASSERT_EQ(IF, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(FALSE, yylex());
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(LCURLY, yylex());
    /* System.out.println(42); */
    ASSERT_EQ(PRINT, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(NUMBER, yylex());
    ASSERT_EQ(42, yylval.num);
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(SEMICOLON, yylex());
    /* } else { */
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(ELSE, yylex());
    ASSERT_EQ(LCURLY, yylex());
    /* System.out.println(1337); */
    ASSERT_EQ(PRINT, yylex());
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(NUMBER, yylex());
    ASSERT_EQ(1337, yylval.num);
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(SEMICOLON, yylex());
    /* }}} */
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(0, yylex());
}
