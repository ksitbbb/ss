%{
    #include "y.tab.c"
    #include <stdio.h>
    extern int yylval;
%}
%%
[ \t] {;}
[+|-|*|/|=|<|>] {printf("Operator is %s\n",yytext);return OP;}
[0-9]+ {yylval = atoi(yytext);printf("Numbers is %d\n",yylval);return DIGIT;}
int|char|bool|float|void|for|do|while|if|else|return {printf("Keyword is %s\n",yytext);return KEY;}
[a-zA-Z0-9]+ {printf("Identifiers is %s\n",yytext);return ID;}
. {;}
%%