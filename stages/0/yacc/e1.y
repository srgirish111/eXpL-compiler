%{
#include<stdio.h>
#include<stdlib.h>

int level = 0;
int a='\0';
%}

%token IF RELOP ID NUMBER OTH 

%%
start : statement '\n'  {exit(1);}

statement:
    | IF '(' condition ')' '{' statement '}' { printf("IF at level %d\n", ++level); }
    |
    OTH statement
    |OTH
    ;

condition:
    x RELOP x;
x : 
    ID | NUMBER;
%%
yyerror(char const *s)
{
    printf("yyerror %s",s);
}

yylex(){
    char c;
    if(a=='\0')
        c=getchar();
    else 
        c=a;
    if(c=='i'){
        c=getchar();
        if(c=='f')
        {
            a='\0';
            return IF;
        }
        else 
        {
            a=c;
            return OTH;
        }
    }
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else if(c=='{'||c=='}'|| c=='('||c==')'){
        prev='\0';
        return c;
    }
    prev='\0';
    return OTH;
}


main(int argc, char *argv[]) {
    yyparse();
    return 0;
}
