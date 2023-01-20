%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
int yyerror(char const *s);
%}


%%
    
[a-zA-Z]+ {//yylval.str=(char*)malloc(sizeof(char)*100); 
	//strcpy(yylval.str,yytext);
	yylval.c=strdup(yytext);
	
	return STRI;
	}
"+"	return *yytext;
"-"	return *yytext;
"*"	return *yytext;
"\/"	  return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;
(.)       return yyerror("unknown character\n");
%%

int yywrap()
{
return 1;
}