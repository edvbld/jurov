%{
    #include "stddef.h"
    #include "ast.h"
    #include "utils.h"
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

%type <tree> program main_class main_method class_declaration 
             function_body
%destructor { delete_ast($$); } main_class main_method class_declaration 
                                function_body
%destructor { jrv_free(&$$); } ID
%%
program: main_class { *result = $1; }

main_class: class_declaration main_method function_body RCURLY 
            { ast *mc; 
              new_mj_main_class($1, $2, $3, &mc);
              $$ = mc; }

main_method: MAIN LPAREN STRING LSQUARE RSQUARE ID RPAREN 
             { ast *a;
               new_mj_identifier($6, &a);
               $$ = a; }

class_declaration: CLASS ID LCURLY { ast *id;
                                     new_mj_identifier($2, &id);
                                     $$ = id; }

function_body: LCURLY statements RCURLY { $$ = NULL; }

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
