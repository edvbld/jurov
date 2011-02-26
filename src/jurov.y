%{
    #include "ast.h"
    void yyerror(ast **result, char *s);
    int yylex(void);
%}

%parse-param {ast **result}

%union {
    char* id;
    int number;
    struct ast_ *tree;
}

%token MAIN PUBLIC CLASS
%token PRINT LENGTH
%token LCURLY RCURLY LPAREN RPAREN LSQUARE RSQUARE
%token IF ELSE WHILE RETURN
%token TRUE FALSE
%token THIS NEW
%token BOOLEAN INT STRING
%token AND LESS PLUS MINUS MUL BANG DOT COMMA SEMICOLON
%token <id> ID
%token <number> NUMBER

%type <tree> start program 

%%
/* This rule is just for retuning the created AST */
start: program {*result = $1;}

program: main_class {$$ = 0}

main_class: class_declaration 
            MAIN LPAREN STRING LSQUARE RSQUARE ID RPAREN 
            function_body
            RCURLY

class_declaration: CLASS ID LCURLY

function_body: LCURLY statements RCURLY

statements: /* nothing */
          | statement statements

statement: LCURLY statements RCURLY
         | print_statement

print_statement: PRINT LPAREN expression RPAREN SEMICOLON

expression: TRUE
          | FALSE

%%

void yyerror(ast **result, char *s)
{
    /* do nothing for now */ 
}
