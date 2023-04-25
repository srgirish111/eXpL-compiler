%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"

	#include"task.h"
	int yyerror(char const*);
	int number;
	//int is_lab=0;
	int ins_cnt=0;
	FILE *f;
	int declflag=0;
	int main_add;
	int field_flag=0;

%}

%%
[0-9]+	{
			
			number=atoi(yytext);
			yylval.numb=number;
			return NUM;
		

	}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"%"	{return MOD;}

";"	{return *yytext;}
"="	{return *yytext;}
[()]	{return *yytext;}
","	{return *yytext;}
"." {field_flag=1;return *yytext;}

">="	{return GE;}
"<="	{return LE;}
"=="	{return EQ;}
"!="	{return NE;}
">"	{return GT;}
"<"	{return LT;}
"AND"	{return ANDTKN;}
"OR"	{return ORTKN;}
"NOT"	{return NOTTKN;}

"begin" {return PBEGIN;}
"end"	{return PEND;}
"write"	{return WRITE;}
"read"	{return READ;}
"initialize" {return INITIALIZE;}
"alloc" {return ALLOC;}
"free" {return FREE;}

"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}

"while"	{return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}

"continue" {return CONTINUE;}
"break"    {return BREAK;}

"decl"  {declflag=1; return DECL;}
"enddecl" {declflag=0; return ENDDECL;}
"int" 	{return INT;}
"str"	{return STR;}
"main"	{return MAINFN;}
"return" {return RETURN;}
"type" {return TYPETKN;}
"endtype" {return ENDTYPETKN;}
"null"  {
		yylval.no=create_tree(0,TLookup("null"),"null",null_node,NULL,NULL,NULL);
		return NULLTKN;
		}

"class" {return CLASS;}
"endclass" {return ENDCLASS;}
"self" {return SELF;}
"delete" {return DELETE;}
"new" {return NEW;}

[\[\]]	{return *yytext;}
[{}]	{

		return *yytext;}
[ \t]+  {
	
}
[\n] {++ins_cnt;}


[a-zA-Z][a-zA-Z0-9_]*	{
			yylval.name=strdup(yytext);
			return ID;}
\"(\\.|[^"\\])*\"  {
			yylval.name=strdup(yytext);
			return MESG;
		}


.		{	
			printf("%s",yytext);
			yyerror("unknown character\n");
			exit(1);
		}

%%

int yywrap(void)
{

	return 1;
}

