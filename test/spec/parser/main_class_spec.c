#include "expectations.h"
#include "parser.h"

begin_example(main_class_parser,
           should_parse_a_program_consisting_of_only_main_class)
    char *program = 
        "class Main {\n"
        "public static void main(String[] args) {\n"
        "}}";
    ast *tree;
    should_pass(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser, should_fail_when_missing_main_function)
    char *program =
        "class Main {\n"
        "public static void start(String[] args) {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
              should_fail_when_missing_static_in_main_function)
    char *program =
        "class Main {\n"
        "public void main(String[] args) {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
              should_fail_when_missing_public_in_main_function)
    char *program =
        "class Main {\n"
        "static void main(String[] args) {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
           should_fail_when_not_taking_string_array_as_argument)
    char *program =
        "class Main {\n"
        "public static void main(String args) {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
           should_fail_when_missing_right_parenthesis_around_main_function)
    char *program =
        "class Main {\n"
        "public static void main(String args {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
           should_fail_when_missing_left_parenthesis_around_main_function)
    char *program =
        "class Main {\n"
        "public static void main String args) {\n"
        "}}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser, should_fail_when_missing_main_function_body)
    char *program =
        "class Main {\n"
        "public static void main(String args) \n"
        "}";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_example(main_class_parser,
           should_fail_when_missing_class_around_main_function)
    char *program =
        "public static void main(String args) \n";
    ast *tree;
    should_fail(parse_string(program, &tree))
    delete_parser(tree);
end_example

begin_description(main_class_parser)
    add_example(should_parse_a_program_consisting_of_only_main_class)
    add_example(should_fail_when_missing_main_function)
    add_example(should_fail_when_missing_static_in_main_function)
    add_example(should_fail_when_missing_public_in_main_function)
    add_example(should_fail_when_not_taking_string_array_as_argument)
    add_example(should_fail_when_missing_right_parenthesis_around_main_function)
    add_example(should_fail_when_missing_left_parenthesis_around_main_function)
    add_example(should_fail_when_missing_main_function_body)
    add_example(should_fail_when_missing_class_around_main_function)
end_description
