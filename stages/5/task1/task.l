%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"

	#include"task.h"
	int yyerror(char const*);
	int number;
	int declflag=0;
	
	
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
[\[\]]	{return *yytext;}
"main"	{return MAINFN;}
"return" {return RETURN;}
[{}]	{return *yytext;}
[ \t\n]+ { }

[a-zA-Z][a-zA-Z0-9]*	{
				yylval.name=strdup(yytext);
				return ID;
			}
["][^"\n]*["]  {
			yylval.name=strdup(yytext);
			return MESG;	
		}

. {printf("unknown character\n");
   exit(1);
   }
%%

int yywrap(void)
{
	 return 1;
}

