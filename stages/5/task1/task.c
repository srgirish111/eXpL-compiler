int stack[50];
int top = -1;
int binding_add = 4096;
int f_no =0;

struct Gsymbol *sym_tab_head=NULL, *sym_tab_tail=NULL;
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
		temp=GLookup(t->varname);
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
void print_symbol_table()
{
    struct Gsymbol *temp = sym_tab_head;
    printf("Name \tType \tSize\tBinding\tflabel\n");
    printf("-------------------------------\n");
    while (temp != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\n", temp->name, temp->type, temp->size, temp->binding,temp->flabel);
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
void GInstall(char *name, int type, int size,struct param *p)
{
    if (GLookup(name) != NULL)
    {
        printf("definition of variable/function already exists : %s\n", name);
        exit(1);
    }
    if (type != inttype && type != booltype && type != strtype)
    {
        printf("undefined type for variable %s\n", name);
    }
    struct Gsymbol *temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->binding = binding_add;
    binding_add += size;
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

struct param *create_par(char *name,int type)
{
    struct param *new;
    new =(struct param *)malloc(sizeof(struct param));
    new->name =  (char *)malloc((strlen(name) + 2) * sizeof(char));
    strcpy(new->name,name);
    new->type =type;
    new->next =NULL;
    return new;
}

struct param *PInstall(struct param *str,struct param *new)
{
    struct param *temp;
    temp = str;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next =new;
}

/*error possible
check for freereg */