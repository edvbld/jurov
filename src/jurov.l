%option noyywrap nodefault yylineno nounput

%{
#include "jurov.tab.h"
%}

WS      ([\t\n ])

%%

"class"                                             { return CLASS; }
"public"{WS}+"static"{WS}+"void"{WS}+"main"         { return MAIN; }
"public"                                            { return PUBLIC; }
"System"{WS}*"."{WS}*"out"{WS}*"."{WS}*"println"    { return PRINT; }
"{"                                                 { return LCURLY; }
"}"                                                 { return RCURLY; }
"("                                                 { return LPAREN; }
")"                                                 { return RPAREN; }
"["                                                 { return LSQUARE; }
"]"                                                 { return RSQUARE; }
"if"                                                { return IF; }
"else"                                              { return ELSE; }
"while"                                             { return WHILE; }
"true"                                              { return TRUE; }
"false"                                             { return FALSE; }
"this"                                              { return THIS; }
"new"                                               { return NEW; }
"length"                                            { return LENGTH; }
"boolean"                                           { return BOOLEAN; }
"int"                                               { return INT; }
"String"                                            { return STRING; }
"return"                                            { return RETURN; }
"&&"                                                { return AND; }
"<"                                                 { return LESS; }
"+"                                                 { return PLUS; }
"-"                                                 { return MINUS; }
"*"                                                 { return MUL; }
"!"                                                 { return BANG; }
"."                                                 { return DOT; }
","                                                 { return COMMA; }
";"                                                 { return SEMICOLON; }
[a-zA-Z][a-zA-Z0-9]*                                { yylval.id = yytext;
                                                      return ID; }
[0-9]+                                              { yylval.number = 
                                                          atoi(yytext);
                                                      return NUMBER; }
[\t\n ]
.

%%

