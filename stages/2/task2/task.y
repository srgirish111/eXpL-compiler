%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	#include"task.h"
	#include"task.c"
	int yylex(void);
	int yyerror(char const*);
	int yywrap();
	int i;
	FILE *fp;
	extern FILE *yyin;
%}
%union
{
	struct tnode *no;
}
%type <no> NUM ID expr Stmt Slist program
%token NUM ID PLUS MINUS MUL DIV READ WRITE PBEGIN PEND
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND';'	{$$=$2;
				 printf("Abstract syntax tree created succesfully\n");
				 inorder($$);
				 headergen();
				 i = codegen($$);
				 i = sys_call("Exit",0,0);
                 printf("xsm file generated");
                }
	|PBEGIN PEND';'		{$$=NULL;}
	;
/*struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r);*/

Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2);}	
	|Stmt			{$$=$1;}
	;
Stmt	: READ'('ID')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL);}
	|WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL);}
	|ID'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3);}
	;

expr	:expr PLUS expr		{$$=create_tree(0,0,"+",op_node,$1,$3);}
	|expr MINUS expr	{$$=create_tree(0,0,"-",op_node,$1,$3);}
	|expr MUL expr		{$$=create_tree(0,0,"*",op_node,$1,$3);}
	|expr DIV expr		{$$=create_tree(0,0,"/",op_node,$1,$3);}
	|'('expr')'		{$$=$2;}
	|NUM			{$$=$1;}
	|ID			{$$=$1;}
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	yyin=fopen("inp.txt","r");
	yyparse();
	return 0;
}
