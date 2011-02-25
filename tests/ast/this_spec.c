#include "spectacular.h"
#include "ast.h"

begin_example(this, should_have_this_object_as_type)
    ast *node;
    
    node = new_this();
    should_eq_int(THIS_OBJECT, node->type)

    free(node);
end_example

begin_description(this)
    add_example(should_have_this_object_as_type)
end_description
