#include "expectations.h"
#include "parser.h"

begin_example(ast_parser, should_return_an_ast_pointer)
    char *program = 
        "class Main { public static void main ( String[] args ) { } }";
    ast *tree;
    mj_main_class *mc;

    should_pass(parse_string(program, &tree))

    should_neq_ptr(NULL, tree)
    should_eq_int(MJ_MAIN_CLASS, tree->type)
    mc = (mj_main_class *) tree;
    should_neq_ptr(NULL, mc->class_id)
    should_eq_int(MJ_IDENTIFIER, mc->class_id->type)
    should_eq_str("Main", mc->class_id->name)
    should_neq_ptr(NULL, mc->parameter_id)
    should_eq_int(MJ_IDENTIFIER, mc->parameter_id->type)
    should_eq_str("args", mc->parameter_id->name)

    delete_parser(tree);
end_example

begin_description(ast_parser)
    add_example(should_return_an_ast_pointer)
end_description
