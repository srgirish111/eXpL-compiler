%{
	//abhis project
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
	struct Classtable *currclass;
	struct Gsymbol *func_=NULL;
	struct Memberfunclist *mem_func=NULL;
	int size=0;
	int cls_fld_idx=0,cls_mtd_idx=0;
	struct Classtable *Cptr=NULL;
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
%token CLASS ENDCLASS SELF NEW DELETE EXTENDS
%type <no> expr Whilestmt Ifstmt Stmt Slist IDEN Fdef Body Rstmt MainBlock ArgList Heapstuff FIELD NULLTKN Assign_stmt Inp_stmt out_stmt
%type <no> class_stmts FieldFunction
%type <numb> NUM
%type <name> ID MESG Ftype_param TypeName
%type <par> ParamList Param
%type <field> FieldDecl FieldDeclList
%type <typ> TypeDef Type_name Type Ptype GType
%left GE LE EQ NE GT LT ANDTKN ORTKN NOTTKN
%left PLUS MINUS
%left MUL DIV MOD

%%

Program	:TypeDefBlock ClassDefBlock GdeclBlock FdefBlock MainBlock {}	
	|TypeDefBlock ClassDefBlock GdeclBlock MainBlock			{}
	|TypeDefBlock ClassDefBlock MainBlock				{}
	;

///////////////////////////
TypeDefBlock  : TYPE_TKN TypeDefList ENDTYPETKN 
				{
						headergen();
						fp=fopen("task.xsm","a");
						//fprintf(fp,"PUSH R0\n");//Space for return value
						fprintf(fp,"JMP F0\n");
						fclose(fp);
						

				}
              | {
					TypeTableCreate();
					headergen();
					fp=fopen("task.xsm","a");
					//fprintf(fp,"PUSH R0\n");//Space for return value
					fprintf(fp,"JMP F0\n");
					fclose(fp);
					
				} //NULL
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
					//print_type($$);
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
//////////////////////////
//////////////////////////
//////////////////////////

ClassDefBlock   : CLASS ClassDefList ENDCLASS
                |
                ;
ClassDefList    : ClassDefList Classdef {}
                | Classdef {}
                ;

Classdef        : Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'
				{

					Cptr->Fieldcount=cls_fld_idx ;
					Cptr->Methodcount=cls_mtd_idx;
					cls_fld_idx=0;
					cls_mtd_idx=0;
					//cls_idx=0;
					Cptr = NULL;
					//free_classtab();
					//printf("class done\n");
				};

Cname           : ID        {Cptr = CInstall($1,NULL);}
                | ID EXTENDS ID {
					Cptr = CInstall($1,$3);
					struct Classtable *paren;
					paren= Cptr->Parentptr;
					Cptr->Fieldcount=paren->Fieldcount;
					cls_fld_idx=paren->Fieldcount;
					Cptr->Methodcount=paren->Methodcount;
					cls_mtd_idx=paren->Methodcount;
					}
                ;

Fieldlists      : Fieldlists Fld {}
                |
                ;

Fld             : TypeName ID ';'  {Class_Finstall(Cptr,$1,$2,cls_fld_idx);
							++cls_fld_idx;
							} //Installing the field to the class
                ;

MethodDecl      : MethodDecl MDecl {}
                | MDecl {}
                ;

MDecl           : TypeName ID '(' ParamList ')' ';' {
						struct Memberfunclist *met;
						met=NULL;
						if(Cptr->Parentptr!=NULL)
							met=Class_Mlookup(Cptr->Parentptr,$2);

						Class_Minstall(Cptr,$2,TLookup($1),$4,cls_mtd_idx);
						if(met==NULL)
						++cls_mtd_idx;			
						//print_mthd(Cptr);
						}
//Installing the method to class
                ;

MethodDefns     : MethodDefns Fdef
                | Fdef
                ;


FieldFunction   : 
				SELF '.' IDEN '(' ArgList ')' 
					{
						if(Cptr==NULL)
						{
							printf("you cant have self stmts outside a class\n");
							exit(1);
						}
						struct Memberfunclist * Mtemp = Class_Mlookup(Cptr, $3->varname);
						if(Mtemp == NULL)
						{
                	        printf("Function -->%s not a member function of the class-->%s \n",$3->varname,Cptr->name);
                        	exit(1);
                        }
						$3->val= Mtemp->Funcposition;
						$3->nodetype =  self_meth_node;
						$3->left=$5;
						$3->Ctype=Cptr;
						//$$=create_tree(0,TLookup("void"),"self",self_meth_node,NULL,NULL,$3);
						$$=$3;
						$$->Lentry = LLookup("self");
                        $$->type = Mtemp->type;
					}
                | IDEN '.' IDEN '(' ArgList ')'   //This will not occur inside a class.
					{
						if(Cptr!=NULL)
						{
							printf("you cant have id.id(args) stmts inside a class\n");
							exit(1);
						}
						$1->mid =$3;
						struct Gsymbol *Gtemp = GLookup($1->varname);
						if(Gtemp==NULL)
						{
							printf("no %s was declared\n",$1->varname);
							exit(1);
						}
						$1->Ctype = Gtemp->Ctype;
						$3->Ctype = Gtemp->Ctype;
						$1->Gentry = Gtemp;
						$1->nodetype=cls_meth_node;


						struct Memberfunclist * Mtemp;
						Mtemp = Class_Mlookup(Gtemp->Ctype, $3->varname);
						if(Mtemp == NULL)
						{
							printf("Function -->%s not a member function of the class-->%s \n",$3->varname,Gtemp->Ctype->name);
                        	exit(1);
                        }
						$3->val= Mtemp->Funcposition;
						$3->nodetype =  mth_call_node;
						$3->left=$5;
						$$=$1;
						$$->Lentry = NULL;
                        $$->type = Mtemp->type;
						
					}
                | FIELD '.' IDEN '(' ArgList ')'
					{
						//if(Cptr == NULL)
						//else
						//$1->nodetype = $1;
						struct tnode *temp; 
						temp=$1;
						while(temp->mid!=NULL)
							temp=temp->mid;
						
						if(temp->Ctype==NULL)
						{
							printf("field doesnt end with a class type\n");
							exit(1);
						}
						temp->mid = $3;
						struct Memberfunclist* m;
						m=Class_Mlookup(temp->Ctype,$3->varname);
						if(m==NULL)
						{
							printf("Function -->%s not a member function of the class-->%s \n",$3->varname,Cptr->name);
                        	exit(1);
						}
						$3->val= m->Funcposition;
						$3->nodetype =  mth_call_node;
						//$$->nodetype=self_meth_node;
						$3->left=$5;
						$$=$1;
						//$$->Lentry = NULL; would be set to self
						//$$->Ctype =m->type
                        $$->type = m->type;
					}
                ;


FIELD     : 

		IDEN'.'IDEN
		{
		//cant occur in context of a class
					
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
			
		}
          | FIELD '.' IDEN {  //can't occur in a class 
		  		if($$->Ctype!=NULL)
				{
					//print_node($$);
					printf("%s\n",$$->Ctype->name);
					printf("variables of a class are protected so you cant access them this way\ncall its methods if possible--%d\n",ins_cnt);
					exit(1);
				}
		  		struct tnode *temp; 
				struct Fieldlist *f;
				struct Fieldlist *mem_f;
				temp=$1;
				int len=0;
				while(temp->mid!=NULL)
				{
					temp=temp->mid;
					++len;
				}
		  		if(Cptr==NULL)
				{
					f=FLookup(temp->type,$3->varname);
					if(f==NULL)
					{
						printf("No field :%s in %s type\n",$3->varname,temp->type->name);
						exit(1);
					}
					temp->nodetype=field_node;
					$3->type=f->type;
					$3->val=f->fieldIndex;
				}
				else
				{
					mem_f=NULL;
					if(len>0)
					{
						mem_f=Class_Flookup(Cptr,$3->varname);
					}
					else
					{
						mem_f=FLookup(temp->type,$3->varname);
					}
					if(mem_f==NULL)
					{
						printf("No field :%s in %s type\n",$3->varname,temp->type->name);
						exit(1);
					}
					//printf("--%s--\n",$3->varname);
					temp->nodetype=self_fld_node;
					$3->type=mem_f->type;
					$3->val=mem_f->fieldIndex;
					//$3->nodetype= 

				}
				temp->mid=$3;

				$1->type=$3->type;
				$$=$1;
		  }
		  |
		  SELF '.' IDEN  //occurs only in a class
		  {
			   //recognise error if this statement occurs outside a class --> implemented in tyepcheck
			   	struct Fieldlist *var;
				if(Cptr==NULL)
				{
					printf("self shouldnt be used outside a class\n");
					exit(1);
				}
			   	var = Class_Flookup(Cptr,$3->varname);
				$$->Ctype =Cptr;
				if(var!=NULL)
				{
						$$=$3;
						$$->Lentry = LLookup("self");
						$$->val= var->fieldIndex;
			   			$$->nodetype=self_fld_node;
						$$->type= var->type;
						$$->Ctype=var->ctype;
				}
				else
				{
					//print_field(Cptr);
					printf("no field matching -->%s in class -->%s\n",$3->varname,Cptr->name);
					exit(1);
				}
		  }
    ;

















//////////////////////////////////
///////////////////////////////////
/////////////////////////////
GdeclBlock : GNULL_TKN DECL GdeclList ENDDECL {
	//print_symbol_table();
	}
 | GNULL_TKN DECL ENDDECL {};

GNULL_TKN : {set_bind_addr();};
GdeclList : GdeclList GDecl {} | GDecl{} ;
GDecl : GType GidList ';' {} ;
GType	:INT					{currtype=TLookup("int");
								$$ =currtype;}
	|STR					{currtype=TLookup("str");
							 $$ =currtype;
						
							}
	| ID {
			currtype = TLookup($1);
			currclass=NULL;
			if(currtype==NULL)
			{
				currtype=NULL;
    			currclass= CLookup($1);
				if(currclass==NULL)
				{
					printf("no class or type of -->%s\n",$1);
					exit(1);
				}

			}
			//$$=currtype;
			
		
		}
GidList : GidList ',' Gid {}
		|
		Gid {};

Gid : ID {GInstall($1,currtype,1,NULL,currclass);}
        | ID'['NUM']' {GInstall($1,currtype,$3,NULL,currclass);}
        | ID'('ParamList')' {GInstall($1,currtype,-1,$3,currclass);}
        ;

////////
FdefBlock : FdefBlock Fdef | Fdef ;

Fdef :  Ftype_param '{' LdeclBlock Body '}'
		{
			//codegen
			$$= $4;
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//inorder($$);
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("tree printed done\n");
			func_starter($1);
			
			i=codegen($$);
			//codegen  break task.c:
			//printf("codegenerated for func\n");
			//deletetree($$);
			//printf("tree deleted\n");
			//print_lcl_tab();
			free_lcl_tab();
			//printf("lcl_tabfreed\n");
		} 
		|
		Ftype_param '{' Body '}' 
		{
			$$=$3;
			//printf("Abstract syntax tree created succesfully\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//inorder($$);
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("tree printed done\n");
			func_starter($1);
			i=codegen($$);
			//codegen
			//deletetree($$);
			//printf("tree deleted\n");
			free_lcl_tab();
			//printf("lcl_tabfreed\n");
		}
		; //break task.c:
Ftype_param : Type ID '(' ParamList ')' 
	{
		if(Cptr==NULL)
		{
			func_=GLookup($2);
		}
		else
		{
			mem_func=Class_Mlookup(Cptr,$2);
		}
		//printf("in ftype_param\n");
		check_name_equi($1,$2,$4);
		//printf("nameequichecked\n");
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
LdeclBlock : DECL LDecList ENDDECL 
	{
		//printf("lcl_block done\n");
		

	}
	 | DECL ENDDECL 
	 {
		
	 } ;

LDecList : LDecList LDecl {}| LDecl {};

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

MainBlock:Type_main '(' ')' '{'LdeclBlock Body'}' 	
	{		
			$$=$6;
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
		    //inorder($$);
			//printf("------------------------------------------\n");
		 	//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("tree printed done\n");
			//inorder($$);
			//printf("tree printed\n");
			//codegen
			//$$->right->val=1;
			main_starter();
			i=codegen($$);
			//printf("xsm file generated\n");
			///
			//deletetree($$);
			free_lcl_tab();
	}
	|Type_main '(' ')' '{'Body'}'			{
			$$=$5;
			//printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			//printf("tree printed\n");
			//codegen
			$$->right->val=1;
			main_starter();
			i=codegen($$);
			//printf("xsm file generated\n");
			///
			//deletetree($$);
			free_lcl_tab();
	}
	;
Type_main : Type MAINFN {func_= NULL;};
Body : PBEGIN Slist Rstmt PEND  
	{
		$$=create_tree(0,TLookup("void"),NULL,conn_node,$2,$3,NULL);
	}
	|
	PBEGIN Rstmt PEND 
	{
		$$=$2;
	}
;	

Rstmt : RETURN expr ';' {
				$$ =create_tree(0,TLookup("void"),NULL,ret_node,$2,NULL,NULL);
				if(Cptr!=NULL)
				{
					if(strcmp($2->type->name,mem_func->type->name)!=0)
					{
						printf("return type error --> %s\n",mem_func->name);
						exit(1);
					}
				}
				else
				{
					if(func_==NULL) //main
					{
						$$->val=1;
						if(strcmp($2->type->name,"int")!=0)
						{
							printf("%s\n",$2->type->name);
							printf("return type error --> main\n");
							exit(1);
						}
					}
					else
					{
						if(strcmp($2->type->name,func_->type->name)!=0)
						{
							printf("return type error --> %s\n",mem_func->name);
							exit(1);
						}
					}
				}

				}
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
	  class_stmts {$$=$1;}|
	  BREAK';' {$$=create_tree(0,TLookup("void"),NULL,break_node,NULL,NULL,NULL);}|
	  CONTINUE';'{$$=create_tree(0,TLookup("void"),NULL,continue_node,NULL,NULL,NULL);} |
	  //func_call {} |
	  FREE'('IDEN')'';' {typecheck($3);$$=create_tree(0,TLookup("void"),NULL,free_node,$3,NULL,NULL);};
		;
class_stmts :
				IDEN '=' NEW '(' IDEN ')' ';' 
				{
					typecheck($1);
					struct Classtable* ctemp=CLookup($5->varname);
					if(ctemp==NULL)
					{
						printf("class %s not found\n",ctemp->name);
						exit(1);
					}
					$1->Ctype=ctemp;
					$5->nodetype=new_node;
					$5->Ctype=ctemp;
					$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$5,NULL);
				}
				|
			//
				FIELD '=' NEW '(' IDEN ')' ';' 
				{
					struct Classtable* ctemp=CLookup($5->varname);
					if(ctemp==NULL)
					{
						printf("class %s not found\n",ctemp->name);
						exit(1);
					}
					$1->Ctype=ctemp;
					$5->nodetype=new_node;
					$5->Ctype=ctemp;
					$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$5,NULL);
				}
				|
				DELETE '(' FIELD ')' ';' 
				{
					typecheck($3);
					$$=create_tree(0,TLookup("void"),NULL,del_node,$3,NULL,NULL);
				}
				;


