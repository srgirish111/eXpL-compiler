int stack[50];
int top=-1;
int binding_add =4096;
struct Gsymbol *sym_tab_head,*sym_tab_tail;
struct tnode* create_tree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r,struct tnode *m)
{
	//printf("%d",nodetype);
	struct tnode *temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	if(varname!=NULL)
   	{
    		temp->varname=(char *)malloc((strlen(varname)+2)*sizeof(char));
    		strcpy(temp->varname,varname);
    	}
	else
	{
		temp->varname=NULL;
	}
    temp->Gentry = NULL;
	temp->nodetype=nodetype;
	temp->left=l;
	temp->right=r;
    temp->mid =m;
    typecheck(temp);
	return temp;
}
void typecheck(struct tnode *t)
{
    struct Gsymbol *temp;
    switch (t->nodetype)
    {
    case op_node:
        if(t->left->type!=inttype || t->right->type !=inttype )
        {
            printf("expected inttype on both sides of OPERATOR : %c",*(t->varname));
            exit(1);
        }
        break;

    case assg_node:
        if(t->left->nodetype!=var_node )
        {
            printf("expected a variable near assignment(=)");
            exit(1);
        }
        break;
    case read_node:
        if(t->left->nodetype!=var_node)
        {
            printf("expected a variable inside READ");
            exit(1);
        }
        break;
    case write_node:
        if(t->left->nodetype!=var_node &&t->left->nodetype!=sconst_node &&t->left->nodetype !=iconst_node)
        {
            printf("expected a var /string const/int const inside WRITE");
            exit(1);
        }
        break;
    case if_node:
        if(t->left->type!=booltype)
        {
            printf("expected a booltype inside IF statement");
            exit(1);
        }
        break;
    case while_node:
        if(t->left->type !=booltype)
        {
            printf("expected a booltype inside WHILE statement");
            exit(1);
        }
        break;
    case relop_node:
        if(t->left->type!=inttype|| t->right->type !=inttype)
        {
            printf("expected inttype statements on both sides of RELOP");
            exit(1);
        }
        break;
    case var_node:
		temp=Lookup(t->varname);
		if(temp==NULL)
		{
			printf("Variable:%s Undeclared\n",t->varname);
			exit(1);
		}
		t->type=temp->type;
        t->Gentry=temp;
		break;
    }
}
//print t->nodetype
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
    	printf("iconst_node ");
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
    case 11:
        printf("break_node");
        break;
    case 12:
        printf("continue_node");
        break;
    case 13:
        printf("sconst_node");
	}
    printf("type:%d val:%d ",t->type,t->val);
	if(t->varname!=NULL)
	printf("varname:%s ",t->varname);
	printf("\n");
}
void inorder(struct tnode *t)
{
	if(t==NULL)
	return;
	print_node(t);
	inorder(t->left);
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
    fprintf(fp, "MOV SP,%d\n",binding_add);
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
            
            //temp =sys_call("Read",-1,temp);

            if(t->left->left==NULL)
            {
                temp=t->left->Gentry->binding;
                i=getreg();
			    fprintf(fp,"MOV R%d,%d\n",i,temp);
                fclose(fp);
                temp=sys_call("Read",-1,i);
                freereg();
                
			    return i;
            }
            else
            {
                l = codegen(t->left->left);
                i=getreg();
                temp=t->left->Gentry->binding;
                fprintf(fp,"MOV R%d,%d\n",i,temp);
                fprintf(fp,"ADD R%d,R%d\n",i,l);
                fprintf(fp,"MOV R%d,R%d\n",l,i);
                freereg();
                fclose(fp);
                temp=sys_call("Read",-1,l);
                freereg();
                
                return l;
            }
            break;
        case write_node:
            temp =codegen(t->left);
            temp =sys_call("Write",-2,temp);
            freereg();
            fclose(fp);
			return temp;
            break;

        case iconst_node:
            temp=getreg();
			fprintf(fp,"MOV R%d,%d\n",temp,t->val);
			fclose(fp);
			return temp;
            break;
        
        case sconst_node:
            temp=getreg();
			fprintf(fp,"MOV R%d,%s\n",temp,t->varname);
			fclose(fp);
			return temp;
            break;
        case var_node:
            if(t->left==NULL)
            {
                temp=t->Gentry->binding;
                i=getreg();
			    fprintf(fp,"MOV R%d,[%d]\n",i,temp);
                fclose(fp);
			    return i;
            }
            else
            {
                l = codegen(t->left);
                i=getreg();
                temp=t->Gentry->binding;
                fprintf(fp,"MOV R%d,%d\n",i,temp);
                fprintf(fp,"ADD R%d,R%d\n",i,l);
                fprintf(fp,"MOV R%d,[R%d]\n",l,i);
                freereg();
                fclose(fp);
                return l;
            }

            break;

        case assg_node:
            //l=codegen(t->left);
            //somechanges need to be made here
            if(t->left->left==NULL)
            {
                temp=t->left->Gentry->binding;
                l=getreg();
			    fprintf(fp,"MOV R%d,%d\n",l,temp);
                fclose(fp);
			    //return i;
            }
            else
            {
                l = codegen(t->left->left);
                i=getreg();
                temp=t->left->Gentry->binding;
                fprintf(fp,"MOV R%d,%d\n",i,temp);
                fprintf(fp,"ADD R%d,R%d\n",i,l);
                fprintf(fp,"MOV R%d,R%d\n",l,i);
                freereg();
                fclose(fp);
                //return l;
            }
            r=codegen(t->right);
			//temp=t->left->Gentry->binding;
            fp=fopen("task.xsm","a");
			fprintf(fp,"MOV [R%d],R%d\n",l,r);
			fclose(fp);
			freereg();
            freereg();
			return l;
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
                label_2 = getLabel();
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
            stack[++top] =label_1;
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
            top--;
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
        case break_node:
            if(top>=0)
            {
                fp=fopen("task.xsm","a");
                fprintf(fp, "JMP L%d\n", stack[top]+1);
                fclose(fp);
            }
            break;
        case continue_node:
            if(top>=0)
            {
                fp=fopen("task.xsm","a");
                fprintf(fp, "JMP L%d\n", stack[top]);
                fclose(fp);
            }
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


void print_symbol_table()
{
	struct Gsymbol *temp=sym_tab_head;
	printf("Name \tType \tSize\tBinding\n");
	printf("-------------------------------\n");
	while(temp!=NULL)
	{
		printf("%s\t%d\t%d\t%d\n",temp->name,temp->type,temp->size,temp->binding);
		temp=temp->next;
	}
}
struct Gsymbol *Lookup(char * name)
{
    struct Gsymbol *temp;
    temp = sym_tab_head;
     

    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }
        temp =temp->next;
    }
    return NULL;
}
void Install(char *name, int type, int size)
{
    if(Lookup(name)!=NULL)
    {
        printf("variable is redefined : %s\n",name);
        exit(1);
    }
    if(type!=inttype&&type!=booltype &&type!=strtype )
    {
        printf("undefined type for variable %s\n",name);
    }
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    temp->name =(char *)malloc((strlen(name)+2)*sizeof(char));
    strcpy(temp->name,name);
    temp->type =type;
    temp->size=size;
    temp->binding =binding_add;
    binding_add += size;
    temp->next  =NULL;
    if(sym_tab_head==NULL)
    {
        sym_tab_head=temp;
        sym_tab_tail =temp;
        return;
    }
    sym_tab_tail->next=temp;
    sym_tab_tail=temp;
}


/*error possible 
check for freereg */