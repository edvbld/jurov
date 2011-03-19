#ifndef INCLUDE_jrv_ast_h__
#define INCLUDE_jrv_ast_h__

#include "ast/ast2.h"
#include "ast/mj_identifier.h"
#include "ast/mj_unary_operation.h"
#include "ast/mj_binary_operation.h"
#include "ast/mj_integer.h"
#include "ast/mj_boolean.h"
#include "ast/mj_new_object.h"
#include "ast/ast_list.h"
#include "ast/mj_call.h"
#include "ast/mj_this.h"
#include "ast/mj_print.h"
#include "ast/mj_main_class.h"
#include "ast/mj_class.h"
#include "ast/mj_type.h"
#include "ast/mj_var_decl.h"
#include "ast/mj_method_arg.h"
#include "ast/mj_method_body.h"
#include "ast/mj_method_decl.h"
#include "ast/mj_if.h"
#include "ast/mj_while.h"
#include "ast/mj_assignment.h"
#include "ast/mj_array_assignment.h"
#include "ast/ast_walker.h"

/** 
 * Formats the ast into a string that is suitable for printing
 *
 * @param tree The AST to format
 * @result A string representation of the tree
 */
char* ast_format(ast *tree);

#endif /* INCLUDE_jrv_ast_h__ */
