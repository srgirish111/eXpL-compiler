int var[26];

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
void preorder(struct tnode *t)
{
	if(t==NULL)
	return;
	
	preorder(t->left);
	print_node(t);
	preorder(t->mid);
	preorder(t->right);
}

int evaluate(struct tnode *t)
{
    if(t==NULL)
    return 0;
	int v,l,r,inp,temp;	
    int bool_ret;
	switch(t->nodetype)
	{
		case read_node:
			v=*(t->left->varname)-'a';
			inp=scanf("%d",&var[v]);
			return inp;
		break;

		case write_node:
			r=evaluate(t->left);
			printf("%d\n",r);
			return r;
		break;

		case conn_node:

			l=evaluate(t->left);
			r=evaluate(t->right);
			return l;
		break;
		
		case var_node:
			v=*(t->varname)-'a';
			return var[v];
		break;

		case const_node:
			return t->val;
		break;

		case assg_node:
			r=evaluate(t->right);
			v=*(t->left->varname)-'a';
			var[v]=r;
			return var[v];
		break;

		case op_node:
			l=evaluate(t->left);
			r=evaluate(t->right);
			switch(*(t->varname))
			{
				case '+':
					return l+r;
					break;
				case '-':
					return l-r;
					break;
				case '*':
					return l*r;
					break;
				case '/':
					return l/r;
					break;
			}
        case relop_node:
            l=evaluate(t->left);
			r=evaluate(t->right);
            if(strcmp(t->varname,">=")==0)
				{ 
					if(l>=r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"<=")==0)
				{ 
					if(l<=r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,">")==0)
				{
					if(l>r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"<")==0)
				{ 
					if(l<r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"==")==0)
				{ 
					if(l==r)
						return 1;
					else
						return 0;
				}
				else if(strcmp(t->varname,"!=")==0)
				{ 
					if(l!=r)
						return 1;
					else
						return 0;
				}
                break;
        case if_node:
            l=evaluate(t->left);
            if(l==1)
            {
                temp =evaluate(t->mid);
            }
            else
            {
                temp =evaluate(t->right);
            }
			//printf("if done");
            return 1;
            break;

        case while_node:
            while(evaluate(t->left)==1)
            {
                r=evaluate(t->right);
            }
            return 1;
		break;
	}
}