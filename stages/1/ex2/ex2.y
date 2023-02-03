%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ex2.h"
 	#include "ex2.c"
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
	
expr    : expr PLUS expr 	{$$ = makeOperatorNode('+',$1,$3);}
        | expr MINUS expr 	{$$ = makeOperatorNode('-',$1,$3);}
        | expr MUL expr 	{$$ = makeOperatorNode('*',$1,$3);}
        | expr DIV expr 	{$$ = makeOperatorNode('/',$1,$3);}
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