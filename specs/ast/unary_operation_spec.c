#include "expectations.h"
#include "ast.h"

begin_example(unary_operation, should_have_unary_operation_as_type)
    unary_operation *node;

    should_pass(new_unary_operation(NOT, NULL, (ast **) &node))
    should_eq_int(NOT, node->type)

    free(node);
end_example

begin_example(unary_operation, should_have_the_given_operand_as_member)
    ast *operand; 
    unary_operation *node;
    
    operand = new_boolean(0);
    should_pass(new_unary_operation(NOT, operand, (ast **) &node))
    should_eq_ptr(operand, node->operand)
    
    free(operand);
    free(node);
end_example

begin_description(unary_operation)
    add_example(should_have_unary_operation_as_type)
    add_example(should_have_the_given_operand_as_member)
end_description
