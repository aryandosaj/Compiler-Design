%{
#include <stdio.h>
int lineno;
%}
%option noyywrap
D [0-9]
L [a-zA-Z]
W ([a-zA-Z]|[0-9]|[.|_|$|#])
C [A-Z]
%%
[\t]+
int|float|char|double|if|for|do|while|long|short|static|void|else|goto   {printf("Keywords: %s",yytext);}
(({D}|{D}{D}|[0-2]{D}{D})\.({D}|{D}{D}|[0-2]{D}{D})\.({D}|{D}{D}|[0-2]{D}{D})\.({D}|{D}{D}|[0-2]{D}{D})) {printf("IP Address :%s",yytext);}
({W}@{W}(\.com)) {printf("Email : %s",yytext);}
(0x{D}+) {printf("HexaDecimal : %s",yytext);}
(("L"|"I"){D}+) {printf("Long Integer : %s",yytext);}
({C})(.*\.) {printf("Sentence : %s",yytext);}
%%
main(int argv, char *argc[])
{
  yyin=fopen(argc[1],"r");
  yylex();
   fclose(yyin);
}
                                                                                                                                                          1,1           All
