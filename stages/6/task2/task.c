int stack[50];
int top = -1;
int binding_add = 4096;
int f_no =1;
int lcl_bind =1,lcl_length=0;


struct Typetable *t_head=NULL,*t_tail=NULL;
struct Gsymbol *sym_tab_head=NULL, *sym_tab_tail=NULL;
struct Lsymbol *lcl_head =NULL,*lcl_tail=NULL;

struct tnode* create_tree(int val,struct Typetable *type,char* varname,int nodetype,struct tnode *l,struct tnode *r,struct tnode *m)
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

    if(nodetype!=var_node)
    typecheck(temp);

	return temp;
}
int is_struct(char *name)
{
    if(strcmp(name,"int")==0 || strcmp(name,"str")==0 ||strcmp(name,"bool")==0 ||strcmp(name,"void")==0)
    {
        return 0;
    }
    return 1;
}
void typecheck(struct tnode *t)
{
    struct Gsymbol *temp;
    struct Lsymbol *ltemp;
    //printf("%s\n",t->varname);
    switch (t->nodetype)
    {
    case op_node:
        if(strcmp(t->left->type->name,"int")!=0 || strcmp(t->right->type->name,"int")!=0 )
        {
            printf("expected inttype on both sides of OPERATOR : %c",*(t->varname));
            exit(1);
        }
        break;

    case assg_node:
        if(t->left->nodetype!=var_node && t->left->nodetype!=field_node )
        {
            printf("expected a variable near assignment(=)\n");
            
            exit(1);
        }
        if(t->left->type != t->right->type && t->right->nodetype!=null_node && t->right->nodetype!=alloc_node )
        {
            printf("type mismatch on = operator\n");
            inorder(t);
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
        if(t->left->nodetype!=var_node &&t->left->nodetype!=field_node &&t->left->nodetype!=sconst_node &&t->left->nodetype !=iconst_node)
        {
            printf("expected a var /string const/int const inside WRITE");
            exit(1);
        }
        break;
    case if_node:
        if(strcmp(t->left->type->name,"bool")!=0)
        {
            printf("expected a booltype inside IF statement");
            exit(1);
        }
        break;
    case while_node:
        if(strcmp(t->left->type->name,"bool")!=0)
        {
            printf("expected a booltype inside WHILE statement");
            exit(1);
        }
        break;
    case relop_node:
        //inorder(t);
        if((strcmp(t->left->type->name,"int")!=0|| strcmp(t->right->type->name,"int")!=0) && !(is_struct(t->left->type->name) && t->right->nodetype==null_node) )
            {
                printf("expected matching type exprs on both sides of RELOP -- %d\n",ins_cnt);
                exit(1);
            }
        break;
    case log_node:
            if(*(t->varname) != '!')
            {
                if(strcmp(t->left->type->name,"bool")!=0 || strcmp(t->right->type->name,"bool")!=0)
                {
                    printf("expected booltype statements on both sides of LOGIC -- %d\n",ins_cnt);
                    inorder(t);
                    exit(1);
                }
            }
            else
            {
                if(strcmp(t->left->type->name,"bool")!=0)
                {
                    printf("expected booltype before not --%d\n",ins_cnt);
                    //inorder(t);
                    exit(1);

                }
            }
        break;
    case var_node:
        ltemp=LLookup(t->varname);
        //printf("%s , %s\n",t->varname,ltemp->type->name);
        if(ltemp==NULL)
        {
            temp=GLookup(t->varname);
            if(temp==NULL)
            {
                printf("Variable:%s Undeclared\n",t->varname);
                exit(1);
            }
            t->type=temp->type;
            t->Gentry=temp;
        }
        else
        {
            t->type=ltemp->type;
            t->Lentry=ltemp;
        }
		break;
    case func_node:
        temp=GLookup(t->varname);
        if(temp==NULL)
        {
            printf("Function:%s Undeclared\n",t->varname);
            exit(1);
        }
        if(temp->size < 0)
        {
            printf(" %s:function declared but not defined\n",t->varname);
            exit(1);
        }
        argcheck(t->left,temp);
        t->type=temp->type;
        t->Gentry=temp;
        break;
    case free_node:
        if(t->left->nodetype!=var_node)
        {
            printf("expected variable inside free node\n");
            exit(1);
        }
        break;
    }
}

void print_param(struct param *temp)
{
    printf("<<<<<<<<<<<<param>>>>>>>>>>>\n");
    while(temp!=NULL)
    {
        printf("%s\t%s\n",temp->name,temp->type->name);
        temp=temp->next;
    }
}
void argcheck(struct tnode *t,struct Gsymbol *func)
{
    struct tnode *temp1;
    struct param *temp2;
    temp1=t;
    temp2=func->paramlist;
    //print_node(temp1);
    //print_param(temp2);
    //if()
    inorder(temp1->arg);
    //if(temp1->arg->arg==NULL){printf("workingfine\n\n");}
    //inorder(temp1->arg->arg);
    while (temp1!=NULL && temp2!=NULL)
    {
        if(temp1->type!=temp2->type)
        {
            printf("%s : type of parameters dont match",func->name);
            print_node(temp1);
            exit(1);
        }
        temp1 =temp1->arg;
        temp2 =temp2->next;
    }

    if(temp1==NULL ^ temp2==NULL)
    {
        printf("%s :no of function parameters donot match -->%d\n",func->name,ins_cnt);
        //inorder(temp1);
        //inorder(t);
        exit(1);
    }

    
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
        printf("~~~~~~~~~~~~~~~~~\n");
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
        break;
    case 14:
        printf("func_node");
        break;
    case 15:
        printf("ret_node");
        break;
    case 16:
        printf("log_node");
        break;
    case 17:
        printf("initia_node");
        break;
    case 18:
        printf("alloc_node");
    break;
    case 19:
        printf("free_node");
    break;
    case 20:
        printf("field_node");
    break;
    case 21:
        printf("null_node");
    break;
    case 22:
        printf("arr_node");
    break;
    
	}
    printf("type:%s val:%d ",t->type->name,t->val);
	if(t->varname!=NULL)
	printf("varname:%s ",t->varname);
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
    FILE *fp =fopen("task.xsm","wt");
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
        freereg();
        fclose(fp);
     	return i;
    }
    else if(strcmp("initialize",scall)==0)
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

     	fprintf(fp,"POP R19\n");

	j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
	freereg();
	return 19;



   }

   else if(strcmp("Alloc",scall)==0)
   {
	i=getreg();
    fprintf(fp,"MOV R%d,\"%s\"\n",i,scall);
    fprintf(fp,"PUSH R%d\n",i);
	fprintf(fp,"MOV R%d,8\n",i);
	fprintf(fp,"PUSH R%d\n",i);
	j=getreg();

     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	freereg();

     	fprintf(fp,"POP R19\n");

	j=getreg();
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
    freereg();
	freereg();
	return 19;


   }
   else if(strcmp("Free",scall)==0)
   {
	i=getreg();
	//fprintf(fp,"MOV [%d],R%d\n",sp,arg1);
	
     	fprintf(fp,"MOV R%d,\"%s\"\n",i,scall);
     	fprintf(fp,"PUSH R%d\n",i);
     	//fprintf(fp,"MOV R%d,R%d\n",i,arg1);
     	fprintf(fp,"PUSH R%d\n",arg1);
   	fclose(fp);

	j=getreg();
	fp=fopen("task.xsm","a");
     	fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"PUSH R%d\n",j);
	    fprintf(fp,"PUSH R%d\n",j);
     	fprintf(fp,"CALL 0\n");
	fclose(fp);
	freereg();

    fp=fopen("task.xsm","a");
	fprintf(fp,"POP R%d\n",i);
	fclose(fp);

	j=getreg();
	fp=fopen("task.xsm","a");
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
     	fprintf(fp,"POP R%d\n",j);
	fclose(fp);
     	freereg();
     
	freereg();
	return i;
   }

}



