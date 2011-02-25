#include "spectacular.h"
#include "ast.h"

static unary_operation* create(nodetype type, ast *operand)
{
    return (unary_operation *) new_unary_operation(type, operand);
}

begin_example(unary_operation, should_have_unary_operation_as_type)
    unary_operation *node;
    
    node = create(NOT, NULL);
    should_eq_int(NOT, node->type)

    free(node);
end_example

begin_example(unary_operation, should_have_the_given_operand_as_member)
    ast *b; 
    unary_operation *node;
    
    b = new_boolean(0);
    node = create(NOT, b);
    should_eq_ptr(b, node->operand)
    
    free(b);
    free(node);
end_example

begin_description(unary_operation)
    add_example(should_have_unary_operation_as_type)
    add_example(should_have_the_given_operand_as_member)
end_description
