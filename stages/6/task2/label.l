%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"

	#include"task.h"
    #include"task.c"
	int yyerror(char const*);
	int number;
	//int is_lab=0;
	int ins_cnt=0,wrap_no=0;
	FILE *f;
	struct lbl *head=NULL,*tail=NULL;
	int declflag=0;
%}

