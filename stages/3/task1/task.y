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
%type <no> NUM ID expr Stmt Slist program Ifstmt Whilestmt E
%token NUM ID PLUS MINUS MUL DIV READ WRITE PBEGIN PEND IF THEN ELSE ENDIF GT LT GE LE EQ NE WHILE DO ENDWHILE
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
Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2);}	
	|Stmt			{$$=$1;}
	;
Stmt	: READ'('ID')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL);}
	|WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL);}
	|ID'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3);}
	|Ifstmt
	|Whilestmt
	;

Ifstmt : IF '('E')' THEN Slist ELSE Slist ENDIF
        | IF '('E')' THEN Slist ENDIF
		;

Whilestmt : WHILE '('E')' DO Slist ENDWHILE
		;
E : EL RELOP EL;
EL : ID|NUM;
RELOP : GT | LT |GE |LE|NE|EQ;  

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
