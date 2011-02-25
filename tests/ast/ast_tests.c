#ifndef __AST_TESTS_H__
#define __AST_TESTS_H__

#include "spectacular.h"

begin_blueprint(ast)
    use_blueprint(ast_list)
    use_blueprint(binary_operation)
    use_blueprint(ast_walk)
    use_blueprint(boolean)
    use_blueprint(call)
    use_blueprint(identifier)
    use_blueprint(integer)
    use_blueprint(main_class)
    use_blueprint(new_object)
    use_blueprint(print)
    use_blueprint(this)
    use_blueprint(unary_operation)

    add_blueprint(ast_list)
    add_blueprint(binary_operation)
    add_blueprint(ast_walk)
    add_blueprint(boolean)
    add_blueprint(call)
    add_blueprint(identifier)
    add_blueprint(integer)
    add_blueprint(main_class)
    add_blueprint(new_object)
    add_blueprint(print)
    add_blueprint(this)
    add_blueprint(unary_operation)
end_blueprint

#endif /* __AST_TESTS_H__ */
