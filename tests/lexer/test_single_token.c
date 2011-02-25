#include "spectacular.h"
#include "jurov.tab.h"
#include "lex.yy.h"

begin_spec(single_token_lexer, should_lex_public_static_void_main_to_MAIN)
    yy_scan_string("public static void main");
    should_eq_int(MAIN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_class_to_CLASS)
    yy_scan_string("class");
    should_eq_int(CLASS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_public_to_PUBLIC)
    yy_scan_string("public");
    should_eq_int(PUBLIC, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_system_out_println_to_PRINT)
    yy_scan_string("System.out.println");
    should_eq_int(PRINT, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_left_curly_bracket_to_LCURLY)
    yy_scan_string("{");
    should_eq_int(LCURLY, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_right_curly_bracket_to_RCURLY)
    yy_scan_string("}");
    should_eq_int(RCURLY, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_left_bracket_to_LSQUARE)
    yy_scan_string("[");
    should_eq_int(LSQUARE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_right_bracket_to_RSQUARE)
    yy_scan_string("]");
    should_eq_int(RSQUARE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_left_parantheses_to_LPAREN)
    yy_scan_string("(");
    should_eq_int(LPAREN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_right_parentheses_to_RPAREN)
    yy_scan_string(")");
    should_eq_int(RPAREN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_if_to_IF)
    yy_scan_string("if");
    should_eq_int(IF, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_else_to_ELSE)
    yy_scan_string("else");
    should_eq_int(ELSE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_while_to_WHILE)
    yy_scan_string("while");
    should_eq_int(WHILE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_true_to_TRUE)
    yy_scan_string("true");
    should_eq_int(TRUE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_false_to_FALSE)
    yy_scan_string("false");
    should_eq_int(FALSE, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_this_to_THIS)
    yy_scan_string("this");
    should_eq_int(THIS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_new_to_NEW)
    yy_scan_string("new");
    should_eq_int(NEW, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_return_to_RETURN)
    yy_scan_string("return");
    should_eq_int(RETURN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_length_to_LENGTH)
    yy_scan_string("length");
    should_eq_int(LENGTH, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_boolean_to_BOOLEAN)
    yy_scan_string("boolean");
    should_eq_int(BOOLEAN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_int_to_INT)
    yy_scan_string("int");
    should_eq_int(INT, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_String_to_STRING)
    yy_scan_string("String");
    should_eq_int(STRING, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_ampersand_ampersand_to_AND)
    yy_scan_string("&&");
    should_eq_int(AND, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_less_than_to_LESS)
    yy_scan_string("<");
    should_eq_int(LESS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_plus_to_PLUS)
    yy_scan_string("+");
    should_eq_int(PLUS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_dash_to_MINUS)
    yy_scan_string("-");
    should_eq_int(MINUS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_star_to_MUL)
    yy_scan_string("*");
    should_eq_int(MUL, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_bang_to_BANG)
    yy_scan_string("!");
    should_eq_int(BANG, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_dot_to_DOT)
    yy_scan_string(".");
    should_eq_int(DOT, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_comma_to_COMMA)
    yy_scan_string(",");
    should_eq_int(COMMA, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_semicolon_to_SEMICOLON)
    yy_scan_string(";");
    should_eq_int(SEMICOLON, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_an_number_to_NUMBER_and_save_value)
    yy_scan_string("42");
    should_eq_int(NUMBER, yylex())
    should_eq_int(42, yylval.number)
    should_eq_int(0, yylex())
end_spec

begin_spec(single_token_lexer, should_lex_an_id_to_ID_and_save_name)
    yy_scan_string("x");
    should_eq_int(ID, yylex())
    should_eq_str("x", yylval.id)
    should_eq_int(0, yylex())

    yy_scan_string("publicc");
    should_eq_int(ID, yylex())
    should_eq_str("publicc", yylval.id)
    should_eq_int(0, yylex())
    
    yy_scan_string("foo01");
    should_eq_int(ID, yylex())
    should_eq_str("foo01", yylval.id)
    should_eq_int(0, yylex())
end_spec

begin_blueprint(single_token_lexer)
    add_spec(should_lex_public_static_void_main_to_MAIN)
    add_spec(should_lex_public_to_PUBLIC)
    add_spec(should_lex_system_out_println_to_PRINT)
    add_spec(should_lex_left_curly_bracket_to_LCURLY)
    add_spec(should_lex_right_curly_bracket_to_RCURLY)
    add_spec(should_lex_left_bracket_to_LSQUARE)
    add_spec(should_lex_right_bracket_to_RSQUARE)
    add_spec(should_lex_left_parantheses_to_LPAREN)
    add_spec(should_lex_right_parentheses_to_RPAREN)
    add_spec(should_lex_if_to_IF)
    add_spec(should_lex_else_to_ELSE)
    add_spec(should_lex_while_to_WHILE)
    add_spec(should_lex_true_to_TRUE)
    add_spec(should_lex_false_to_FALSE)
    add_spec(should_lex_this_to_THIS)
    add_spec(should_lex_new_to_NEW)
    add_spec(should_lex_return_to_RETURN)
    add_spec(should_lex_length_to_LENGTH)
    add_spec(should_lex_boolean_to_BOOLEAN)
    add_spec(should_lex_int_to_INT)
    add_spec(should_lex_String_to_STRING)
    add_spec(should_lex_ampersand_ampersand_to_AND)
    add_spec(should_lex_less_than_to_LESS)
    add_spec(should_lex_plus_to_PLUS)
    add_spec(should_lex_dash_to_MINUS)
    add_spec(should_lex_star_to_MUL)
    add_spec(should_lex_star_to_MUL)
    add_spec(should_lex_bang_to_BANG)
    add_spec(should_lex_dot_to_DOT)
    add_spec(should_lex_comma_to_COMMA)
    add_spec(should_lex_semicolon_to_SEMICOLON)
    add_spec(should_lex_an_number_to_NUMBER_and_save_value)
    add_spec(should_lex_an_id_to_ID_and_save_name)
end_blueprint
