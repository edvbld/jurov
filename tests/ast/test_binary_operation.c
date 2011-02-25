#include "spectacular.h"
#include "ast.h"

begin_spec(binary_operation, should_have_the_given_type)
    binary_operation *op;

    should_pass(new_binary_operation(ADDITION, NULL, NULL, (ast **) &op))
    should_eq_int(ADDITION, op->type)

    free(op);
end_spec

begin_spec(binary_operation, should_have_the_given_operands)
    ast *left = new_integer(5);
    ast *right = new_integer(7);
    binary_operation *op;

    should_pass(new_binary_operation(ADDITION, left, right, (ast **) &op))
    should_eq_ptr(left, op->left_operand)
    should_eq_ptr(right, op->right_operand)

    free(left);
    free(right);
    free(op);
end_spec

begin_blueprint(binary_operation)
    add_spec(should_have_the_given_type)
    add_spec(should_have_the_given_operands)
end_blueprint
