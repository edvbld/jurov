%{
    #include "stddef.h"
    #include "list.h"
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

%type <tree> program main_class main_method begin_class 
             function_body statements statement print_statement expression
             class_declarations class_declaration variable_declarations 
             variable_declaration method_declarations type
             identifier
%destructor { delete_ast($$); } program main_class main_method begin_class 
                                function_body statements statement 
                                print_statement expression class_declarations
                                class_declaration variable_declarations 
                                variable_declaration method_declarations type
                                identifier
%destructor { jrv_free(&$$); } ID
%%
start: program { *result = $1; }

program: main_class class_declarations { mj_ast_list_prepend($2, $1); $$ = $2;}

main_class: begin_class main_method function_body RCURLY 
            { ast *mc; 
              new_mj_main_class($1, $2, $3, &mc);
              $$ = mc; }

main_method: MAIN LPAREN STRING LSQUARE RSQUARE ID RPAREN 
             { ast *a;
               new_mj_identifier($6, &a);
               $$ = a; }

class_declarations:  /* nothing, return an empty mj_ast_list */
                    { ast *node;
                      empty_mj_ast_list(&node);
                      $$ = node; }
                  | class_declaration class_declarations
                    { mj_ast_list_prepend($2, $1);
                      $$ = $2; }

class_declaration: begin_class variable_declarations method_declarations RCURLY
                   { ast *class;
                     new_mj_class($1, $2, $3, &class);
                     $$ = class; }

variable_declarations: /* nothing, return the empty list */
                       { ast *node;
                         empty_mj_ast_list(&node);
                         $$ = node; }
                     | variable_declaration variable_declarations
                       { mj_ast_list_prepend($2, $1);
                         $$ = $2; }

variable_declaration: type identifier SEMICOLON
                      { ast *var_decl;
                        new_mj_var_decl($1, $2, &var_decl);
                        $$ = var_decl; }

method_declarations: { ast *list;
                       empty_mj_ast_list(&list);
                       $$ = list; }

type: BOOLEAN 
      { ast *type;
        new_mj_type(MJ_TYPE_BOOLEAN, NULL, &type);
        $$ = type; }
    | INT
      { ast *type;
        new_mj_type(MJ_TYPE_INTEGER, NULL, &type);
        $$ = type; }
    | INT LSQUARE RSQUARE
      { ast *type;
        new_mj_type(MJ_TYPE_INT_ARRAY, NULL, &type);
        $$ = type; }
    | identifier
      { ast *type;
        new_mj_type(MJ_TYPE_USER_DEFINED, $1, &type);
        $$ = type; }

identifier: ID
            { ast *id;
              new_mj_identifier($1, &id);
              $$ = id; }

begin_class: CLASS identifier LCURLY { $$ = $2; }

function_body: LCURLY statements RCURLY { $$ = $2; }

statements: /* nothing, return an empty mj_ast_list */ 
            { ast *node;
              empty_mj_ast_list(&node);
              $$ = node; }
          | statement statements { mj_ast_list_prepend($2, $1); $$ = $2; }

statement: LCURLY statements RCURLY { $$ = $2; }
         | print_statement { $$ = $1; }

print_statement: PRINT LPAREN expression RPAREN SEMICOLON 
                 { ast *node;
                   new_mj_print($3, &node);
                   $$ = node; }
                

expression: TRUE { ast *node; new_mj_boolean(1, &node); $$ = node; }
          | FALSE { ast *node; new_mj_boolean(0, &node); $$ = node; }

%%

void yyerror(ast **result, char *s)
{
    /* do nothing for now */ 
}
