struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r,struct tnode *m)
{
	printf("%d",nodetype);
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
    temp->mid =m;
    if((nodetype==if_node||nodetype==while_node) &&l->type!=booltype)
    {
        printf("expected a booltype expresion after if/while statement");
    }
    else if((nodetype==read_node||nodetype==write_node) && l->type !=inttype)
    {
        printf("expected a inttype after read/write statement");
    }
    else if(nodetype==assg_node && r->type!=inttype)
    {
        printf("expected inttype after assignment operator");
    }
    else if((nodetype==relop_node||nodetype==op_node)&&(l->type!=inttype ||r->type!=inttype))
    {
        printf("type mismatch");
    }
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
	case 8:
		printf("if_node");
		break;
	case 9:
		printf("while_node");
		break;
	case 10:
		printf("relop_node");
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
	inorder(t->mid);
	inorder(t->right);
}


int lab_no=0;
int getLabel()
{
    return lab_no++;
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
    FILE *fp =fopen("task.xsm","a");
    fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
    fprintf(fp, "MOV SP,4121\n");
    fclose(fp);
}  


int sys_call(char *scall,int arg1, int arg2)
{

    FILE *fp=fopen("task.xsm","a");
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
        fclose(fp);
     	return i;
    }

}


int codegen(struct tnode* t)
{
    FILE *fp;
    fp=fopen("task.xsm","a");
    int temp,i;
    int l, r,label_1,label_2;
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
        case if_node:
            label_1 = getLabel();
            label_2 = getLabel();
            fclose(fp);
            l=codegen(t->left);
            fp=fopen("task.xsm","a");
            fprintf(fp,"JZ R%d,L%d\n",l,label_1);
            freereg();
            fclose(fp);
            r=codegen(t->mid);
            fp=fopen("task.xsm","a");
            if(t->right != NULL)
            {
                fprintf(fp, "JMP L%d\n", label_2);
            }
            fprintf(fp, "L%d:\n", label_1);
            fclose(fp);
            if(t->right != NULL)
            {
                fp=fopen("task.xsm","a");
                r=codegen(t->right);
                fprintf(fp, "L%d:\n", label_2);
                fclose(fp);
            }
            
            break;
        case while_node:
            label_1 = getLabel();
            label_2 = getLabel();
            fprintf (fp, "L%d:\n", label_1);        // Place the first label here.
            fclose(fp);
            l=codegen(t->left);
            fp=fopen("task.xsm","a");
            fprintf(fp,"JZ R%d,L%d\n",l,label_2);
            fclose(fp);
            freereg();
            r=codegen(t->right);
            fp=fopen("task.xsm","a");
            fprintf(fp, "JMP L%d\n", label_1);   // return to the beginning of the loop.
            fprintf(fp, "L%d:\n", label_2);       // Place the second label here
            fclose(fp);
            return 1;
            break;
        case relop_node:
            l=codegen(t->left);
			r=codegen(t->right);
            if(strcmp(t->varname,">=")==0)
				{ 
					fprintf(fp,"GE R%d,R%d\n",l,r);
				}
			else if(strcmp(t->varname,"<=")==0)
				{ 
					fprintf(fp,"LE R%d,R%d\n",l,r);
				}
			else if(strcmp(t->varname,">")==0)
				{
					fprintf(fp,"GT R%d,R%d\n",l,r);
				}
			else if(strcmp(t->varname,"<")==0)
				{ 
					fprintf(fp,"LT R%d,R%d\n",l,r);
				}
			else if(strcmp(t->varname,"==")==0)
				{ 
					fprintf(fp,"EQ R%d,R%d\n",l,r);
				}
			else if(strcmp(t->varname,"!=")==0)
				{ 
					fprintf(fp,"NE R%d,R%d\n",l,r);
				}
            freereg();
            fclose(fp);
            return l;
            break;
        
        

    } 
}

void insertlabel(int labelnum)
{
    struct lbl *new;
    new =(struct lbl*)malloc(sizeof(struct lbl));
    new->val = labelnum;
    new->address = 2048 + ins_cnt*2;
    new->next =NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;
        return;
    }
    tail->next = new;
    tail =new;
}
int searchlabel(int labelnum)
{
    struct lbl *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->val==labelnum)
        {
            return temp->address;
        }
        temp=temp->next;
    }
    return -1;
}

void print_lbl_tbl()
{
    struct lbl *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        printf("%d\n",temp->address);
        temp=temp->next;
    }
}