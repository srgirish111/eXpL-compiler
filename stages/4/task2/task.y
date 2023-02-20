%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	#include"task.h"
	#include"task.c"
	int yylex();
	int yyerror(char const*);
	int yywrap();
	int i;
	FILE *fp;
	extern FILE *yyin;
	int currtype;
%}

%union
{
	struct tnode *no;
	int numb;
	char *name;
}

%token NUM VAR PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EQ NE PBEGIN PEND CONTINUE BREAK INT STR DECL ENDDECL MESG
%type <no> NUM VAR MESG expr Whilestmt Ifstmt Stmt Slist program 

%left GE LE EQ NE GT LT
%left PLUS MINUS
%left MUL DIV

%%
program :Declarations PBEGIN Slist PEND';'	{$$=$3;
				 printf("Abstract syntax tree created succesfully\n");
				 fp=fopen("task.xsm","wt");
				 fclose(fp);
				 inorder($$);
				 printf("tree printed\n");
				 headergen();
				 i=codegen($$);
				 i = sys_call("Exit",0,0);
                 printf("xsm file generated\n");
                }
	|PBEGIN PEND';'		{$$=NULL;}
	;

Declarations: DECL Decllist ENDDECL		{print_symbol_table();
				}
	    | DECL ENDDECL			{//print_symbol_table();
		}
	    ;

Decllist:Decllist Decl				{ }
	|Decl					{ }
	;

Decl	:Type Varlist ';'			{ }
	;
Type	:INT					{currtype=inttype;}
	|STR					{currtype=strtype;
							//print_symbol_table();
							}
	;
Varlist :Varlist ',' VAR	{
							//printf("currtype:%d\n",currtype);
						 	Install($3->varname,currtype,1);
							}	
	|VAR					{
							//printf("currtype:%d\n",currtype);
						  	Install($1->varname,currtype,1);
							}
	|Varlist ',' VAR'['NUM']' 
							{
							Install($3->varname,currtype,$5->val);
							}
	| VAR'['NUM']'			{
							Install($1->varname,currtype,$3->val);
							}

	;

Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2,NULL);}	
	|Stmt			{$$=$1;}
	;
Stmt	: READ'('VAR')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL,NULL);}
	|WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL,NULL);}
	|VAR'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3,NULL);}
	|Ifstmt
	|Whilestmt
	|BREAK';' {$$=create_tree(0,0,NULL,break_node,NULL,NULL,NULL);}
	|CONTINUE';'{$$=create_tree(0,0,NULL,continue_node,NULL,NULL,NULL);}
	;

Ifstmt : IF '('expr')' THEN Slist ELSE Slist ENDIF';' {$$=create_tree(0,0,NULL,if_node,$3,$8,$6);}
        | IF '('expr')' THEN Slist ENDIF';' {$$=create_tree(0,0,NULL,if_node,$3,NULL,$6);}
		;

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE';' {$$= create_tree(0,0,NULL,while_node,$3,$6,NULL);}
		;
expr	:expr PLUS expr		{$$=create_tree(0,inttype,"+",op_node,$1,$3,NULL);}
	|expr MINUS expr	{$$=create_tree(0,inttype,"-",op_node,$1,$3,NULL);}
	|expr MUL expr		{$$=create_tree(0,inttype,"*",op_node,$1,$3,NULL);}
	|expr DIV expr		{$$=create_tree(0,inttype,"/",op_node,$1,$3,NULL);}
	|expr GT expr {$$=create_tree(0,booltype,"<",relop_node,$1,$3,NULL);}
	|expr LT expr {$$ =create_tree(0,booltype,">",relop_node,$1,$3,NULL);}
	|expr LE expr {$$ =create_tree(0,booltype,">=",relop_node,$1,$3,NULL);}
	|expr GE expr {$$ =create_tree(0,booltype,"<=",relop_node,$1,$3,NULL);}
	|expr EQ expr {$$ =create_tree(0,booltype,"==",relop_node,$1,$3,NULL);}
	|expr NE expr {$$ =create_tree(0,booltype,"!=",relop_node,$1,$3,NULL);}
	|'('expr')'		{$$=$2;}
	|VAR			{$$=create_tree(0,notype,$1,var_node,NULL,NULL,NULL);}
	|NUM			{$$=create_tree(number,inttype,NULL,iconst_node,NULL,NULL,NULL);}
	|MESG			{$$=create_tree(0,strtype,$1,sconst_node,NULL,NULL,NULL);;}
	|VAR'['NUM']'	{$$=create_tree(0,notype,$1,var_node,NULL,NULL,NULL);}
	;
%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	//wrap_no=0;
	yyin=fopen("inp.txt","r");
	yyparse();
	return 0;
}
