#ifndef INCLUDE_jrv_parser_h__
#define INCLUDE_jrv_parser_h__

#include "ast.h"
#include "lex.yy.h"

/**
 * Parses the given string into an AST pointer.
 *
 * @param str The string to parse
 * @param tree A pointer to the pointer to store the result in
 *
 * @returns An integer describing if the function was successful or not
 */
int parse_string(char *str, ast **tree);

/**
 * Parses the given file into an AST.
 *
 * @param stream The file to parser
 * @param tree A pointer to the pointer to store the result in
 *
 * @return The result of the function
 */
int parse_file(FILE *stream, ast **tree);

/**
 * Frees all the data allocated during the parsing
 *
 * @param tree The AST to delete
 */
void delete_parser(ast *tree);

#endif /* INCLUDE_jrv_parser_h__ */
