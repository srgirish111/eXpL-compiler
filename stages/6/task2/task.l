%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"

	#include"task.h"
	int yyerror(char const*);
	int number;
	//int is_lab=0;
	int ins_cnt=0,wrap_no=0;
	FILE *f;
	struct lbl *head=NULL,*tail=NULL;
	int declflag=0;
	int main_add;
	int field_flag=0;

%}

%%
[0-9]+	{ 
		
					if(wrap_no==0)
		{
			number=atoi(yytext);
			yylval.numb=number;
			return NUM;
		}
		else if(wrap_no==1)
		{
			f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}
		else if(wrap_no==2)
		{
			f=fopen("task_fin.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}

	}
"+"	{return PLUS;}
"-"	{if(wrap_no==0)
			{return MINUS;}
			else if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%c",*yytext);
				fclose(f);
			}
			else if(wrap_no==2)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%c",*yytext);
				fclose(f);
			}
		}
"*"	{return MUL;}
"/"	{return DIV;}
"%"	{return MOD;}

";"	{return *yytext;}
"="	{return *yytext;}
[()]	{return *yytext;}
","	{if(wrap_no==0)
				{
					return *yytext;}
			else if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
			else if(wrap_no==2)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}}
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
"enddecl" {declflag=0;printf("enddecl\n"); return ENDDECL;}
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
[\[\]]	{if(wrap_no==0)
				{
					return *yytext;
				}
				else if(wrap_no==1)
				{
					f=fopen("task_int.xsm","a");
					fprintf(f,"%s",yytext);
					fclose(f);
				}
				else if(wrap_no==2)
				{
					f=fopen("task_fin.xsm","a");
					fprintf(f,"%s",yytext);
					fclose(f);
				};}
[{}]	{

		return *yytext;}
[ \t]+  {
	if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
			if(wrap_no==2)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
}
[\n] {

	if(wrap_no==0)
			{
				++ins_cnt;
			}
			else if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
				++ins_cnt;
			}
			else if(wrap_no==2)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);

			} 
	}
0\n2056\n0\n0\n0\n0\n0\n0\n	{
	if(wrap_no==1)
	{
		f=fopen("task_int.xsm","a");
		fprintf(f,"%s",yytext);
		fclose(f);
		ins_cnt+=4; 
	}
	if(wrap_no==2)
	{
		f=fopen("task_fin.xsm","a");
		fprintf(f,"%s",yytext);
		fclose(f);
	}
}
[L][0-9]+\n {
	   	if(wrap_no==1)
	   	{
	    	f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
			++ins_cnt;
        }
		else if(wrap_no==2)
		{
			f=fopen("task_fin.xsm","a");
			// num=0;
			//for(int i=1;yytext[i]!='\n';i++)
			
				//num=num*10+(yytext[i]-'0');
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			int i;
			for(i=0;yytext[i]!='\n';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
			int x=searchlabel(temp);
			fprintf(f,"%d\n",x);
			fclose(f);
		}
	  }
	
[L][0-9]+:\n {
	if(wrap_no==1)
	{
		insertlabel(yytext);
	}
}
[F][0-9]+\n {
	   	if(wrap_no==1)
	   	{
	    	f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
			++ins_cnt;
        }
		else if(wrap_no==2)
		{
			f=fopen("task_fin.xsm","a");
			// num=0;
			//for(int i=1;yytext[i]!='\n';i++)
			
				//num=num*10+(yytext[i]-'0');
			char *temp;
			temp=malloc(yyleng*sizeof(char));
			int i;
			for(i=0;yytext[i]!='\n';i++)
			{
				temp[i]=yytext[i];
			}
			temp[i]='\0';
			int x=searchlabel(temp);
			fprintf(f,"%d\n",x);
			fclose(f);
		}
	  }
	
[F][0-9]+:\n {
	if(wrap_no==1)
	{
		insertlabel(yytext);
	}
}


[a-zA-Z][a-zA-Z0-9]*	{
		if(wrap_no==0)
		{
			yylval.name=strdup(yytext);
			return ID;
		}
		else if(wrap_no==1)
		{
			f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}
		else if(wrap_no==2)
		{
			f=fopen("task_fin.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}
	}
\"(\\.|[^"\\])*\"  {
			
		
		if(wrap_no==0)
		{
			yylval.name=strdup(yytext);
			return MESG;
		}
		else if(wrap_no==1)
		{
			f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}
		else if(wrap_no==2)
		{
			f=fopen("task_fin.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
		}	
		}


.		{	
			if(wrap_no==0)
			{
			printf("%s",yytext);
			yyerror("unknown character\n");
			exit(1);
			}
			else if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
			else if(wrap_no==2)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
		}
%%

int yywrap(void)
{
if(wrap_no==0)
	{
		yyin=fopen("task.xsm","r");
		f =fopen("task_int.xsm","wt");
		fclose(f);
		ins_cnt=0;
		++wrap_no;
		yylex();
		return 0;
	}
	if(wrap_no==1)
	{
		ins_cnt=0;
		print_lbl_tbl();
		yyin=fopen("task_int.xsm","r");
		f =fopen("task_fin.xsm","wt");
		fclose(f);
		++wrap_no;
		yylex();
		return 0;
	}
	return 1;

}

