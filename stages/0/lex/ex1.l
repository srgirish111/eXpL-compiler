%{
    #include<stdio.h>
int nlines,nwords,nchars;
%}

%%
\n {
	nchars++;nlines++; 
	}
 
[^ \n\t]+ {nwords++, nchars=nchars+yyleng;}
. {nchars++;}
%%
int yywrap(void)
{
 return 1;
}
int main() 
{
	yyin=fopen("inp1.txt","r");
    yylex();
    printf("Lines = %d\nChars=%d\nWords=%d",nlines,nchars,nwords);

 return 0;
} 