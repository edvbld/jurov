#include "spectacular.h"

begin_blueprint(parser)
    use_blueprint(main_class_parser)
    use_blueprint(statement_parser)

    add_blueprint(main_class_parser)
    add_blueprint(statement_parser)
end_blueprint
