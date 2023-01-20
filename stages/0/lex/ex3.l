%{
#include<stdio.h>
int i=0;
%}


number [0-9]
letter [a-zA-Z]

%option noyywrap
%%
("A"{letter}{letter}}) {++i;}
%%

int main() 
{
	yyin=fopen("inp3.txt","r");
    yylex();
    printf("no.of 3 letter words starting with A =%d",i);
    return 0;
}