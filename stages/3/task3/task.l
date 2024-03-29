%{
	#include<stdio.h>
	#include<stdlib.h>
	
	#include"y.tab.h"
	#include"task.h"
	int yyerror(char const*);
	int number;
	int is_lab=0;
	int ins_cnt=0,wrap_no=0;
	FILE *f;
	struct lbl *head=NULL,*tail=NULL;
%}

/*struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r);*/
%%
[0-9]+	{	
		if(wrap_no==0)
		{
			number=atoi(yytext);
			yylval.no=create_tree(number,inttype,NULL,const_node,NULL,NULL,NULL);
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
[a-z]	{
		
		if(wrap_no==0)
		{
			yylval.no=create_tree(0,inttype,yytext,var_node,NULL,NULL,NULL);
			return ID;
		}
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
"begin"	{return PBEGIN;}
"read"	{return READ;}
"write"	{return WRITE;}
"end"	{return PEND;}
"+"		{return PLUS;}
"-"		{
		if(wrap_no==0)
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
"*"		{return MUL;}
"/"		{return DIV;}
[()]	{return *yytext;}
"<" 	{return GT;}
">" 	{return LT;}
"<=" 	{return GE;}
">=" 	{return LE;}
"==" 	{return EQ;}
"!=" 	{return NE;}
";"		{return *yytext;}
"="		{return *yytext;}
"if" 	{return IF;}
"then"  {return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}
"while" {return WHILE;}
"do"	{return DO;}
"endwhile" {return ENDWHILE;}
[ \t]+	{
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
[\n]	{
			if(wrap_no==1)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
				++ins_cnt;
			}
			if(wrap_no==2)
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

L[0-9]+\n {
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
			int num=0;
			for(int i=1;yytext[i]!='\n';i++)
			{
				num=num*10+(yytext[i]-'0');
			}
			int x=searchlabel(num);
			fprintf(f,"%d\n",x);
			fclose(f);
		}
	  }
	
L[0-9]+:\n {
	if(wrap_no==1)
	{
		int num=0;
		  for(int i=1;yytext[i]!=':';i++)
		  {
			num=num*10+(yytext[i]-'0');
		  }
		  insertlabel(num);
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
/*
f=fopen("task_int","a");
fprintf(f,"%s",yytext);
fclose(f);
*/