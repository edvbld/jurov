#include "expectations.h"
#include "parser.h"

begin_example(ast_parser, should_create_an_ast_from_the_empty_program)
    char *program = 
        "class Main { public static void main ( String[] args ) { } }";
    ast *tree;
    mj_main_class *mc;
    mj_ast_list *classes, *stmts;

    should_pass(parse_string(program, &tree))

    should_neq_ptr(NULL, tree)
    should_eq_int(MJ_AST_LIST, tree->type);
    classes = (mj_ast_list *) tree;
    should_eq_int(1, classes->list->size);
    should_neq_ptr(NULL, classes->list->first);
    mc = (mj_main_class *) classes->list->first->data;
    should_eq_int(MJ_MAIN_CLASS, mc->type);
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
    mj_ast_list *classes, *stmts;
    mj_print *print;
    mj_boolean *bo;

    should_pass(parse_string(program, &tree))

    should_neq_ptr(NULL, tree)
    should_eq_int(MJ_AST_LIST, tree->type);
    classes = (mj_ast_list *) tree;
    should_eq_int(1, classes->list->size);
    should_neq_ptr(NULL, classes->list->first);
    mc = (mj_main_class *) classes->list->first->data;
    should_eq_int(MJ_MAIN_CLASS, mc->type);
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

begin_example(ast_parser, should_handle_several_classes)
    ast *tree;
    mj_ast_list *classes, *vars, *methods;
    mj_main_class *mc;
    mj_class *foo;
    char *program = 
        "class Main {\n"
        "   public static void main(String[] args) {\n"
        "   }}\n"
        "class Foo {\n"
        "}";

    should_pass(parse_string(program, &tree))
    should_eq_int(MJ_AST_LIST, tree->type)
    classes = (mj_ast_list *) tree;
    should_eq_int(2, classes->list->size)
    should_neq_ptr(NULL, classes->list->first)
    mc = classes->list->first->data;
    should_eq_int(MJ_MAIN_CLASS, mc->type)

    should_neq_ptr(NULL, classes->list->last)
    foo = classes->list->last->data;
    should_eq_int(MJ_CLASS, foo->type)
    should_eq_str("Foo", foo->id->name)
    should_eq_int(MJ_AST_LIST, foo->var_declarations->type)
    vars = (mj_ast_list *) foo->var_declarations;
    should_eq_int(0, vars->list->size)
    should_eq_int(MJ_AST_LIST, foo->method_declarations->type)
    methods = (mj_ast_list *) foo->method_declarations;
    should_eq_int(0, methods->list->size)

    delete_parser(tree);
end_example

begin_example(ast_parser, should_handle_variable_declarations)
    ast *tree;
    mj_ast_list *classes, *vars;
    mj_class *foo;
    mj_var_decl *var;
    char *program = 
        "class Main {\n"
        "   public static void main(String[] args) {\n"
        "   }}\n"
        "class Foo {\n"
        "   Foo f;\n"
        "   int x;\n"
        "   int[] xs;\n"
        "   boolean b;\n"
        "}";

    should_pass(parse_string(program, &tree))
    
    should_eq_int(MJ_AST_LIST, tree->type)
    classes = (mj_ast_list *) tree;
    should_eq_int(2, classes->list->size)
    should_neq_ptr(NULL, classes->list->last)
    foo = classes->list->last->data;
    should_eq_int(MJ_CLASS, foo->type)
    should_eq_str("Foo", foo->id->name)
    should_eq_int(MJ_AST_LIST, foo->var_declarations->type)
    vars = (mj_ast_list *) foo->var_declarations;
    should_eq_int(4, vars->list->size)
    var = vars->list->last->data;
    should_eq_int(MJ_TYPE_BOOLEAN, var->mj_type->mj_type)
    should_eq_str("b", var->id->name)
    var = vars->list->last->previous->data;
    should_eq_int(MJ_TYPE_INT_ARRAY, var->mj_type->mj_type)
    should_eq_str("xs", var->id->name)
    var = vars->list->last->previous->previous->data;
    should_eq_int(MJ_TYPE_INTEGER, var->mj_type->mj_type)
    should_eq_str("x", var->id->name)
    var = vars->list->first->data;
    should_eq_int(MJ_TYPE_USER_DEFINED, var->mj_type->mj_type)
    should_neq_ptr(NULL, var->mj_type->id)
    should_eq_str("Foo", var->mj_type->id->name)
    should_eq_str("f", var->id->name)
     
    delete_parser(tree);
end_example

begin_example(ast_parser, should_handle_method_declarations)
    ast *tree;
    mj_ast_list *classes, *vars, *methods, *args, *method_vars;
    mj_var_decl *a, *y;
    mj_class *d;
    mj_method_decl *m;
    mj_method_arg *arg;
    mj_boolean *ret;
    char *program = 
        "class Main {\n"
        "   public static void main(String[] args) {\n"
        "   }\n"
        "}\n"
        "class Double {\n"
        "   int[] a;\n"
        "   public int double(int x) {\n"
        "       int y;\n"
        "       return true;\n"
        "   }\n"
        "}";
    
    should_pass(parse_string(program, &tree))
    
    should_eq_int(MJ_AST_LIST, tree->type)
    classes = (mj_ast_list *) tree;
    should_eq_int(2, classes->list->size)
    should_neq_ptr(NULL, classes->list->last)
    
    d = classes->list->last->data;
    should_eq_int(MJ_CLASS, d->type)
    should_eq_str("Double", d->id->name)

    should_eq_int(MJ_AST_LIST, d->var_declarations->type)
    vars = (mj_ast_list *) d->var_declarations;
    should_eq_int(1, vars->list->size)

    a = vars->list->first->data;
    should_eq_int(MJ_VAR_DECL, a->type);
    should_eq_int(MJ_TYPE_INT_ARRAY, a->mj_type->mj_type)
    should_eq_str("a", a->id->name)
    
    methods = (mj_ast_list *) d->method_declarations;
    should_eq_int(1, methods->list->size)
    should_neq_ptr(NULL, methods->list->first)
    m = methods->list->first->data;
    should_eq_int(MJ_TYPE_INTEGER, m->return_type->mj_type)
    should_eq_str("double", m->id->name)
    args = m->arguments;
    should_eq_int(1, args->list->size)

    arg = args->list->first->data;
    should_eq_int(MJ_METHOD_ARG, arg->type)
    should_eq_int(MJ_TYPE_INTEGER, arg->mj_type->mj_type)
    should_eq_str("x", arg->id->name)

    method_vars = m->var_declarations;
    should_eq_int(1, method_vars->list->size)
    y =  method_vars->list->first->data;

    should_eq_int(MJ_VAR_DECL, y->type)
    should_eq_int(MJ_TYPE_INTEGER, y->mj_type->mj_type)
    should_eq_str("y", y->id->name)

    should_eq_int(0, m->statements->list->size)

    should_eq_int(MJ_BOOLEAN, m->return_expression->type)
    ret = (mj_boolean *) m->return_expression;
    should_eq_int(1, ret->value)
   
    delete_parser(tree);
end_example

begin_description(ast_parser)
    add_example(should_create_an_ast_from_the_empty_program)
    add_example(should_create_an_ast_for_the_boolean_printer_program)
    add_example(should_handle_several_classes)
    add_example(should_handle_variable_declarations)
    add_example(should_handle_method_declarations)
end_description
