#include "expectations.h"
#include "ast.h"
#include "jurov.tab.h"
#include "lex.yy.h"

int yyparse();
static int parse_program(char *program, ast **tree)
{
    int res = 0;
    yy_scan_string(program);
    res = yyparse(tree);
    yylex_destroy();
    return res;
}

begin_example(ast_parser, should_return_an_ast_pointer)
    char *program = 
        "class Main { public static void main ( String[] args ) { } }";
    ast *tree = NULL;
    main_class *mc;
    should_pass(parse_program(program, &tree))
    should_neq_ptr(NULL, tree)
    should_eq_int(MAIN_CLASS, tree->type)
    mc = (main_class *) tree;
    should_neq_ptr(NULL, mc->class_id)
    should_eq_int(IDENTIFIER, mc->class_id->type)
    should_eq_str("Main", mc->class_id->name)
    should_neq_ptr(NULL, mc->parameter_id)
    should_eq_int(IDENTIFIER, mc->parameter_id->type)
    should_eq_str("args", mc->parameter_id->name)

    /* TODO: Free stuff here */
end_example

begin_description(ast_parser)
    add_example(should_return_an_ast_pointer)
end_description
