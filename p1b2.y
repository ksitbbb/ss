%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%token num
%left '+' '-'
%left '*'  '/'
%%


input:exp {printf("%d\n",$$);exit(0);}
exp:exp'+'exp {$$=$1+$3;}
| exp'-'exp {$$=$1-$3;}
| exp'*'exp {$$=$1*$3;}
| exp'/'exp {
    if($3==0){
        printf("Divide by zero \n");
        exit(0);
    }else
        $$=$1/$3;
;}
| '('exp')' {$$=$2;}
| num {$$=$1;};
%%


#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();


int yyerror(){
    printf("Error");
    exit(0);
}
int main(){
    printf("Enter an expression: \n");
    yyparse();
}