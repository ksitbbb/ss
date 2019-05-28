%{
    #include <stdio.h>
    #include <stdlib.h>
    int id=0,dig=0,op=0,key=0;
    int yyerror(const char *s);
    extern int yylex();
    extern int yyparse();
    extern FILE *yyin;
%}
%token DIGIT ID KEY OP
%%
input:
DIGIT input {dig++;}
| ID input {id++;}
| KEY input {key++;}
| OP input {op++;}
| DIGIT {dig++;}
| ID {id++;}
| KEY {key++;}
| OP {op++;}
%%

int main(){
    FILE *mf = fopen("example.c","r");
    if(!mf){
        printf("Can't open the file");
        return -1;
    }
    yyin = mf;
    do{
        yyparse();
    }while(!feof(yyin));
    printf("\n\nNumbers = %d\nKeywords = %d\nIdentifiers = %d\nOperators = %d\n",dig,key,id,op);
}
int yyerror(const char *s){
    printf("Parse error! Message : ");
    exit(-1);
}
int yywrap(void){
    return 1;
}