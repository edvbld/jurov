#include "spectacular.h"
#include "ast.h"

void on_add(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left + right;
}

void on_sub(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left - right;
}

void on_mul(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left * right;
}

void on_div(binary_operation *op, void *result)
{
    int left, right = 0;
    ast_visit(op->left_operand, &left);
    ast_visit(op->right_operand, &right);
    *((int *) result) = left / right;
}

void on_int(integer *i, void *result)
{
    *((int *) result) = i->value;
}

begin_spec(ast_walk, should_handle_addition_and_integer_nodes)
    int result;
    ast* tree;
    
    ast_callbacks callbacks;
    callbacks.on_addition = &on_add;
    callbacks.on_integer = &on_int;

    should_pass(new_binary_operation(ADDITION, new_integer(2), new_integer(3), 
                                     &tree))
    ast_walk(tree, callbacks, &result);
    should_eq_int(5, result)
end_spec

begin_spec(ast_walk, should_handle_all_arithmetic_nodes)
    int result = 0;
    ast *op0;
    ast *op1;
    ast *op2;
    ast *op3;
    ast *op4;
    
    ast_callbacks callbacks;
    callbacks.on_addition = &on_add;
    callbacks.on_subtraction = &on_sub;
    callbacks.on_multiplication = &on_mul;
    callbacks.on_division = &on_div;
    callbacks.on_integer = &on_int;

    /* (+ (* (- 5 2) (+ 1 1)) (/ 10 2)) */
    should_pass(new_binary_operation(ADDITION, new_integer(1), new_integer(1), 
                                     &op4))
    should_pass(new_binary_operation(SUBTRACTION, new_integer(5), 
                                     new_integer(2), &op3))
    should_pass(new_binary_operation(DIVISION, new_integer(10), 
                                     new_integer(2), &op2))
    should_pass(new_binary_operation(MULTIPLICATION, op3, op4, &op1))
    should_pass(new_binary_operation(ADDITION, op1, op2, &op0))
    ast_walk(op0, callbacks, &result);
    should_eq_int(11, result)
end_spec

begin_description(ast_walk)
    add_spec(should_handle_addition_and_integer_nodes)
    add_spec(should_handle_all_arithmetic_nodes)
end_description
