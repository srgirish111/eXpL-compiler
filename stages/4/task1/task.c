
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
    typecheck(temp);
	return temp;
}
void typecheck(struct tnode *t)
{
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
            printf("expected a variable near assignment");
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
            printf("expected a booltype inside if statement");
            exit(1);
        }
        break;
    case while_node:
        if(t->left->type !=booltype)
        {
            printf("expected a booltype inside while statement");
            exit(1);
        }
        break;
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
    case 11:
        printf("break_node");
        break;
    case 12:
        printf("continue_node");
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