#include "expectations.h"
#include "ast/mj_boolean.h"
#include "ast/mj_unary_operation.h"

begin_example(mj_unary_operation, should_have_mj_unary_operation_as_type)
    mj_unary_operation *node;

    should_pass(new_mj_unary_operation(MJ_NOT, NULL, (ast **) &node))
    should_eq_int(MJ_NOT, node->type)

    free(node);
end_example

begin_example(mj_unary_operation, should_have_the_given_operand_as_member)
    ast *operand;
    mj_unary_operation *node;
    
    should_pass(new_mj_boolean(0, &operand))
    should_pass(new_mj_unary_operation(MJ_NOT, operand, (ast **) &node))
    should_eq_ptr(operand, node->operand)
    
    free(operand);
    free(node);
end_example

begin_description(mj_unary_operation)
    add_example(should_have_mj_unary_operation_as_type)
    add_example(should_have_the_given_operand_as_member)
end_description
