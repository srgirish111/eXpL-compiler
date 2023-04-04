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
	struct Typetable *currtype;
	int size=0;
%}

%union
{
	struct tnode *no;
	struct param *par;
	struct Fieldlist *field;
	struct Typetable *typ;
	int numb;
	char *name;
}
%token NUM PLUS MINUS MUL DIV READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE GT LT GE LE EQ NE PBEGIN PEND CONTINUE BREAK INT STR DECL ENDDECL MESG ID
%token RETURN MAINFN ANDTKN ORTKN NOTTKN
%token TYPETKN ENDTYPETKN INITIALIZE ALLOC FREE NULLTKN
%type <no> expr Whilestmt Ifstmt Stmt Slist IDEN Fdef Body Rstmt MainBlock ArgList Heapstuff FIELD NULLTKN Assign_stmt Inp_stmt out_stmt
%type <numb> NUM
%type <name> ID MESG Ftype_param TypeName
%type <par> ParamList Param
%type <field> FieldDecl FieldDeclList
%type <typ> TypeDef Type_name Type Ptype
%left GE LE EQ NE GT LT ANDTKN ORTKN NOTTKN
%left PLUS MINUS
%left MUL DIV MOD

%%

Program	:TypeDefBlock GdeclBlock FdefBlock MainBlock {}	
	|TypeDefBlock GdeclBlock MainBlock			{}
	|TypeDefBlock MainBlock				{}
	;

///////////////////////////
TypeDefBlock  : TYPE_TKN TypeDefList ENDTYPETKN {printf("typedefblck\n");}
              | //NULL
              ;
TYPE_TKN : TYPETKN {TypeTableCreate();} ;

TypeDefList   : TypeDefList TypeDef {}
              | TypeDef {}
              ;
Type_name : ID  {$$ =TInstall($1,0,NULL);};
TypeDef       : Type_name '{' FieldDeclList '}'   { 
					$$ = $1;
					$$->fields = $3;
					$$->size = size;
					print_type($$);
					size=0; }
              ;

FieldDeclList : FieldDecl FieldDeclList {$1->next=$2;
					$$=$1;}
              | FieldDecl {$$ =$1;}
              ;

FieldDecl    : TypeName ID ';'  {
					$$ = Fcreate($2,$1);
					//printf("%s  %s\n",$1,$2);
					++size;
					}

TypeName     : INT {$$="int";}
             | STR {$$="str";}
             | ID {$$=$1;}
             ;

//////////////////////////
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
			//printf("tree printed done\n");
			printf("------------------------------------------\n");
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
			//printf("tree printed\n");
			printf("------------------------------------------\n");
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
		printf("ftype_param_done\n");
		$$ =$2;
	}
/////////////
/////////////


ParamList : ParamList ',' Param {PInstall($1,$3);
								 $$ =$1;}
		| Param {$$ =$1;}
        |  /*epsilon*/{$$=NULL;}
        ;

Param : Ptype ID {$$ = create_par($2,$1);} 
	;

Ptype :INT		{$$=TLookup("int"); }
	|STR			{$$=TLookup("str"); }
	|ID			{$$=TLookup($1); }
	;

//////////////////////
//////////////////////


////////////////////////
////////////////////////
LdeclBlock : DECL LDecList ENDDECL {printf("lcl_block done\n");} | DECL ENDDECL {} ;

LDecList : LDecList LDecl {}| LDecl {print_lcl_tab();};

LDecl : Type IdList ';' {};

IdList : IdList',' ID {LInstall($3,currtype);} 
		| ID {LInstall($1,currtype);}
		;

//Type : INT | STR ;
Type	:INT					{currtype=TLookup("int");
								$$ =currtype;}
	|STR					{currtype=TLookup("str");
							 $$ =currtype;
						
							}
	| ID {
			currtype = TLookup($1);
			if(currtype==NULL)
			{
				printf("type not declared --> %s\n",$1);
				exit(1);
			}
			$$=currtype;
			
		
		}


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
		$$=create_tree(0,TLookup("void"),NULL,conn_node,$2,$3,NULL);
	}
;	

Rstmt : RETURN expr ';' {
				$$ =create_tree(0,TLookup("void"),NULL,ret_node,$2,NULL,NULL);}
;

/////////////////////////////
/////////////////////////////
Slist	: Slist Stmt		{$$=create_tree(0,TLookup("void"),NULL,conn_node,$1,$2,NULL);}	
	|Stmt			{$$ =$1;}
	;
Stmt: Assign_stmt {$$=$1;}|
	  Inp_stmt    {$$=$1;} |
	  out_stmt    {$$=$1;} |
	  Ifstmt      {$$=$1;}|
	  Whilestmt   {$$=$1;}|
	  BREAK';' {$$=create_tree(0,TLookup("void"),NULL,break_node,NULL,NULL,NULL);}|
	  CONTINUE';'{$$=create_tree(0,TLookup("void"),NULL,continue_node,NULL,NULL,NULL);} |
	  //func_call {} |
	  FREE'('IDEN')'';' {typecheck($3);$$=create_tree(0,TLookup("void"),NULL,free_node,$3,NULL,NULL);};
		;