Assign_stmt : IDEN'='expr';'	{typecheck($1);$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	|FIELD'='expr ';' {$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	|IDEN'='Heapstuff ';'{typecheck($1);$$=create_tree(0,TLookup("void"),"=",assg_node,$1,$3,NULL);}
	;
Inp_stmt :READ'('IDEN')'';'	{
	typecheck($3);
	$$=create_tree(0,TLookup("void"),NULL,read_node,$3,NULL,NULL);
	//printf("%s\n",$3->Gentry->name);
	}
	|
	READ'('FIELD')'';'	{
	//typecheck($3);
	$$=create_tree(0,TLookup("void"),NULL,read_node,$3,NULL,NULL);
	//printf("%s\n",$3->Gentry->name);
	}
	;

out_stmt :WRITE'('expr')'';'	{$$=create_tree(0,TLookup("void"),NULL,write_node,$3,NULL,NULL);};


Heapstuff : INITIALIZE'('')' {$$=create_tree(0,TLookup("int"),NULL,initia_node,NULL,NULL,NULL);}
		|	ALLOC'('')' {$$=create_tree(0,TLookup("void"),NULL,alloc_node,NULL,NULL,NULL);}
	;

//typecheck properly




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
	//|ID '('')' 		{$$=create_tree(0,TLookup("void"),$1,func_node,NULL,NULL,NULL);}
    |ID '('ArgList')' {$$=create_tree(0,TLookup("void"),$1,func_node,$3,NULL,NULL);}
	|FIELD  {$$= $1;}
	|FieldFunction {$$=$1;}
	|NULLTKN {$$=$1;}
	;
ArgList : expr ','  ArgList{$1->arg =$3;$$=$1;}
        | expr {$$=$1;$$->arg=NULL;};
		| {$$ =NULL;} //no args

IDEN : ID {$$=create_tree(0,TLookup("void"),$1,var_node,NULL,NULL,NULL);}		
		|
		ID '['expr']' {$$=create_tree(0,TLookup("void"),$1,arr_node,$3,NULL,NULL);}
		;
%%
int yyerror(char const *s)
{
	printf("yyerror %s-->%d\n",s,ins_cnt);
}
int main()
{
	yyin=fopen("inp.expl","r");
	FILE *fp =fopen("task.xsm","wt");
	yyparse();
	return 0;
}