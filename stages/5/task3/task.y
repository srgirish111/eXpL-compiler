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
	FILE *fp=NULL;
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
%type <no> expr Whilestmt Ifstmt Stmt Slist IDEN Fdef Body Rstmt MainBlock ArgList
%type <numb> NUM Type Ptype
%type <name> ID MESG Ftype_param
%type <par> ParamList Param
%left GE LE EQ NE GT LT ANDTKN ORTKN NOTTKN
%left PLUS MINUS
%left MUL DIV MOD

%%

Program	:GdeclBlock FdefBlock MainBlock {}	
	|GdeclBlock MainBlock			{}
	|MainBlock				{}
	;

///////////////////////////
GdeclBlock : DECL GdeclList ENDDECL {
	print_symbol_table();
	headergen();
	fp=fopen("task.xsm","a");
	fprintf(fp,"PUSH R0\n");//Space for return value
	fprintf(fp,"CALL F0\n");
	fclose(fp);
	i = sys_call("Exit",0,0);
	}
 | DECL ENDDECL {};

GdeclList : GdeclList GDecl {} | GDecl{} ;
GDecl : Type GidList ';' {} ;
GidList : GidList ',' Gid {}
		|
		Gid {};

Gid : ID {GInstall($1,currtype,1,NULL);}
        | ID'['NUM']' {GInstall($1,currtype,$3,NULL);}
        | ID'('ParamList')' {GInstall($1,currtype,-1,$3);}
        ;


////////
FdefBlock : FdefBlock Fdef | Fdef ;

Fdef :  Ftype_param '{' LdeclBlock Body '}'
		{
			//codegen
			$$= $4;
			print_lcl_tab();
			printf("Abstract syntax tree created succesfully\n");
			
			//inorder($$);
			printf("tree printed done\n");
			func_starter($1);
			
			i=codegen($$);
			//codegen
			printf("codegenerated for func\n");
			deletetree($$);
			printf("tree deleted\n");
			free_lcl_tab();
		} 
		|
		Ftype_param '{' Body '}' 
		{
			$$=$3;
			printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			printf("tree printed\n");
			func_starter($1);
			i=codegen($$);
			//codegen
			deletetree($$);
			free_lcl_tab();
		}
		;
Ftype_param : Type ID '(' ParamList ')' 
	{
		check_name_equi($1,$2,$4);
		alocate_param($4);
		//printf("ftype_param_done\n");
		$$ =$2;
	}
/////////////
/////////////


ParamList : ParamList ',' Param {PInstall($1,$3);
								 $$ =$1;}
		| Param {$$ =$1;}
        |  /*epsilon*/{$$=NULL;}
        ;
Ptype :INT		{$$=inttype; }
	|STR			{$$=strtype; }
	;
Param : Ptype ID {$$ = create_par($2,$1);

printf("param\n");} ;


//////////////////////
//////////////////////


////////////////////////
////////////////////////
LdeclBlock : DECL LDecList ENDDECL {printf("lcldecl block done\n");} | DECL ENDDECL {} ;

LDecList : LDecList LDecl {}| LDecl {};

LDecl : Type IdList ';' {};

IdList : IdList',' ID {LInstall($3,currtype);} 
		| ID {LInstall($1,currtype);}
		;

//Type : INT | STR ;
Type	:INT					{currtype=inttype;
								$$ =inttype;}
	|STR					{currtype=strtype;
							 $$ =strtype;
							//print_symbol_table();
							}

	;
//Since a function call is treated as an expression (whose value is the return value of the function), the following rules must be added:
///////////////////////////////
///////////////////////////////
///////////////////////////////

MainBlock:Type MAINFN '(' ')' '{'LdeclBlock Body'}' 	
	{		
			$$=$7;
			print_lcl_tab();
			printf("Abstract syntax tree created succesfully\n");
			
			//inorder($$);
			printf("tree printed\n");
			//codegen
			main_starter();
			
			
			i=codegen($$);
			printf("xsm file generated\n");
			///
			deletetree($$);
			free_lcl_tab();
	}
	|Type MAINFN '(' ')' '{'Body'}'			{
			$$=$6;
			printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			printf("tree printed\n");
			//codegen

			main_starter();
			i=codegen($$);
			printf("xsm file generated\n");
			///
			deletetree($$);
			free_lcl_tab();
	}

	;
Body : PBEGIN Slist Rstmt PEND  
	{
		$$=create_tree(0,0,NULL,conn_node,$2,$3,NULL);
	}
;	

Rstmt : RETURN expr ';' {
				$$ =create_tree(0,0,NULL,ret_node,$2,NULL,NULL);}
;

///////////////////////////
/////////////////////////////



Slist	: Slist Stmt		{$$=create_tree(0,0,NULL,conn_node,$1,$2,NULL);}	
	|Stmt			{$$ =$1;}
	;
Stmt	: READ'('IDEN')'';'	{$$=create_tree(0,0,NULL,read_node,$3,NULL,NULL);}
	|WRITE'('expr')'';'	{$$=create_tree(0,0,NULL,write_node,$3,NULL,NULL);}
	|IDEN'='expr';'	{$$=create_tree(0,0,"=",assg_node,$1,$3,NULL);}
	|Ifstmt {$$=$1;}
	|Whilestmt {$$=$1;}
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
	|expr MOD expr  {$$ = create_tree(0,inttype,"%",op_node,$1,$3,NULL);}
	|expr GT expr {$$=create_tree(0,booltype,">",relop_node,$1,$3,NULL);}
	|expr LT expr {$$ =create_tree(0,booltype,"<",relop_node,$1,$3,NULL);}
	|expr GE expr {$$ =create_tree(0,booltype,">=",relop_node,$1,$3,NULL);}
	|expr LE expr {$$ =create_tree(0,booltype,"<=",relop_node,$1,$3,NULL);}
	|expr EQ expr {	$$ =create_tree(0,booltype,"==",relop_node,$1,$3,NULL);}
	|expr NE expr {$$ =create_tree(0,booltype,"!=",relop_node,$1,$3,NULL);}
	|expr ANDTKN expr {$$ =create_tree(0,booltype,"&&",log_node,$1,$3,NULL);}
	|expr ORTKN expr {$$ =create_tree(0,booltype,"||",log_node,$1,$3,NULL);}
	|NOTTKN expr {$$ =create_tree(0,booltype,"!",log_node,$2,NULL,NULL);}
	|'('expr')'		{$$=$2;}
	|IDEN			{$$=$1;}
	|NUM			{$$=create_tree($1,inttype,NULL,iconst_node,NULL,NULL,NULL);}
	|MESG			{$$=create_tree(0,strtype,$1,sconst_node,NULL,NULL,NULL);}
	|ID '('')' 		{$$=create_tree(0,notype,$1,func_node,NULL,NULL,NULL);}
    |ID '('ArgList')' {$$=create_tree(0,notype,$1,func_node,$3,NULL,NULL);}
    ;

IDEN : ID {$$=create_tree(0,notype,$1,var_node,NULL,NULL,NULL);}
		|
		ID '['expr']' {$$=create_tree(0,notype,$1,var_node,$3,NULL,NULL);}
		;

ArgList : expr ','  ArgList{$1->mid =$3;$$=$1;}
        | expr {$$=$1;};

%%
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	yyin=fopen("inp.expl","r");
	yyparse();
	return 0;
}