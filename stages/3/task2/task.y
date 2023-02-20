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
%token NUM ID PLUS MINUS MUL DIV READ WRITE PBEGIN PEND IF THEN ELSE ENDIF GT LT GE LE EQ NE WHILE DO ENDWHILE
%type <no> NUM ID expr Stmt Slist program Ifstmt Whilestmt E
%left GE LE EQ NE GT LT
%left PLUS MINUS
%left MUL DIV

%%
program : PBEGIN Slist PEND';'	{$$=$2;
				 printf("Abstract syntax tree created succesfully\n");
				 fp=fopen("task2.xsm","wt");
				 fclose(fp);
				 inorder($$);
				 headergen();
				 i=codegen($$);
				 i = sys_call("Exit",0,0);
                 printf("xsm file generated");
                }
	|PBEGIN PEND';'		{$$=NULL;}
	;
Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2,NULL);}	
	|Stmt			{$$=$1;}
	;
Stmt	: READ'('ID')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL,NULL);}
	|WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL,NULL);}
	|ID'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3,NULL);}
	|Ifstmt
	|Whilestmt
	;

Ifstmt : IF '('E')' THEN Slist ELSE Slist ENDIF';' {$$=create_tree(0,0,NULL,if_node,$3,$8,$6);}
        | IF '('E')' THEN Slist ENDIF';' {$$=create_tree(0,0,NULL,if_node,$3,NULL,$6);}
		;

Whilestmt : WHILE '('E')' DO Slist ENDWHILE';' {$$= create_tree(0,0,NULL,while_node,$3,$6,NULL);}
		;
E : expr GT expr	{$$=create_tree(0,booltype,"<",relop_node,$1,$3,NULL);}
	|expr LT expr {$$ =create_tree(0,booltype,">",relop_node,$1,$3,NULL);}
	|expr LE expr {$$ =create_tree(0,booltype,">=",relop_node,$1,$3,NULL);}
	|expr GE expr {$$ =create_tree(0,booltype,"<=",relop_node,$1,$3,NULL);}
	|expr EQ expr {$$ =create_tree(0,booltype,"==",relop_node,$1,$3,NULL);}
	|expr NE expr {$$ =create_tree(0,booltype,"!=",relop_node,$1,$3,NULL);}
	;

expr	:expr PLUS expr		{$$=create_tree(0,inttype,"+",op_node,$1,$3,NULL);}
	|expr MINUS expr	{$$=create_tree(0,inttype,"-",op_node,$1,$3,NULL);}
	|expr MUL expr		{$$=create_tree(0,inttype,"*",op_node,$1,$3,NULL);}
	|expr DIV expr		{$$=create_tree(0,inttype,"/",op_node,$1,$3,NULL);}
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