void insertlabel(char *name)
{
    
    char *temp;
    temp =(char*)malloc(strlen(name)*sizeof(char));
    temp= strdup(name);
    int num=0,i=0;
	while(temp[i]!=':')
    {
        ++i;
    }
    temp[i]='\0';
    struct lbl *new;
    new =(struct lbl*)malloc(sizeof(struct lbl));
    new->name = temp;
    new->address = 2048 + (ins_cnt)*2;
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
int searchlabel(char *name)
{
    struct lbl *temp;
    temp=head;
    int i=0;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
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
        printf("%s--",temp->name);
        printf("%d\n",temp->address);
        temp=temp->next;
    }
}


void print_symbol_table()
{
    struct Gsymbol *temp;
    temp = sym_tab_head;
    printf("Name \tType \tSize\tBinding\tflabel\n");
    printf("-------------------------------\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%d\t%d\t%d\n", temp->name, temp->type->name, temp->size, temp->binding,temp->flabel);
        temp = temp->next;
    }
    
}
struct Gsymbol *GLookup(char *name)
{
    struct Gsymbol *temp;
    temp = sym_tab_head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void GInstall(char *name, struct Typetable *type, int size,struct param *p)
{
    if (GLookup(name) != NULL)
    {
        printf("definition of variable/function already exists : %s\n", name);
        exit(1);
    }
    struct Gsymbol *temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;

    if(size>0)
    {
        temp->binding = binding_add;
        binding_add += size;
    }
    temp->paramlist = p;
    if(p!=NULL)
    temp->flabel= f_no++;
    else
    temp->flabel=-1;

    if (sym_tab_head == NULL)
    {
        sym_tab_head = temp;
        sym_tab_tail = temp;
        temp->next =NULL;
        return;
    }
    sym_tab_tail->next = temp;
    sym_tab_tail = temp;
    temp->next =NULL;
}

struct param *create_par(char *name,struct Typetable *type)
{
    struct param *new;
    new =(struct param *)malloc(sizeof(struct param));
    new->name =  (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(new->name,name);
    new->type =type;
    new->next =NULL;
    return new;
}
void PInstall(struct param *str,struct param *new)
{
    struct param *temp;
    temp = str;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next =new;
}

void check_name_equi(struct Typetable *type,char *name,struct param *p)
{
    struct Gsymbol *temp = sym_tab_head;
    while(temp!=NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==NULL)
    {
        printf("%s :function declaration not found",name);
        exit(1);
    }
    if(strcmp(temp->type->name,type->name)!=0)
    {
        printf("%s :function declared with different return type",name);
        exit(1);
    }

    if(temp->size !=-1)
    {
        printf("%s :multiple definitions of functions found",name);
        exit(1);
    }
    temp->size=0;
    //check parm list
    struct param *qq;
    qq = temp->paramlist;
    while(qq!=NULL &&p!=NULL)
    {
       
        if(strcmp(qq->name,p->name)!=0)
        {
            printf("%s :difference in parameter names in def and decl",name);
            exit(1);
        }
        if(qq->type != p->type)
        {
            printf("%s :difference in parameter tyeps in def and decl",name);
            exit(1);
        }
        p = p->next;
        qq= qq->next;
    }
    if(p==NULL ^ qq==NULL)
    {
        printf("%s :difference in number of parmeters in function decl and def",name);
        exit(1);
    }



}



struct Lsymbol *LLookup(char *name)
{
    struct Lsymbol *temp;
    temp = lcl_head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void LInstall(char *name, struct Typetable *type)
{
    ++lcl_length;
    if (LLookup(name) != NULL)
    {
        printf("definition of variable/function already exists : %s\n", name);
        exit(1);
    }
    struct Lsymbol *temp;
    temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
    temp->name = (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(temp->name, name);
    temp->type = type;
    temp->binding = lcl_bind++;

    if (lcl_head == NULL)
    {
        lcl_head = temp;
        lcl_tail = temp;
        temp->next =NULL;
        return;
    }
    lcl_tail->next = temp;
    lcl_tail = temp;
    temp->next =NULL;
}

void alocate_param(struct param *p)
{
    if(p==NULL)
    return;
    struct param *temp;
    temp= p;
    //int x=lcl_bind;
    lcl_bind=-2;
    while(temp!=NULL)
    {
        --lcl_bind;
        temp=temp->next;
    }
    
    temp=p;
    while(temp!=NULL)
    {
        LInstall(temp->name,temp->type);
        temp=temp->next;
    }
    lcl_bind=1;
    lcl_length=0;


}

void print_lcl_tab()
{
    struct Lsymbol *temp;
    temp =lcl_head;
    printf("Name \tType \tBinding\n");
    printf("------------------------------\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%d\n", temp->name, temp->type->name, temp->binding);
        temp = temp->next;
    }
}


//when return is executed
void free_lcl_tab()
{
    lcl_bind=1;
    lcl_length=0;
    struct Lsymbol *temp,*temp2;
    temp =lcl_head;
    lcl_head=NULL;
    lcl_tail=NULL;
    while (temp!=NULL)
    {
        temp2=temp;
        temp=temp->next;
        free(temp2);
    }
    
}


void deletetree(struct tnode *t)
{
    if(t==NULL)
	return;
	
	deletetree(t->left);
	deletetree(t->mid);
	deletetree(t->right);
    free(t);
}

int getaddr(struct tnode* t)
{
  	int i,j,l,base;
 	FILE *fp=NULL;
	struct Lsymbol *local;
	struct Gsymbol *global;
	
   	if(t->nodetype==arr_node)
   	{
		if(t->Gentry==NULL)
		{
			printf("HEY ITS NULL___________\n");
			exit(1);
		}
		base=t->Gentry->binding;
		printf("addr of base:%d\n",base);
 		l=codegen(t->left);
		//freereg();
		fp=fopen("task.xsm","a");
		fprintf(fp,"ADD R%d,%d\n",l,t->Gentry->binding);
		fclose(fp);
		return l;
   	}

	if(t->nodetype==var_node)
	{
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("task.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
			printf("addr of global variable:%d\n",t->Gentry->binding);
			//freereg();
			return i;
		}
		else
		{
			i=getreg();
			fp=fopen("task.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
			printf("relative addr of local variable:%d\n",local->binding);
			return i;
		}
	}
	if(t->nodetype==field_node)
	{
		int addr;
		struct tnode *temp;
		//i=getreg();
		local=LLookup(t->varname);
		if(local==NULL)
		{
	   		i=getreg();
			fp=fopen("task.xsm","a");
			fprintf(fp,"MOV R%d,%d\n",i,t->Gentry->binding);
			fclose(fp);
			//printf("addr of global variable:%d\n",t->Gentry->binding);
			//freereg();
			//return i;
		}
		else
		{
			i=getreg();
			fp=fopen("task.xsm","a");
			fprintf(fp,"MOV R%d,BP\n",i);
			fprintf(fp,"ADD R%d,%d\n",i,local->binding);
			fclose(fp);
			//printf("relative addr of local variable:%d\n",local->binding);
			//return i;
		}
		fp=fopen("task.xsm","a");
		fprintf(fp,"MOV R%d, [R%d]\n",i,i);
		fclose(fp);
		temp=t->mid;
		while(temp!=NULL)
		{
			fp=fopen("task.xsm","a");
			fprintf(fp,"ADD R%d, %d\n",i,temp->val);
			fclose(fp);
			if(temp->mid!=NULL)
			{
				fp=fopen("task.xsm","a");
				fprintf(fp,"MOV R%d, [R%d]\n",i,i);
				fclose(fp);
			}
			temp=temp->mid;
		}
		return i;
	}
}

int codegen(struct tnode* t)
{
    if(t==NULL)
    {
        return -1;
    }
    FILE *fp=NULL;
    fp=fopen("task.xsm","a");
    int temp,i,no_args=0;
    struct tnode* temp_tnode;
    struct Gsymbol *temp_Gsym;
    struct Lsymbol *temp_Lsym;
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
        case assg_node:
            l=getaddr(t->left);
			r=codegen(t->right);
			
			fp=fopen("task.xsm","a");
			fprintf(fp,"MOV [R%d],R%d\n",l,r);
			fclose(fp);
			freereg();
			freereg();
			printf("reg--->%d\n",q);
			return l;
			break;
        case read_node:
            temp=getaddr(t->left);
            fclose(fp);
            temp =sys_call("Read",-1,temp);
            freereg();
            break;
        case write_node:
            fclose(fp);
            temp =codegen(t->left);
            temp =sys_call("Write",-2,temp);
            freereg();
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
            fclose(fp);
            temp=getaddr(t);
            fp=fopen("task.xsm","a");
            fprintf(fp,"MOV R%d,[R%d]\n",temp,temp);
            fclose(fp);
            return temp;
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
                case '%':
                {
                    fprintf(fp, "MOD R%d,R%d\n", l, r);
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
            //inorder(t->mid);
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
                r=codegen(t->right);
                fp=fopen("task.xsm","a");
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
            fclose(fp);
            l=codegen(t->left);
			r=codegen(t->right);
            fp=fopen("task.xsm","a");
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
        case log_node:
            fclose(fp);
            l=codegen(t->left);
            r=codegen(t->right);
            fp=fopen("task.xsm","a");
            if(strcmp(t->varname,"&&")==0)
            {
                fprintf(fp,"MUL R%d,R%d\n",l,r);
                freereg();
            }
            else if(strcmp(t->varname,"||")==0)
            {
                fprintf(fp,"ADD R%d,1\n",l);
                fprintf(fp,"MOD R%d,2\n",l);

                fprintf(fp,"ADD R%d,1\n",r);
                fprintf(fp,"MOD R%d,2\n",r);

                fprintf(fp,"MUL R%d,R%d\n",l,r);

                fprintf(fp,"ADD R%d,1\n",l);
                fprintf(fp,"MOD R%d,2\n",l);
                freereg();
            }
            else if(strcmp(t->varname,"!")==0)
            {
                fprintf(fp,"ADD R%d,1\n",l);
                fprintf(fp,"MOD R%d,2\n",l);
            }
            fclose(fp);
            return l;
            break;
        case break_node:
            if(top>=0)
            {
                fprintf(fp, "JMP L%d\n", stack[top]+1);
            }
            fclose(fp);
            break;
        case continue_node:
            if(top>=0)
            {
                fprintf(fp, "JMP L%d\n", stack[top]);
            }
            fclose(fp);
            break;
        
        case ret_node:
            //fp=fopen("task.xsm","a");
            fprintf(fp,"SUB SP,%d\n",lcl_length);
            fclose(fp);

            l=codegen(t->left);
            fp=fopen("task.xsm","a");
            fprintf(fp,"SUB BP,2\n");
            fprintf(fp,"MOV [BP],R%d\n",l);
            fprintf(fp,"POP BP\n");
            fprintf(fp,"RET\n");
            fclose(fp);
            freereg();
            break;
        case func_node:
            //push all registers in use and free them
            
            temp=q;
            i=0;
            while(i<=temp)
            {
                fprintf(fp,"PUSH R%d\n",i);
                ++i;
            }
            q=-1;

            //evaluate args and push them
            
            temp_tnode= t->left;
            fclose(fp);
            while(temp_tnode!=NULL)
            {
                l=codegen(temp_tnode);
                fp=fopen("task.xsm","a");
                fprintf(fp,"PUSH R%d\n",l);
                freereg();
                fclose(fp);
                ++no_args;
                temp_tnode=temp_tnode->arg;
            }
            //empty space for return value
            fp=fopen("task.xsm","a");
            fprintf(fp,"PUSH R%d\n",0);
            freereg();
            //getlabel and generate call to that label
            i =t->Gentry->flabel;
            fprintf(fp,"CALL F%d\n",i);
            

            //returns from function
            fprintf(fp,"POP R19\n");

            //pop out args
            while(no_args>0)
            {
                fprintf(fp,"POP R%d\n",0);
                --no_args;
            }
           //restore regs
            q=temp;
            while (temp>=0)
            {
                fprintf(fp,"POP R%d\n",temp);
                --temp;
            }
            temp=getreg();
            fprintf(fp,"MOV R%d,R19\n",temp);
            fclose(fp);
            return temp;
            break;
        case initia_node:
            //push all registers in use and free them
            temp=q;
            i=0;
            while(i<=temp)
            {
                fprintf(fp,"PUSH R%d\n",i);
                ++i;
            }
            fclose(fp);
            q=-1;
            i=sys_call("initialize",0,0);
            q=temp;
            while (temp>=0)
            {
                fp=fopen("task.xsm","a");
                fprintf(fp,"POP R%d\n",temp);
                fclose(fp);
                --temp;
            }
            temp=getreg();
            fp=fopen("task.xsm","a");
            fprintf(fp,"MOV R%d,R19\n",temp);
            fclose(fp);
            return temp;
            break;
        case alloc_node:
            temp=q;
            i=0;
            while(i<=temp)
            {
                fprintf(fp,"PUSH R%d\n",i);
                ++i;
            }
            fclose(fp);
            q=-1;
            i=sys_call("Alloc",8,0);
            q=temp;
            while (temp>=0)
            {
                fp=fopen("task.xsm","a");
                fprintf(fp,"POP R%d\n",temp);
                --temp;
            }
            temp=getreg();
            fprintf(fp,"MOV R%d,R19\n",temp);
            fclose(fp);
            return temp;
            break;
        case free_node:
            fclose(fp);
            l=codegen(t->left);
            i=sys_call("Free",l,0);
            freereg();
            break;
        case field_node:
            fclose(fp);
            i=getaddr(t);
            fp=fopen("task.xsm","a");
            fprintf(fp,"MOV R%d,[R%d]\n",i,i);
            fclose(fp);
            return i;
            break;
        case arr_node:
            if(t->Gentry==NULL)
				{
					printf(" ITS NULL \n");
				//exit(1);
				}
				i=getaddr(t);
				fp=fopen("task.xsm","a");
				fprintf(fp,"MOV R%d,[R%d]\n",i,i);
				fclose(fp);
				return i;
			break;
        case null_node:
            i=getreg();
			fprintf(fp,"MOV R%d, 0\n",i);
            fclose(fp);
			return i;
            break;
    } 
    return 0;
}


void func_starter(char *name)
{
    //printf("hi");
    struct Gsymbol *temp;
    temp =GLookup(name);
    //printf("hello\n");
    FILE *fp;
    fp=fopen("task.xsm","a");
    fprintf(fp,"F%d:\n",temp->flabel);
    fprintf(fp,"PUSH BP\n");
    fprintf(fp,"MOV BP,SP\n");
    fprintf(fp,"ADD SP,%d\n",lcl_length);

    fclose(fp);    
}

void main_starter()
{
    FILE *fp;
    fp=fopen("task.xsm","a");
    fprintf(fp,"F0:\n");
    fprintf(fp,"PUSH BP\n");
    fprintf(fp,"MOV BP,SP\n");
    fprintf(fp,"ADD SP,%d\n",lcl_length);
    fclose(fp); 

}


////////////////////////////////////
struct Typetable* TLookup(char *name) 
{
    struct Typetable *temp;
    temp = t_head;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields)
{
    if (TLookup(name) != NULL)
    {
        printf("definition of type already exists : %s\n", name);
        exit(1);
    }
    //if (type != inttype && type != booltype && type != strtype)

    struct Typetable *temp;
    temp = (struct Typetable *)malloc(sizeof(struct Typetable));
    temp->name = (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(temp->name, name);
    temp->size = size;

    temp->fields = fields;
    
    temp->next =NULL;
    if (t_head == NULL)
    {
        t_head = temp;
        t_tail = temp;
        
        return temp;
    }
    t_tail->next = temp;
    t_tail = temp;
    return temp;
}

void TypeTableCreate(){
    struct Typetable *temp;
    char name[5]= "int";
    temp=TInstall(name,1,NULL);
    strcpy(name,"str");
    temp=TInstall(name,1,NULL);
    strcpy(name,"bool");
    temp=TInstall(name,1,NULL);
    strcpy(name,"void");
    temp=TInstall(name,1,NULL);
    strcpy(name,"null");
    temp=TInstall(name,1,NULL);
}

int GetSize(Typetable * type)
{
    int size=0;
	struct Fieldlist *temp;
	if(strcmp(type->name,"bool")==0||strcmp(type->name,"void")==0)
		return 0;
	if(strcmp(type->name,"int")==0||strcmp(type->name,"str")==0)
		return 1;
	temp=type->fields;
	while(temp!=NULL)
	{	
		size++;
		temp=temp->next;
	}
	return size;
}

struct Fieldlist* FLookup(Typetable *type, char *name)
{
    struct Fieldlist *temp;
    temp=type->fields;
    while (temp!=NULL)
    {
        if(strcmp(temp->name,name)==0)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
    
}

struct Fieldlist* Fcreate(char *name,char *type)
{
    struct Typetable* temp;
    temp=TLookup(type);
    if(temp==NULL)
    {
        printf("in type ->> %s type isnt defined\n",name);
        exit(1); 
    }
    struct Fieldlist* new;
    new = (struct Fieldlist *)malloc(sizeof(struct Fieldlist));
    new->name = (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(new->name, name);
    new->type=temp;
    new->next=NULL;
    new->fieldIndex=size;
    return new;
}

void print_type(Typetable * type)
{
    Fieldlist *temp;
    printf("type --> %s\n",type->name);
    printf("size --> %d\n",type->size);
    temp=type->fields;
    printf("name\tfieldIndex\ttype\n");
    printf("---------------------------------\n");
    while(temp!=NULL)
    {
        printf("%s\t%d\t%s\n",temp->name,temp->fieldIndex,temp->type->name);
        temp=temp->next;
    }

}

void field_add(struct tnode *f,struct tnode *s)
{
    
}



