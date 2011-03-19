#include "expectations.h"
#include "ast/mj_this.h"

begin_example(mj_this, should_have_mj_this_as_type)
    ast *node;
   
    should_pass(new_mj_this(&node))
    should_eq_int(MJ_THIS, node->type)

    free(node);
end_example

begin_description(mj_this)
    add_example(should_have_mj_this_as_type)
end_description
