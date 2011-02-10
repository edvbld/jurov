%{
/* for cpp usage */
void yyerror(const char *s) {}
void clear_stack();
%}

%union {
    char* id;
    int num;
}

%token MAIN PUBLIC CLASS
%token PRINT LENGTH
%token LCURLY RCURLY LPAREN RPAREN LSQUARE RSQUARE
%token IF ELSE WHILE RETURN
%token TRUE FALSE
%token THIS NEW
%token BOOLEAN INT STRING
%token AND LESS PLUS MINUS MUL BANG DOT COMMA SEMICOLON
%token ID NUMBER

%%
program: main_class

main_class: CLASS ID LCURLY 
            MAIN LPAREN STRING LSQUARE RSQUARE ID RPAREN LCURLY 
            statements RCURLY
            RCURLY
            ;

statements: /* nothing for now */
          ;

%%
