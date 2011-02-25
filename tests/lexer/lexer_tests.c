#include "spectacular.h"

begin_blueprint(lexer)
    use_blueprint(single_token_lexer)
    use_blueprint(multiple_token_lexer)

    add_blueprint(single_token_lexer)
    add_blueprint(multiple_token_lexer)
end_blueprint
