extern "C" {
#include "../jurov.tab.h"
#include "../lex.yy.h"
}

#include <gtest/gtest.h>

TEST(LexSingleToken, Main) 
{
    yy_scan_string("public static void main");
    ASSERT_EQ(MAIN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Class) 
{
    yy_scan_string("class");
    ASSERT_EQ(CLASS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Public) 
{
    yy_scan_string("public");
    ASSERT_EQ(PUBLIC, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Print) 
{
    yy_scan_string("System.out.println");
    ASSERT_EQ(PRINT, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, LCurly) 
{
    yy_scan_string("{");
    ASSERT_EQ(LCURLY, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, RCurly) 
{
    yy_scan_string("}");
    ASSERT_EQ(RCURLY, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, LParen) 
{
    yy_scan_string("(");
    ASSERT_EQ(LPAREN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, RParen) 
{
    yy_scan_string(")");
    ASSERT_EQ(RPAREN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, LSquare) 
{
    yy_scan_string("[");
    ASSERT_EQ(LSQUARE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, RSquare) 
{
    yy_scan_string("]");
    ASSERT_EQ(RSQUARE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, If) 
{
    yy_scan_string("if");
    ASSERT_EQ(IF, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Else) 
{
    yy_scan_string("else");
    ASSERT_EQ(ELSE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, While) 
{
    yy_scan_string("while");
    ASSERT_EQ(WHILE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, True)
{
    yy_scan_string("true");
    ASSERT_EQ(TRUE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, False)
{
    yy_scan_string("false");
    ASSERT_EQ(FALSE, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, This)
{
    yy_scan_string("this");
    ASSERT_EQ(THIS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, New)
{
    yy_scan_string("new");
    ASSERT_EQ(NEW, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Length)
{
    yy_scan_string("length");
    ASSERT_EQ(LENGTH, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Boolean)
{
    yy_scan_string("boolean");
    ASSERT_EQ(BOOLEAN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Int)
{
    yy_scan_string("int");
    ASSERT_EQ(INT, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, String)
{
    yy_scan_string("String");
    ASSERT_EQ(STRING, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Return)
{
    yy_scan_string("return");
    ASSERT_EQ(RETURN, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, And)
{
    yy_scan_string("&&");
    ASSERT_EQ(AND, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Less)
{
    yy_scan_string("<");
    ASSERT_EQ(LESS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Plus)
{
    yy_scan_string("+");
    ASSERT_EQ(PLUS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Minus)
{
    yy_scan_string("-");
    ASSERT_EQ(MINUS, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Mul)
{
    yy_scan_string("*");
    ASSERT_EQ(MUL, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Bang)
{
    yy_scan_string("!");
    ASSERT_EQ(BANG, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Dot)
{
    yy_scan_string(".");
    ASSERT_EQ(DOT, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Comma)
{
    yy_scan_string(",");
    ASSERT_EQ(COMMA, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Semicolon)
{
    yy_scan_string(";");
    ASSERT_EQ(SEMICOLON, yylex());
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Number)
{
    yy_scan_string("42");
    ASSERT_EQ(NUMBER, yylex());
    ASSERT_EQ(42, yylval.num);
    ASSERT_EQ(0, yylex());
}

TEST(LexSingleToken, Id)
{
    yy_scan_string("x");
    ASSERT_EQ(ID, yylex());
    ASSERT_EQ(0, strcmp("x", yylval.id));
    ASSERT_EQ(0, yylex());

    yy_scan_string("publicc");
    ASSERT_EQ(ID, yylex());
    ASSERT_EQ(0, strcmp("publicc", yylval.id));
    ASSERT_EQ(0, yylex());
    
    yy_scan_string("foo01");
    ASSERT_EQ(ID, yylex());
    ASSERT_EQ(0, strcmp("foo01", yylval.id));
    ASSERT_EQ(0, yylex());
}
