#include "spectacular.h"

begin_description(lexer)
    use_description(single_token_lexer)
    use_description(multiple_token_lexer)

    add_description(single_token_lexer)
    add_description(multiple_token_lexer)
end_description
