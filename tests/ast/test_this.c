#include "spectacular.h"
#include "ast.h"

begin_spec(this, should_have_this_object_as_type)
    ast *node;
    
    node = new_this();
    should_eq_int(THIS_OBJECT, node->type)

    free(node);
end_spec

begin_description(this)
    add_spec(should_have_this_object_as_type)
end_description
