%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    int yyerror(const char *s);
%}

%token A B
%%

input:s'\n' {printf("Successful Grammer\n");exit(0);}
s: A y B| B
y: ; | A y
%%

void main(){
    printf("Enter a string : ");
    yyparse();
}
int yyerror(const char *s){
    printf("Not a grammer\n");
    exit(0);
}
int yywrap(void){
    return 1;
}