Assign_stmt : IDEN'='expr';'	{typecheck($1);$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	|FIELD'='expr ';' {$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	|IDEN'='Heapstuff ';'{typecheck($1);$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	;
Inp_stmt :READ'('IDEN')'';'	{$$=create_tree(0,TLookup("void"),NULL,read_node,$3,NULL,NULL);};

out_stmt :WRITE'('expr')'';'	{$$=create_tree(0,TLookup("void"),NULL,write_node,$3,NULL,NULL);};


Heapstuff : INITIALIZE'('')' {$$=create_tree(0,TLookup("int"),NULL,initia_node,NULL,NULL,NULL);printf("initialize\n");}
		|	ALLOC'('')' {$$=create_tree(0,TLookup("void"),NULL,alloc_node,NULL,NULL,NULL);}
	;

//typecheck properly

FIELD     : IDEN'.'IDEN {
				typecheck($1);
				//printf("%s---%s\n ",$1->type->name,$3->varname);
				struct Fieldlist *f;
				if($1->type==TLookup("int") || $1->type==TLookup("str"))
				{
					printf("invalid field access\n");
							exit(1);
				}
				//printf("f1\n");
				f=FLookup($1->type,$3->varname);
				//printf("f1\n");
				if(f==NULL)
				{
			      	printf("No field :%s in %s type\n",$3->varname,$1->type->name);
				 	exit(1);
				}
				$1->nodetype=field_node;
				$1->mid=$3;
				$3->type=f->type;
				$3->val=f->fieldIndex;
				$1->type=$3->type;
				$$=$1;	
				//printf("f1\n");
						}
          | FIELD '.' IDEN {
				struct tnode *temp; 
				struct Fieldlist *f;
				temp=$1;
				while(temp->mid!=NULL)
					temp=temp->mid;
				f=FLookup(temp->type,$3->varname);
				if(f==NULL)
				{
					printf("No field :%s in %s type\n",$3->varname,temp->type->name);
				 	exit(1);
				}
				temp->nodetype=field_node;
				temp->mid=$3;
				$3->type=f->type;
				$3->val=f->fieldIndex;
				$1->type=$3->type;
				$$=$1;
		  }
          ;

Ifstmt : IF '('expr')' THEN Slist ELSE Slist ENDIF';' {$$=create_tree(0,TLookup("void"),NULL,if_node,$3,$8,$6);}
        | IF '('expr')' THEN Slist ENDIF';' {$$=create_tree(0,TLookup("void"),NULL,if_node,$3,NULL,$6);}
		;

Whilestmt : WHILE '('expr')' DO Slist ENDWHILE';' {$$= create_tree(0,TLookup("void"),NULL,while_node,$3,$6,NULL);}
		;

expr	:expr PLUS expr		{$$=create_tree(0,TLookup("int"),"+",op_node,$1,$3,NULL);}
	|expr MINUS expr	{$$=create_tree(0,TLookup("int"),"-",op_node,$1,$3,NULL);}
	|expr MUL expr		{$$=create_tree(0,TLookup("int"),"*",op_node,$1,$3,NULL);}
	|expr DIV expr		{$$=create_tree(0,TLookup("int"),"/",op_node,$1,$3,NULL);}
	|expr MOD expr  {$$ = create_tree(0,TLookup("int"),"%",op_node,$1,$3,NULL);}
	|expr GT expr {$$=create_tree(0,TLookup("bool"),">",relop_node,$1,$3,NULL);}
	|expr LT expr {$$ =create_tree(0,TLookup("bool"),"<",relop_node,$1,$3,NULL);}
	|expr GE expr {$$ =create_tree(0,TLookup("bool"),">=",relop_node,$1,$3,NULL);}
	|expr LE expr {$$ =create_tree(0,TLookup("bool"),"<=",relop_node,$1,$3,NULL);}
	|expr EQ expr {	$$ =create_tree(0,TLookup("bool"),"==",relop_node,$1,$3,NULL);}
	|expr NE expr {$$ =create_tree(0,TLookup("bool"),"!=",relop_node,$1,$3,NULL);}
	|expr ANDTKN expr {$$ =create_tree(0,TLookup("bool"),"&&",log_node,$1,$3,NULL);}
	|expr ORTKN expr {$$ =create_tree(0,TLookup("bool"),"||",log_node,$1,$3,NULL);}
	|NOTTKN expr {$$ =create_tree(0,TLookup("bool"),"!",log_node,$2,NULL,NULL);}
	|'('expr')'		{$$=$2;}
	|IDEN			{$$=$1;typecheck($$);}
	|NUM			{$$=create_tree($1,TLookup("int"),NULL,iconst_node,NULL,NULL,NULL);}
	|MESG			{$$=create_tree(0,TLookup("str"),$1,sconst_node,NULL,NULL,NULL);}
	|ID '('')' 		{$$=create_tree(0,TLookup("void"),$1,func_node,NULL,NULL,NULL);}
    |ID '('ArgList')' {$$=create_tree(0,TLookup("void"),$1,func_node,$3,NULL,NULL);}
	|FIELD  {$$= $1;}
	|NULLTKN {$$=$1;}
	;
ArgList : expr ','  ArgList{$1->arg =$3;$$=$1;}
        | expr {$$=$1;$$->arg=NULL;};

IDEN : ID {$$=create_tree(0,TLookup("void"),$1,var_node,NULL,NULL,NULL);}		
		|
		ID '['expr']' {$$=create_tree(0,TLookup("void"),$1,arr_node,$3,NULL,NULL);}
		;
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