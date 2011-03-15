#include "stddef.h"
#include "string.h"
#include "errors.h"
#include "ast.h"
#include "utils.h"

static int invalid_type(ast **node)
{
    *node = NULL;
    return JRV_INVALID_TYPE;
}

static int is_of_type(nodetype type, ast *node)
{
    if(node == NULL) {
        return 2;
    }
    return node->type == type;
}

int new_mj_identifier(char *name, ast **node)
{
    mj_identifier *id;

    if(name == NULL || strlen(name) == 0) {
        *node = NULL;
        return JRV_INVALID_STRING;
    }

    id = jrv_malloc(sizeof(mj_identifier));
    id->name = name; 
    id->type = MJ_IDENTIFIER;
    *node = (ast *) id;
    return JRV_SUCCESS;
}

int new_mj_binary_operation(nodetype type, ast *left_operand, 
                            ast *right_operand, ast **node)
{
    mj_binary_operation *op = jrv_malloc(sizeof(mj_binary_operation));
    op->type = type;
    op->left_operand = left_operand;
    op->right_operand = right_operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

int new_mj_unary_operation(nodetype type, ast *operand, ast **node)
{
    mj_unary_operation *op = jrv_malloc(sizeof(mj_unary_operation));
    op->type = type;
    op->operand = operand;
    *node = (ast *) op;
    return JRV_SUCCESS;
}

int new_mj_integer(int value, ast **node)
{
    mj_integer *i = jrv_malloc(sizeof(mj_integer));
    i->value = value;
    i->type = MJ_INTEGER;
    *node = (ast *) i;
    return JRV_SUCCESS;
}

int new_mj_boolean(int value, ast **node)
{
    mj_boolean *b = jrv_malloc(sizeof(mj_boolean));
    b->type = MJ_BOOLEAN;
    b->value = value;
    *node = (ast *) b;
    return JRV_SUCCESS;
}

int new_mj_new_object(ast *class_id, ast **node)
{
    mj_new_object *no;
    
    if(class_id != NULL && class_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    no = jrv_malloc(sizeof(mj_new_object));
    no->type = MJ_NEW_OBJECT;
    no->class_id = (mj_identifier *) class_id;
    *node = (ast *) no;
    return JRV_SUCCESS;
}

int new_mj_ast_list(list *list, ast **node)
{
    mj_ast_list *al = jrv_malloc(sizeof(mj_ast_list));
    al->type = MJ_AST_LIST;
    al->list = list;
    *node = (ast *) al;
    return JRV_SUCCESS;
}

int empty_mj_ast_list(ast **node)
{
    list *l;
    mj_ast_list *al = jrv_malloc(sizeof(mj_ast_list));
    new_list(&l);
    al->type = MJ_AST_LIST;
    al->list = l;
    *node = (ast *) al;
    return JRV_SUCCESS;
}

int mj_ast_list_prepend(ast *list, ast *node)
{
    mj_ast_list *l;
    
    if(NULL == list) {
        return JRV_NULL_PTR_ERROR;
    }
    if(NULL == node) {
        return JRV_SUCCESS;
    }
    if(MJ_AST_LIST != list->type) {
        return JRV_INVALID_TYPE;
    }

    l = (mj_ast_list *) list;
    if(node->type == MJ_AST_LIST) {
        list_prepend_list(l->list, ((mj_ast_list *) node)->list);
        jrv_free(&node);
    } else {
        list_prepend_ele(l->list, node);
    }

    return JRV_SUCCESS;
}

int new_mj_call(ast *object, ast *method, mj_ast_list *parameters, ast **node)
{
    mj_call *c;
    
    if(method != NULL && method->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    c = jrv_malloc(sizeof(mj_call));
    c->type = MJ_CALL;
    c->object = object;
    c->method = (mj_identifier *) method;
    c->parameters = parameters;
    *node = (ast *) c;
    return JRV_SUCCESS;
}

int new_mj_this(ast **node)
{
    ast* this = jrv_malloc(sizeof(ast));
    this->type = MJ_THIS;
    *node = this;
    return JRV_SUCCESS;
}

int new_mj_print(ast* expression, ast **node)
{
    mj_print *p = jrv_malloc(sizeof(mj_print));
    p->type = MJ_PRINT;
    p->expression = expression;
    *node = (ast *) p;
    return JRV_SUCCESS;
}

int new_mj_main_class(ast *class_id, ast *parameter_id, ast* statements, 
                      ast **node)
{
    mj_main_class *mc;
    
    if(class_id != NULL && class_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }
    
    if(parameter_id != NULL && parameter_id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }
    
    mc = jrv_malloc(sizeof(mj_main_class));
    mc->type = MJ_MAIN_CLASS;
    mc->class_id = (mj_identifier *) class_id;
    mc->parameter_id = (mj_identifier *) parameter_id;
    mc->statements = statements;
    *node = (ast *) mc;
    return JRV_SUCCESS;
}

int new_mj_class(ast *id, ast *var_declarations,
                 ast *method_declarations, ast **node)
{
    mj_class *mc;

    if(id != NULL && id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    if(var_declarations != NULL && var_declarations->type != MJ_AST_LIST) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    if(method_declarations != NULL && 
       method_declarations->type != MJ_AST_LIST) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }
    
    mc = jrv_malloc(sizeof(mj_class));
    mc->type = MJ_CLASS;
    mc->id = (mj_identifier *) id;
    mc->var_declarations = var_declarations;
    mc->method_declarations = method_declarations;
    *node = (ast *) mc;
    return JRV_SUCCESS;
}

int new_mj_type(minijava_type type, ast *id, ast **node)
{
    mj_type *t;

    if(id != NULL && id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    t = jrv_malloc(sizeof(mj_type));
    t->type = MJ_TYPE;
    t->mj_type = type;
    if(type == MJ_TYPE_USER_DEFINED) {
        t->id = (mj_identifier *) id;
    } else {
        t->id = NULL;
    }
    *node = (ast *) t;
    return JRV_SUCCESS;
}

int new_mj_var_decl(ast *type, ast *id, ast **node)
{
    mj_var_decl *d;

    if(type != NULL && type->type != MJ_TYPE) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    if(id != NULL && id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    d = jrv_malloc(sizeof(mj_var_decl));
    d->type = MJ_VAR_DECL;
    d->mj_type = (mj_type *) type;
    d->id = (mj_identifier *) id;
    *node = (ast *) d;
    return JRV_SUCCESS;
}

int new_mj_method_arg(ast *type, ast *id, ast **node)
{
    mj_method_arg *a;

    if(type != NULL && type->type !=  MJ_TYPE) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    if(id != NULL && id->type != MJ_IDENTIFIER) {
        *node = NULL;
        return JRV_INVALID_TYPE;
    }

    a = jrv_malloc(sizeof(mj_method_arg));
    a->type = MJ_METHOD_ARG;
    a->mj_type = (mj_type *) type;
    a->id = (mj_identifier *) id;
    *node = (ast *) a;
    return JRV_SUCCESS;
}

int new_mj_method_body(ast *var_declarations, ast *statements, ast **node)
{
    mj_method_body *b;

    if(!is_of_type(MJ_AST_LIST, var_declarations)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_AST_LIST, statements)) {
        return invalid_type(node);
    }

    b = jrv_malloc(sizeof(mj_method_body));
    b->type = MJ_METHOD_BODY;
    b->var_declarations = (mj_ast_list *) var_declarations;
    b->statements = (mj_ast_list *) statements;
    *node = (ast *) b;
    return JRV_SUCCESS;
}

int mj_method_body_add_statement(ast *statement, ast *method_body)
{
    mj_method_body *b;
    if(!is_of_type(MJ_METHOD_BODY, method_body)) {
        return JRV_INVALID_TYPE;
    }
    
    b = (mj_method_body *) method_body;
    mj_ast_list_prepend((ast *) b->statements, statement);
    return JRV_SUCCESS;
}

int mj_method_body_add_var_decl(ast *var_decl, ast *method_body)
{
    mj_method_body *b;
    if(!is_of_type(MJ_METHOD_BODY, method_body)) {
        return JRV_INVALID_TYPE;
    }

    b = (mj_method_body *) method_body;
    mj_ast_list_prepend((ast *) b->var_declarations, var_decl);
    return JRV_SUCCESS;
}

int new_mj_method_decl(ast *return_type, ast *id, ast *arguments,
                       ast *body, ast *return_expression, ast **node)
{
    mj_method_decl *m;

    if(!is_of_type(MJ_TYPE, return_type)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }
    
    if(!is_of_type(MJ_AST_LIST, arguments)) {
        return invalid_type(node);
    }

    if(!is_of_type(MJ_METHOD_BODY, body)) {
        return invalid_type(node);
    }

    m = jrv_malloc(sizeof(mj_method_decl));
    m->type = MJ_METHOD_DECL;
    m->return_type = (mj_type *) return_type;
    m->id = (mj_identifier *) id;
    m->arguments = (mj_ast_list *) arguments;
    m->body = (mj_method_body *) body;
    m->return_expression = return_expression;
    *node = (ast *) m;
    return JRV_SUCCESS;
}

int new_mj_if(ast *condition, ast *true_statement, ast *false_statement, 
              ast **node)
{
    mj_if *mi;

    mi = jrv_malloc(sizeof(mj_if));
    mi->type = MJ_IF;
    mi->condition = condition;
    mi->true_statement = true_statement;
    mi->false_statement = false_statement;
    *node = (ast *) mi;
    return JRV_SUCCESS;
}

int new_mj_while(ast *condition, ast *statement, ast **node)
{
    mj_while *w;

    w = jrv_malloc(sizeof(mj_while));
    w->type = MJ_WHILE;
    w->condition = condition;
    w->statement = statement;
    *node = (ast *) w;
    return JRV_SUCCESS;
}

int new_mj_assignment(ast *id, ast *expression, ast **node)
{
    mj_assignment *a;

    if(!is_of_type(MJ_IDENTIFIER, id)) {
        return invalid_type(node);
    }

    a = jrv_malloc(sizeof(mj_assignment));
    a->type = MJ_ASSIGNMENT;
    a->id = (mj_identifier *) id;
    a->expression = expression;
    *node = (ast *) a;
    return JRV_SUCCESS;
}

ast_callbacks _callbacks;
void ast_walk(ast* tree, ast_callbacks callbacks, void *result)
{
    _callbacks = callbacks;
    ast_visit(tree, result);
}

void ast_visit(ast *node, void *result)
{
    if(node == NULL) {
        return;
    }
    switch(node->type) {
        case MJ_IDENTIFIER: 
            if(_callbacks.on_mj_identifier != NULL) {
                _callbacks.on_mj_identifier((mj_identifier *) node, result);
            }
            break;
        case MJ_ADDITION:
            if(_callbacks.on_mj_addition != NULL) {
                _callbacks.on_mj_addition((mj_binary_operation *) node, result);
            }
            break;
        case MJ_SUBTRACTION:
            if(_callbacks.on_mj_subtraction != NULL) {
                _callbacks.on_mj_subtraction((mj_binary_operation *) node, 
                                             result);
            }
            break;
        case MJ_DIVISION:
            if(_callbacks.on_mj_division != NULL) {
                _callbacks.on_mj_division((mj_binary_operation *) node, 
                                          result);
            }
            break;
        case MJ_MULTIPLICATION:
            if(_callbacks.on_mj_multiplication != NULL) {
                _callbacks.on_mj_multiplication((mj_binary_operation *) node, 
                                                result);
            }
            break;
        case MJ_LESS_THAN:
            if(_callbacks.on_mj_less_than != NULL) {
                _callbacks.on_mj_less_than((mj_binary_operation *) node, 
                                           result);
            }
            break;
        case MJ_ARRAY_LOOKUP:
            if(_callbacks.on_mj_array_lookup != NULL) {
                _callbacks.on_mj_array_lookup((mj_binary_operation *) node, 
                                              result);
            }
            break;
        case MJ_ARRAY_LENGTH:
            if(_callbacks.on_mj_array_length != NULL) {
                _callbacks.on_mj_array_length((mj_unary_operation *) node, 
                                              result);
            }
            break;
        case MJ_NOT:
            if(_callbacks.on_mj_not != NULL) {
                _callbacks.on_mj_not((mj_unary_operation *) node, result);
            }
            break;
        case MJ_NEW_ARRAY:
            if(_callbacks.on_mj_new_array != NULL) {
                _callbacks.on_mj_new_array((mj_unary_operation *) node, result);
            }
            break;
        case MJ_INTEGER:
            if(_callbacks.on_mj_integer != NULL) {
                _callbacks.on_mj_integer((mj_integer *) node, result);
            }
            break;
        case MJ_THIS:
            if(_callbacks.on_mj_this != NULL) {
                _callbacks.on_mj_this((ast *) node, result);
            }
            break;
        case MJ_BOOLEAN:
            if(_callbacks.on_mj_boolean != NULL) {
                _callbacks.on_mj_boolean((mj_boolean *) node, result);
            }
            break;
        case MJ_AST_LIST:
            if(_callbacks.on_mj_ast_list != NULL) {
                _callbacks.on_mj_ast_list((mj_ast_list *) node, result);
            }
            break;
        case MJ_NEW_OBJECT:
            if(_callbacks.on_mj_new_object != NULL) {
                _callbacks.on_mj_new_object((mj_new_object *) node, result);
            }
            break;
        case MJ_CALL:
            if(_callbacks.on_mj_call != NULL) {
                _callbacks.on_mj_call((mj_call *) node, result);
            }
            break;
        case MJ_PRINT:
            if(_callbacks.on_mj_print != NULL) {
                _callbacks.on_mj_print((mj_print *) node, result);
            }
            break;
        case MJ_MAIN_CLASS:
            if(_callbacks.on_mj_main_class != NULL) {
                _callbacks.on_mj_main_class((mj_main_class *) node, result);
            }
            break;
        case MJ_CLASS:
            if(_callbacks.on_mj_class != NULL) {
                _callbacks.on_mj_class((mj_class *) node, result);
            }
            break;
        case MJ_TYPE:
            if(_callbacks.on_mj_type != NULL) {
                _callbacks.on_mj_type((mj_type *) node, result);
            }
            break;
        case MJ_VAR_DECL:
            if(_callbacks.on_mj_var_decl != NULL) {
                _callbacks.on_mj_var_decl((mj_var_decl *) node, result);
            }
            break;
        case MJ_METHOD_ARG:
            if(_callbacks.on_mj_method_arg != NULL) {
                _callbacks.on_mj_method_arg((mj_method_arg *) node, result);
            }
            break;
        case MJ_METHOD_BODY:
            if(_callbacks.on_mj_method_body != NULL) {
                _callbacks.on_mj_method_body((mj_method_body *) node, result);
            }
            break;
        case MJ_METHOD_DECL:
            if(_callbacks.on_mj_method_decl != NULL) {
                _callbacks.on_mj_method_decl((mj_method_decl *) node, result);
            }
            break;
        case MJ_IF:
            if(_callbacks.on_mj_if != NULL) {
                _callbacks.on_mj_if((mj_if *) node, result);
            }
            break;
        case MJ_WHILE:
            if(_callbacks.on_mj_while != NULL) {
                _callbacks.on_mj_while((mj_while *) node, result);
            }
            break;
        default:
            jrv_die("Unknown AST node found");
    }
}

void delete_mj_this(ast *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_boolean(mj_boolean *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_integer(mj_integer *node, void *p)
{
    jrv_free(&node);
}

void delete_mj_identifier(mj_identifier *node, void *p)
{
    jrv_free(&node->name);
    jrv_free(&node);
}

void delete_mj_unary_operation(mj_unary_operation *node, void *p)
{
    ast_visit(node->operand, p);
    jrv_free(&node);
}

void delete_mj_binary_operation(mj_binary_operation *node, void *p)
{
    ast_visit(node->left_operand, p);
    ast_visit(node->right_operand, p);
    jrv_free(&node);
}

void delete_mj_new_object(mj_new_object *node, void *p)
{
    delete_mj_identifier(node->class_id, NULL);
    jrv_free(&node);
}

void delete_mj_ast_list_element(void *data)
{
    ast_visit((ast *) data, NULL);
}

void delete_mj_ast_list(mj_ast_list *node, void *p)
{
    delete_list_cb(node->list, &delete_mj_ast_list_element);
    jrv_free(&node);
}

void delete_mj_call(mj_call *node, void *p)
{
    ast_visit(node->object, p);
    delete_mj_identifier(node->method, p);
    delete_mj_ast_list(node->parameters, p);
    jrv_free(&node);
}

void delete_mj_print(mj_print *node, void *p)
{
    ast_visit(node->expression, p);
    jrv_free(&node);
}

void delete_mj_main_class(mj_main_class *node, void *p)
{
    delete_mj_identifier(node->class_id, p);
    delete_mj_identifier(node->parameter_id, p);
    ast_visit(node->statements, p);
    jrv_free(&node);
}

void delete_mj_class(mj_class *node, void *p)
{
    delete_mj_identifier(node->id, p);
    ast_visit(node->var_declarations, p);
    ast_visit(node->method_declarations, p);
    jrv_free(&node);
}

void delete_mj_type(mj_type *node, void *p)
{
    if(node->mj_type == MJ_TYPE_USER_DEFINED) {
        delete_mj_identifier(node->id, p);
    }
    jrv_free(&node);
}

void delete_mj_var_decl(mj_var_decl *node, void *p)
{
    delete_mj_type(node->mj_type, p);
    delete_mj_identifier(node->id, p);
    jrv_free(&node);
}

void delete_mj_method_arg(mj_method_arg *node, void *p)
{
    delete_mj_type(node->mj_type, p);
    delete_mj_identifier(node->id, p);
    jrv_free(&node);
}

void delete_mj_method_body(mj_method_body *node, void *p)
{
    delete_mj_ast_list(node->var_declarations, p);
    delete_mj_ast_list(node->statements, p);
    jrv_free(&node);
}

void delete_mj_method_decl(mj_method_decl *node, void *p)
{
    delete_mj_type(node->return_type, p);
    delete_mj_identifier(node->id, p);
    ast_visit((ast *) node->arguments, p);
    ast_visit((ast *) node->body, p);
    ast_visit(node->return_expression, p);
    jrv_free(&node);
}

void delete_mj_if(mj_if *node, void *p)
{
    ast_visit(node->condition, p);
    ast_visit(node->true_statement, p);
    ast_visit(node->false_statement, p);
    jrv_free(&node);
}

void delete_mj_while(mj_while *node, void *p)
{
    ast_visit(node->condition, p);
    ast_visit(node->statement, p);
    jrv_free(&node);
}

void delete_ast(ast *tree)
{
    ast_callbacks callbacks;
    callbacks.on_mj_identifier = &delete_mj_identifier;
    callbacks.on_mj_addition = &delete_mj_binary_operation;
    callbacks.on_mj_subtraction = &delete_mj_binary_operation;
    callbacks.on_mj_division = &delete_mj_binary_operation;
    callbacks.on_mj_multiplication = &delete_mj_binary_operation;
    callbacks.on_mj_less_than = &delete_mj_binary_operation;
    callbacks.on_mj_array_lookup = &delete_mj_binary_operation;
    callbacks.on_mj_array_length = &delete_mj_unary_operation;
    callbacks.on_mj_not = &delete_mj_unary_operation;
    callbacks.on_mj_new_array = &delete_mj_unary_operation;
    callbacks.on_mj_integer = &delete_mj_integer;
    callbacks.on_mj_this = &delete_mj_this;
    callbacks.on_mj_boolean = &delete_mj_boolean;
    callbacks.on_mj_ast_list = &delete_mj_ast_list;
    callbacks.on_mj_new_object = &delete_mj_new_object;
    callbacks.on_mj_call = &delete_mj_call;
    callbacks.on_mj_print = &delete_mj_print;
    callbacks.on_mj_main_class = &delete_mj_main_class;
    callbacks.on_mj_class = &delete_mj_class;
    callbacks.on_mj_type = &delete_mj_type;
    callbacks.on_mj_var_decl = &delete_mj_var_decl;
    callbacks.on_mj_method_arg = &delete_mj_method_arg;
    callbacks.on_mj_method_body = &delete_mj_method_body;
    callbacks.on_mj_method_decl = &delete_mj_method_decl;
    callbacks.on_mj_if = &delete_mj_if;
    callbacks.on_mj_while = &delete_mj_while;
    ast_walk(tree, callbacks, NULL);
}
