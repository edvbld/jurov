#include "expectations.h"
#include "ast.h"

begin_example(binary_operation, should_have_the_given_type)
    binary_operation *op;

    should_pass(new_binary_operation(ADDITION, NULL, NULL, (ast **) &op))
    should_eq_int(ADDITION, op->type)

    free(op);
end_example

begin_example(binary_operation, should_have_the_given_operands)
    ast *five; 
    ast *seven;
    binary_operation *op;

    should_pass(new_integer(5, &five))
    should_pass(new_integer(7, &seven))
    should_pass(new_binary_operation(ADDITION, five, seven, (ast **) &op))
    should_eq_ptr(five, op->left_operand)
    should_eq_ptr(seven, op->right_operand)

    free(five);
    free(seven);
    free(op);
end_example

begin_description(binary_operation)
    add_example(should_have_the_given_type)
    add_example(should_have_the_given_operands)
end_description
