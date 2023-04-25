%{
	#include<stdio.h>
	#include<stdlib.h>
	//#include"y.tab.h"

	//#include"task.h"
    #include"label.c"
	int yyerror(char const*);
	int number;
	//int is_lab=0;
	int ins_cnt=0,wrap_no=0;
	FILE *f;
	int declflag=0;
%}
%%
0\n2056\n0\n0\n0\n0\n0\n0\n	{
	if(wrap_no==0)
	{
		f=fopen("task_int.xsm","a");
		fprintf(f,"%s",yytext);
		fclose(f);
		ins_cnt+=4; 
	}
	if(wrap_no==1)
	{
		f=fopen("task_fin.xsm","a");
		fprintf(f,"%s",yytext);
		fclose(f);
	}
}
[L][0-9]+\n {
		   	if(wrap_no==0)
	   	{
	    	f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
			++ins_cnt;
        }
		else if(wrap_no==1)
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
		insertlabel(yytext,ins_cnt);
}
[F][0-9]+\n {
	   	if(wrap_no==0)
	   	{
	    	f=fopen("task_int.xsm","a");
			fprintf(f,"%s",yytext);
			fclose(f);
			++ins_cnt;
        }
		else if(wrap_no==1)
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
		insertlabel(yytext,ins_cnt);
}

[\n] {

			if(wrap_no==0)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
				++ins_cnt;
			}
			else if(wrap_no==1)
			{
				f=fopen("task_fin.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);

			} 
	}


.		{	
			if(wrap_no==0)
			{
				f=fopen("task_int.xsm","a");
				fprintf(f,"%s",yytext);
				fclose(f);
			}
			else if(wrap_no==1)
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
int main()
{
	yyin=fopen("task.xsm","r");
	f =fopen("task_int.xsm","wt");
	fclose(f);
	yylex();
}

