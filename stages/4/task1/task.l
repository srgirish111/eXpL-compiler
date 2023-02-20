%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
	#include"task.h"
	int yyerror(char const*);
	int number;
	int declflag=0;
%}

%%
[0-9]+	{ 
		number=atoi(yytext);
		yylval.no=create_tree(number,inttype,NULL,iconst_node,NULL,NULL,NULL);
		return NUM;
	}


"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
";"		{return *yytext;}
"="		{return *yytext;}
[()]	{return *yytext;}
","		{return *yytext;}


">="	{return GE;}
"<="	{return LE;}
"=="	{return EQ;}
"!="	{return NE;}
">"		{return GT;}
"<"		{return LT;}
"write"	{return WRITE;}
"read"	{return READ;}


"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}

"while"	{return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
"continue" {return CONTINUE;}
"break" {return BREAK;}
"begin"	{return PBEGIN;}
"end" 	{return PEND;}
"decl"  {declflag=1; return DECL;}
"enddecl" {declflag=0; return ENDDECL;}
"int" 	{return INT;}
"str"	{return STR;}


[ \t\n]+ { }

[a-zA-Z][a-zA-Z0-9]*	{
				yylval.no=create_tree(0,notype,yytext,var_node,NULL,NULL,NULL);
				return VAR;
			}
\"(\\.|[^"\\])*\"  {
			yylval.no=create_tree(0,strtype,yytext,sconst_node,NULL,NULL,NULL);
			return MESG;	
		}

. {printf("unknown character\n");
	printf("%s",yytext);
   exit(1);
   }
%%

int yywrap(void)
{
	 return 1;
}