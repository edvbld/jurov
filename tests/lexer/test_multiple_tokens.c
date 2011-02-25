#include "spectacular.h"
#include "jurov.tab.h"
#include "lex.yy.h"

begin_spec(multiple_token_lexer, should_lex_two_tokens_separated_by_space)
    yy_scan_string("public class");
    should_eq_int(PUBLIC, yylex())
    should_eq_int(CLASS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(multiple_token_lexer, 
           should_lex_public_static_void_main_with_different_spaces)
    char *test_str =
        " \t\npublic \n\t\n   \t  public \t \n"
        "\t  \tstatic\n void\t\n   \n main "
        "public\nclass \t\n";
    yy_scan_string(test_str);
    should_eq_int(PUBLIC, yylex())
    should_eq_int(MAIN, yylex())
    should_eq_int(PUBLIC, yylex())
    should_eq_int(CLASS, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(multiple_token_lexer, should_lex_multiple_different_parentheses)
    char *test_str = " )} {}\n{({}\t)[] {({][]{(";
    yy_scan_string(test_str);
    should_eq_int(RPAREN, yylex())
    should_eq_int(RCURLY, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(RCURLY, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(RCURLY, yylex())
    should_eq_int(RPAREN, yylex())
    should_eq_int(LSQUARE, yylex())
    should_eq_int(RSQUARE, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(RSQUARE, yylex())
    should_eq_int(LSQUARE, yylex())
    should_eq_int(RSQUARE, yylex())
    should_eq_int(LCURLY, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(0, yylex())
end_spec

begin_spec(multiple_token_lexer, should_lex_a_small_program_with_print)
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
    should_eq_int(PUBLIC, yylex())
    should_eq_int(CLASS, yylex())
    should_eq_int(ID, yylex())
    should_eq_str("Program", yylval.id)
    should_eq_int(LCURLY, yylex())
    /* public static void main(String[] args) */
    should_eq_int(MAIN, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(STRING, yylex())
    should_eq_int(LSQUARE, yylex())
    should_eq_int(RSQUARE, yylex())
    should_eq_int(ID, yylex())
    should_eq_str("args", yylval.id)
    should_eq_int(RPAREN, yylex())
    should_eq_int(LCURLY, yylex())
    /* if(false) { */
    should_eq_int(IF, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(FALSE, yylex())
    should_eq_int(RPAREN, yylex())
    should_eq_int(LCURLY, yylex())
    /* System.out.println(42) */
    should_eq_int(PRINT, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(NUMBER, yylex())
    should_eq_int(42, yylval.number)
    should_eq_int(RPAREN, yylex())
    should_eq_int(SEMICOLON, yylex())
    /* } else { */
    should_eq_int(RCURLY, yylex())
    should_eq_int(ELSE, yylex())
    should_eq_int(LCURLY, yylex())
    /* System.out.println(1337) */
    should_eq_int(PRINT, yylex())
    should_eq_int(LPAREN, yylex())
    should_eq_int(NUMBER, yylex())
    should_eq_int(1337, yylval.number)
    should_eq_int(RPAREN, yylex())
    should_eq_int(SEMICOLON, yylex())
    /* }}} */
    should_eq_int(RCURLY, yylex())
    should_eq_int(RCURLY, yylex())
    should_eq_int(RCURLY, yylex())
    should_eq_int(0, yylex())
end_spec

begin_description(multiple_token_lexer)
    add_spec(should_lex_two_tokens_separated_by_space)
    add_spec(should_lex_public_static_void_main_with_different_spaces)
    add_spec(should_lex_multiple_different_parentheses)
    add_spec(should_lex_a_small_program_with_print)
end_description
