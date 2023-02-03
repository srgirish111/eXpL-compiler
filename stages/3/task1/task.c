
struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r)
{
	struct tnode *temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	if(varname!=NULL)
   	{
    		temp->varname=(char*)malloc(sizeof(char));
    		temp->varname=varname;
    	}
	else
	{
		temp->varname=NULL;
	}
	temp->nodetype=nodetype;
	temp->left=l;
	temp->right=r;
	return temp;
}
void print_node(struct tnode *t)
{
	
	switch(t->nodetype)
	{
  	case 1:
    	printf("op_node ");
    	break;
    	case 2:
    	printf("assg_node ");
   	break;
    	case 3:
    	printf("conn_node ");
    	break;
    	case 4:
    	printf("const_node ");
   	break;
    	case 5:
  	printf("read_node ");
  	break;
    	case 6:
    	printf("var_node ");
   	break;
    	case 7:
    	printf("write_node ");
    	break; 
	}
    printf("type:%d val:%d ",t->type,t->val);
	if(t->varname!=NULL)
	printf("varname:%c ",*t->varname);
	printf("\n");
}

void inorder(struct tnode *t)
{
	if(t==NULL)
	return;
	inorder(t->left);
	print_node(t);
	inorder(t->right);

}


int q=-1;
int getreg()
{
    ++q;
    if(q>20)
        printf("registers exhausted\n");
    else
        return q;
}

void freereg()
{
    --q;
}
void headergen()
{
    FILE *fp =fopen("task2.xsm","a");
    fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fp, "MOV SP,4121\n");
    fclose(fp);
}  


int sys_call(char *scall,int arg1, int arg2)
{
    FILE *fp=fopen("task2.xsm","a");
 	int r,i,j;
  
    if(strcmp("Write",scall)==0)
    {
        i=getreg();
        fprintf(fp,"MOV R%d,\"%s\"\n",i,scall);
        fprintf(fp,"PUSH R%d\n",i);
        fprintf(fp,"MOV R%d,%d\n",i,arg1);
        fprintf(fp,"PUSH R%d\n",i);
        fprintf(fp,"PUSH R%d\n",arg2);
        j=getreg();
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"PUSH R%d\n",j);
        fprintf(fp,"CALL 0\n");
        freereg();
        fprintf(fp,"POP R%d\n",i);

        j=getreg();
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        fprintf(fp,"POP R%d\n",j);
        freereg();
        
        freereg();
        fclose(fp);
        return i;
    }
   else if(strcmp("Read",scall)==0)
   {
     	i=getreg();
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,scall);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",i);

     	fprintf(fp,"MOV R%d,%d\n",i,arg2);
     	fprintf(fp,"PUSH R%d\n",i);
	
	    j=getreg();
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	    freereg();
	
     	fprintf(fp,"POP R%d\n",i);

	    j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	freereg();

     	freereg();
     	fclose(fp);
	return i;
    }
   else if(strcmp("Exit",scall)==0)
   {
     	i=getreg();
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,scall);
	    fprintf(fp,"PUSH R%d\n",i);
     	j=getreg();
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
     	freereg();

     	return i;
    }

}


int codegen(struct tnode* t)
{
    FILE *fp;
    fp=fopen("task2.xsm","a");
    int temp,i;
    int l, r;

    switch(t->nodetype)
	{

		case conn_node:
            temp= codegen(t->left);
            temp= codegen(t->right);
            //returned val doesnt matter cuz each stmt is independent and commited to memory 
            fclose(fp);
			return temp;
            break;
        case read_node:
            temp =4096+*(t->left->varname)-'a';
            temp =sys_call("Read",-1,temp);
            fclose(fp);
			return temp;
            break;
        case write_node:
            temp =codegen(t->left);
            temp =sys_call("Write",-2,temp);
            freereg();
            fclose(fp);
			return temp;
            break;

        case const_node:
            temp=getreg();
			fprintf(fp,"MOV R%d,%d\n",temp,t->val);
			fclose(fp);
			return temp;
            break;
        case var_node:
            temp=4096 + *(t->varname)-'a';
			i=getreg();
			fprintf(fp,"MOV R%d,[%d]\n",i,temp);
			fclose(fp);
			return i;
            break;

        case assg_node:
            i=codegen(t->right);
			temp=4096+*(t->left->varname)-'a';
			fprintf(fp,"MOV [%d],R%d\n",temp,i);
			fclose(fp);
			freereg();
			return i;
            break;
        case op_node:
            
            l = codegen(t->left);
            r = codegen(t->right);
            switch (*(t->varname))
            {
                case '+':
                {
                    fprintf(fp, "ADD R%d,R%d\n", l, r);
                    break;
                }

                case '-':
                {
                    fprintf(fp, "SUB R%d,R%d\n", l, r);
                    break;
                }
                case '*':
                {
                    fprintf(fp, "MUL R%d,R%d\n", l, r);
                    break;
                }
                case '/':
                {
                    fprintf(fp, "DIV R%d,R%d\n", l, r);
                    break;
                }
            }
            freereg();
            fclose(fp);
            return l;
            break;
        
        

    } 
}
