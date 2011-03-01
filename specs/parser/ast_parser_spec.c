#include "expectations.h"
#include "parser.h"

begin_example(ast_parser, should_create_an_ast_from_the_empty_program)
    char *program = 
        "class Main { public static void main ( String[] args ) { } }";
    ast *tree;
    mj_main_class *mc;
    mj_ast_list *stmts;

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
    should_neq_ptr(NULL, mc->statements)
    should_eq_int(MJ_AST_LIST, mc->statements->type)
    stmts = (mj_ast_list *) mc->statements;
    should_eq_int(0, stmts->list->size)

    delete_parser(tree);
end_example

begin_example(ast_parser, should_create_an_ast_for_the_boolean_printer_program)
    char *program =
        "class BooleanPrinter {\n"
        "   public static void main(String[] args) {\n"
        "       System.out.println(false);\n"
        "       System.out.println(true);\n"
        "   }\n"
        "}";
    ast *tree;
    mj_main_class *mc;
    mj_ast_list *stmts;
    mj_print *print;
    mj_boolean *bo;

    should_pass(parse_string(program, &tree))

    should_neq_ptr(NULL, tree)
    should_eq_int(MJ_MAIN_CLASS, tree->type)
    mc = (mj_main_class *) tree;
    should_neq_ptr(NULL, mc->class_id)
    should_eq_int(MJ_IDENTIFIER, mc->class_id->type)
    should_eq_str("BooleanPrinter", mc->class_id->name)
    should_neq_ptr(NULL, mc->parameter_id)
    should_eq_int(MJ_IDENTIFIER, mc->parameter_id->type)
    should_eq_str("args", mc->parameter_id->name)
    
    should_neq_ptr(NULL, mc->statements)
    should_eq_int(MJ_AST_LIST, mc->statements->type)
    stmts = (mj_ast_list *) mc->statements;
    should_eq_int(2, stmts->list->size)

    should_neq_ptr(NULL, stmts->list->first)
    print = (mj_print *) stmts->list->first->data;
    should_eq_int(MJ_PRINT, print->type)
    should_neq_ptr(NULL, print->expression)
    should_eq_int(MJ_BOOLEAN, print->expression->type);
    bo = (mj_boolean *) print->expression;
    should_eq_int(0, bo->value)

    should_neq_ptr(NULL, stmts->list->last)
    print = (mj_print *) stmts->list->last->data;
    should_eq_int(MJ_PRINT, print->type)
    should_neq_ptr(NULL, print->expression)
    should_eq_int(MJ_BOOLEAN, print->expression->type);
    bo = (mj_boolean *) print->expression;
    should_eq_int(1, bo->value)

    delete_parser(tree);
end_example

begin_description(ast_parser)
    add_example(should_create_an_ast_from_the_empty_program)
    add_example(should_create_an_ast_for_the_boolean_printer_program)
end_description
