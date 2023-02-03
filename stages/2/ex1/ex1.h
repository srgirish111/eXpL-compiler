#define op_node    1
#define assg_node  2
#define conn_node  3
#define const_node 4
#define read_node  5
#define var_node   6
#define write_node 7


struct tnode* create_tree(int val,int type,char *varname,int nodetype,struct tnode *l,struct tnode *r);
int evaluate(struct tnode *t);

typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left,*right;
}tnode;


