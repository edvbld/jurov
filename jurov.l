%option noyywrap nodefault yylineno

%{
#include "jurov.tab.h"
%}

%%

"class"                                                 { return CLASS; }
"public"[\t\n ]+"static"[\t\n ]+"void"[\t\n ]+"main"    { return MAIN; }
"public"                                                { return PUBLIC; }
"System.out.println"                                    { return PRINT; }
"{"                                                     { return LCURLY; }
"}"                                                     { return RCURLY; }
"("                                                     { return LPAREN; }
")"                                                     { return RPAREN; }
"["                                                     { return LSQUARE; }
"]"                                                     { return RSQUARE; }
"if"                                                    { return IF; }
"else"                                                  { return ELSE; }
"while"                                                 { return WHILE; }
"true"                                                  { return TRUE; }
"false"                                                 { return FALSE; }
"this"                                                  { return THIS; }
"new"                                                   { return NEW; }
"length"                                                { return LENGTH; }
"boolean"                                               { return BOOLEAN; }
"int"                                                   { return INT; }
"String"                                                { return STRING; }
"return"                                                { return RETURN; }
"&&"                                                    { return AND; }
"<"                                                     { return LESS; }
"+"                                                     { return PLUS; }
"-"                                                     { return MINUS; }
"*"                                                     { return MUL; }
"!"                                                     { return BANG; }
"."                                                     { return DOT; }
","                                                     { return COMMA; }
";"                                                     { return SEMICOLON; }
[\t\n ]
.

%%

