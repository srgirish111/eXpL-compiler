%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"y.tab.h"
	#include"task.h"
	int yyerror(char const*);
	
	int number;
%}
/*struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r);*/
%%
[0-9]+	{	number=atoi(yytext);
		yylval.no=create_tree(number,inttype,NULL,const_node,NULL,NULL,NULL);
		return NUM;
	}
[a-z]	{
		yylval.no=create_tree(0,inttype,yytext,var_node,NULL,NULL,NULL);
		return ID;
	}
"begin"	{return PBEGIN;}
"read"	{return READ;}
"write"	{return WRITE;}
"end"	{return PEND;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
[ \t]	{}
[\n]	{}
[()]	{return *yytext;}
"<" 	{return GT;}
">" 	{return LT;}
"<=" 	{return GE;}
">=" 	{return LE;}
"==" 	{return EQ;}
"!=" 	{return NE;}
";"		{return *yytext;}
"="		{return *yytext;}
"if" 	{return IF;}
"then"  {return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
.		{	
			yyerror("unknown character\n");
			exit(1);
		}
%%

int yywrap(void)
{
	return 1;
} 
