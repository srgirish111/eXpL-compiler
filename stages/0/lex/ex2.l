%{
#include<stdio.h>
int i=0,f=0;
%}


number [0-9]
point "."
%option noyywrap
%%

{number}+ {++i;}
({number}*(\.){number}+) {++f;}
%%

int main() 
{
	yyin=fopen("inp2.txt","r");
    yylex();
    printf("no.of integers =%d \n no.of floats = %d",i,f);
    return 0;
}