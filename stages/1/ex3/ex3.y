%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ex3.h"
 	#include "ex3.c"
    FILE *fp;
    extern FILE *yyin;
	int yyerror(char const *s);
	int yylex(void);
%}
%union{
	 struct tnode *no;
	}
%token NUM PLUS MINUS MUL DIV END
%type <no> expr NUM program END	

%left PLUS MINUS
%left MUL DIV	
%%
	
program : expr END {   printf("tree generated!!!\n");
			//
			headergen();
			int aa= codegen($$);
			write_gen(aa);
			exit_gen();
			printf("xsm file generated");
			return 0;
		    }
	;
	
expr    : PLUS expr expr 	{$$ = makeOperatorNode('+',$2,$3);}
        | MINUS expr expr 	{$$ = makeOperatorNode('-',$2,$3);}
        | MUL expr expr 	{$$ = makeOperatorNode('*',$2,$3);}
        | DIV expr expr 	{$$ = makeOperatorNode('/',$2,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM		        {$$ = $1;}
	;
	
%%
	
int yyerror(char const *s)
{
	printf("yyerror %s",s);
}
	
	
int main(void) 
{
    yyin =fopen("inp.txt","r");
    yyparse();
    return 0;
}