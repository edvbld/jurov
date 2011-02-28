#include "expectations.h"
#include "ast.h"

begin_example(mj_binary_operation, should_have_the_given_type)
    mj_binary_operation *op;

    should_pass(new_mj_binary_operation(MJ_ADDITION, NULL, NULL, (ast **) &op))
    should_eq_int(MJ_ADDITION, op->type)

    free(op);
end_example

begin_example(mj_binary_operation, should_have_the_given_operands)
    ast *five; 
    ast *seven;
    mj_binary_operation *op;

    should_pass(new_mj_integer(5, &five))
    should_pass(new_mj_integer(7, &seven))
    should_pass(new_mj_binary_operation(MJ_ADDITION, five, seven, (ast **) &op))
    should_eq_ptr(five, op->left_operand)
    should_eq_ptr(seven, op->right_operand)

    free(five);
    free(seven);
    free(op);
end_example

begin_description(mj_binary_operation)
    add_example(should_have_the_given_type)
    add_example(should_have_the_given_operands)
end_description
