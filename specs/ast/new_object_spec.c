#include "expectations.h"
#include "ast.h"

begin_example(mj_new_object, should_have_mj_new_object_as_type)
    ast *class_id;
    mj_new_object *node;

    should_pass(new_mj_identifier("foo", &class_id))
    should_pass(new_mj_new_object(class_id, (ast **) &node))
    should_eq_int(MJ_NEW_OBJECT, node->type)

    free(class_id);
    free(node);
end_example

begin_example(mj_new_object, should_have_the_given_class_id_as_member)
    ast *class_id;
    mj_new_object *node;

    should_pass(new_mj_identifier("foo", &class_id))
    should_pass(new_mj_new_object(class_id, (ast **) &node))
    should_eq_ptr(class_id, node->class_id);

    free(class_id);
    free(node);
end_example

begin_description(mj_new_object)
    add_example(should_have_mj_new_object_as_type)
    add_example(should_have_the_given_class_id_as_member)
end_description
