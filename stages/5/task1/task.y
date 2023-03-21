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
	struct param *par;
	int numb;
	char *name;
}

%token NUM PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EQ NE PBEGIN PEND CONTINUE BREAK INT STR DECL ENDDECL MESG ID
%token RETURN MAINFN ANDTKN ORTKN NOTTKN
%type <no> expr Whilestmt Ifstmt Stmt Slist program IDEN
%type <numb> NUM
%type <name> ID MESG
%type <par> ParamList Param
%left GE LE EQ NE GT LT ANDTKN ORTKN NOTTKN
%left PLUS MINUS
%left MUL DIV MOD

%%

Program	:GdeclBlock FdefBlock MainBlock 	
	|GdeclBlock MainBlock			
	|MainBlock				
	;
GdeclBlock : DECL GdeclList ENDDECL {print_symbol_table();}
 | DECL ENDDECL {};

GdeclList : GdeclList GDecl {} | GDecl{} ;
GDecl : Type GidList ';' {} ;
Type	:INT					{currtype=inttype;}
	|STR					{currtype=strtype;
							//print_symbol_table();
							}
GidList : GidList ',' Gid {}
		|
		Gid {};

Gid : ID {GInstall($1,currtype,1,NULL);}
        | ID'['NUM']' {GInstall($1,currtype,$3,NULL);}
        | ID'('ParamList')' {GInstall($1,currtype,-1,$3);}
        ;

ParamList : ParamList ',' Param {PInstall($1,$3);
								 $$ =$1;} 
		| Param {$$ =$1;}
        |  /*epsilon*/{$$=NULL;}
        ;
Param : Type ID {$$ = create_par($2,currtype);} ;


///////////////////
//////////////////////
FdefBlock : FdefBlock Fdef | Fdef ;

Fdef : Type ID '(' ParamList ')' '{' LdeclBlock Body '}' ;

////////////////////////////
////////////////////////
LdeclBlock : DECL LDecList ENDDECL | DECL ENDDECL ;

LDecList : LDecList LDecl | LDecl ;

LDecl : Type IdList ;

IdList : IdList',' ID | ID ;

//Type : INT | STR ;

//Since a function call is treated as an expression (whose value is the return value of the function), the following rules must be added:




///////////////////////////////
///////////////////////////////
///////////////////////////////

MainBlock:Type MAINFN '(' ')' '{'LdeclBlock Body'}' 	
	|Type MAINFN '(' ')' '{'Body'}'			
	;
Body : PBEGIN Slist Rstmt PEND ';'
;	

Rstmt : RETURN expr ';'
;



Slist	: Slist Stmt		{}	
	|Stmt			{}
	;
Stmt	: READ'('IDEN')'';'	{}
	|WRITE'('expr')'';'	{}
	|IDEN'='expr';'	{}
	|Ifstmt
	|Whilestmt
	|BREAK';' {}
	|CONTINUE';'{}
	;

Ifstmt : IF '('expr')' THEN Slist ELSE Slist ENDIF';' {}
        | IF '('expr')' THEN Slist ENDIF';' {}
		;

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE';' {}
		;
expr	:expr PLUS expr		{$$=create_tree(0,inttype,"+",op_node,$1,$3,NULL);}
	|expr MINUS expr	{$$=create_tree(0,inttype,"-",op_node,$1,$3,NULL);}
	|expr MUL expr		{$$=create_tree(0,inttype,"*",op_node,$1,$3,NULL);}
	|expr DIV expr		{$$=create_tree(0,inttype,"/",op_node,$1,$3,NULL);}
	|expr MOD expr  {$$ = create_tree(0,inttype,"%",op_node,$1,$3,NULL);}
	|expr GT expr {$$=create_tree(0,booltype,"<",relop_node,$1,$3,NULL);}
	|expr LT expr {$$ =create_tree(0,booltype,">",relop_node,$1,$3,NULL);}
	|expr LE expr {$$ =create_tree(0,booltype,">=",relop_node,$1,$3,NULL);}
	|expr GE expr {$$ =create_tree(0,booltype,"<=",relop_node,$1,$3,NULL);}
	|expr EQ expr {$$ =create_tree(0,booltype,"==",relop_node,$1,$3,NULL);}
	|expr NE expr {$$ =create_tree(0,booltype,"!=",relop_node,$1,$3,NULL);}
	|expr ANDTKN expr {$$ =create_tree(0,booltype,"&&",relop_node,$1,$3,NULL);}
	|expr ORTKN expr {$$ =create_tree(0,booltype,"||",relop_node,$1,$3,NULL);}
	|NOTTKN expr {$$ =create_tree(0,booltype,"!",relop_node,$2,NULL,NULL);}
	|'('expr')'		{$$=$2;}
	|IDEN			{$$=$1;}
	|NUM			{$$=create_tree($1,inttype,NULL,iconst_node,NULL,NULL,NULL);}
	|MESG			{$$=create_tree(0,strtype,$1,sconst_node,NULL,NULL,NULL);}
	|ID '('')' {}
    |ID '('ArgList')' {}
    ;


ArgList : ArgList ',' expr {}
        | expr {};
IDEN : ID {}
		|
		ID '['expr']' {}
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
