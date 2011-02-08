#include "CuTest.h"
#include "jurov.tab.h"
#include "lex.yy.h"

void should_lex_public_static_void_main_to_MAIN(CuTest *tc)
{
    yy_scan_string("public static void main");
    CuAssertIntEquals(tc, MAIN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_class_to_CLASS(CuTest *tc)
{
    yy_scan_string("class");
    CuAssertIntEquals(tc, CLASS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_public_to_PUBLIC(CuTest *tc)
{
    yy_scan_string("public");
    CuAssertIntEquals(tc, PUBLIC, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_system_out_println_to_PRINT(CuTest *tc)
{
    yy_scan_string("System.out.println");
    CuAssertIntEquals(tc, PRINT, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_left_curly_bracket_to_LCURLY(CuTest *tc)
{
    yy_scan_string("{");
    CuAssertIntEquals(tc, LCURLY, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_right_curly_bracket_to_RCURLY(CuTest *tc)
{
    yy_scan_string("}");
    CuAssertIntEquals(tc, RCURLY, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_left_bracket_to_LSQUARE(CuTest *tc)
{
    yy_scan_string("[");
    CuAssertIntEquals(tc, LSQUARE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_right_bracket_to_RSQUARE(CuTest *tc)
{
    yy_scan_string("]");
    CuAssertIntEquals(tc, RSQUARE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_left_parantheses_to_LPAREN(CuTest *tc)
{
    yy_scan_string("(");
    CuAssertIntEquals(tc, LPAREN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_right_parentheses_to_RPAREN(CuTest *tc)
{
    yy_scan_string(")");
    CuAssertIntEquals(tc, RPAREN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_if_to_IF(CuTest *tc)
{
    yy_scan_string("if");
    CuAssertIntEquals(tc, IF, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_else_to_ELSE(CuTest *tc)
{
    yy_scan_string("else");
    CuAssertIntEquals(tc, ELSE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_while_to_WHILE(CuTest *tc)
{
    yy_scan_string("while");
    CuAssertIntEquals(tc, WHILE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_true_to_TRUE(CuTest *tc)
{
    yy_scan_string("true");
    CuAssertIntEquals(tc, TRUE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_false_to_FALSE(CuTest *tc)
{
    yy_scan_string("false");
    CuAssertIntEquals(tc, FALSE, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_this_to_THIS(CuTest *tc)
{
    yy_scan_string("this");
    CuAssertIntEquals(tc, THIS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_new_to_NEW(CuTest *tc)
{
    yy_scan_string("new");
    CuAssertIntEquals(tc, NEW, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_return_to_RETURN(CuTest *tc)
{
    yy_scan_string("return");
    CuAssertIntEquals(tc, RETURN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_length_to_LENGTH(CuTest *tc)
{
    yy_scan_string("length");
    CuAssertIntEquals(tc, LENGTH, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_boolean_to_BOOLEAN(CuTest *tc)
{
    yy_scan_string("boolean");
    CuAssertIntEquals(tc, BOOLEAN, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_int_to_INT(CuTest *tc)
{
    yy_scan_string("int");
    CuAssertIntEquals(tc, INT, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_String_to_STRING(CuTest *tc)
{
    yy_scan_string("String");
    CuAssertIntEquals(tc, STRING, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_ampersand_ampersand_to_AND(CuTest *tc)
{
    yy_scan_string("&&");
    CuAssertIntEquals(tc, AND, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_less_than_to_LESS(CuTest *tc)
{
    yy_scan_string("<");
    CuAssertIntEquals(tc, LESS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_plus_to_PLUS(CuTest *tc)
{
    yy_scan_string("+");
    CuAssertIntEquals(tc, PLUS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_dash_to_MINUS(CuTest *tc)
{
    yy_scan_string("-");
    CuAssertIntEquals(tc, MINUS, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_star_to_MUL(CuTest *tc)
{
    yy_scan_string("*");
    CuAssertIntEquals(tc, MUL, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_bang_to_BANG(CuTest *tc)
{
    yy_scan_string("!");
    CuAssertIntEquals(tc, BANG, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_dot_to_DOT(CuTest *tc)
{
    yy_scan_string(".");
    CuAssertIntEquals(tc, DOT, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_comma_to_COMMA(CuTest *tc)
{
    yy_scan_string(",");
    CuAssertIntEquals(tc, COMMA, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_semicolon_to_SEMICOLON(CuTest *tc)
{
    yy_scan_string(";");
    CuAssertIntEquals(tc, SEMICOLON, yylex());
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_an_number_to_NUMBER_and_save_value(CuTest *tc)
{
    yy_scan_string("42");
    CuAssertIntEquals(tc, NUMBER, yylex());
    CuAssertIntEquals(tc, 42, yylval.num);
    CuAssertIntEquals(tc, 0, yylex());
}

void should_lex_an_id_to_ID_and_save_name(CuTest *tc)
{
    yy_scan_string("x");
    CuAssertIntEquals(tc, ID, yylex());
    CuAssertStrEquals(tc, "x", yylval.id);
    CuAssertIntEquals(tc, 0, yylex());

    yy_scan_string("publicc");
    CuAssertIntEquals(tc, ID, yylex());
    CuAssertStrEquals(tc, "publicc", yylval.id);
    CuAssertIntEquals(tc, 0, yylex());
    
    yy_scan_string("foo01");
    CuAssertIntEquals(tc, ID, yylex());
    CuAssertStrEquals(tc, "foo01", yylval.id);
    CuAssertIntEquals(tc, 0, yylex());
}

CuSuite* lexer_lex_single_token_test_suite()
{
    CuSuite *suite = CuSuiteNew();

    SUITE_ADD_TEST(suite, should_lex_public_static_void_main_to_MAIN);
    SUITE_ADD_TEST(suite, should_lex_public_to_PUBLIC);
    SUITE_ADD_TEST(suite, should_lex_system_out_println_to_PRINT);
    SUITE_ADD_TEST(suite, should_lex_left_curly_bracket_to_LCURLY);
    SUITE_ADD_TEST(suite, should_lex_right_curly_bracket_to_RCURLY);
    SUITE_ADD_TEST(suite, should_lex_left_bracket_to_LSQUARE);
    SUITE_ADD_TEST(suite, should_lex_right_bracket_to_RSQUARE);
    SUITE_ADD_TEST(suite, should_lex_left_parantheses_to_LPAREN);
    SUITE_ADD_TEST(suite, should_lex_right_parentheses_to_RPAREN);
    SUITE_ADD_TEST(suite, should_lex_if_to_IF);
    SUITE_ADD_TEST(suite, should_lex_else_to_ELSE);
    SUITE_ADD_TEST(suite, should_lex_while_to_WHILE);
    SUITE_ADD_TEST(suite, should_lex_true_to_TRUE);
    SUITE_ADD_TEST(suite, should_lex_false_to_FALSE);
    SUITE_ADD_TEST(suite, should_lex_this_to_THIS);
    SUITE_ADD_TEST(suite, should_lex_new_to_NEW);
    SUITE_ADD_TEST(suite, should_lex_return_to_RETURN);
    SUITE_ADD_TEST(suite, should_lex_length_to_LENGTH);
    SUITE_ADD_TEST(suite, should_lex_boolean_to_BOOLEAN);
    SUITE_ADD_TEST(suite, should_lex_int_to_INT);
    SUITE_ADD_TEST(suite, should_lex_String_to_STRING);
    SUITE_ADD_TEST(suite, should_lex_ampersand_ampersand_to_AND);
    SUITE_ADD_TEST(suite, should_lex_less_than_to_LESS);
    SUITE_ADD_TEST(suite, should_lex_plus_to_PLUS);
    SUITE_ADD_TEST(suite, should_lex_dash_to_MINUS);
    SUITE_ADD_TEST(suite, should_lex_star_to_MUL);
    SUITE_ADD_TEST(suite, should_lex_star_to_MUL);
    SUITE_ADD_TEST(suite, should_lex_bang_to_BANG);
    SUITE_ADD_TEST(suite, should_lex_dot_to_DOT);
    SUITE_ADD_TEST(suite, should_lex_comma_to_COMMA);
    SUITE_ADD_TEST(suite, should_lex_semicolon_to_SEMICOLON);
    SUITE_ADD_TEST(suite, should_lex_an_number_to_NUMBER_and_save_value);
    SUITE_ADD_TEST(suite, should_lex_an_id_to_ID_and_save_name);

    return suite;
}
