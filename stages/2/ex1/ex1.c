int var[26];
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
int evaluate(struct tnode *t)
{
	int v,l,r,inp;	
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
			l=evaluate(t->right);
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
		break;
	}
}