#define op_node    1
#define assg_node  2
#define conn_node  3
#define iconst_node 4
#define read_node  5
#define var_node   6
#define write_node 7
#define if_node 8
#define while_node 9
#define relop_node 10
#define break_node 11
#define continue_node 12
#define sconst_node 13

#define notype -1
#define booltype 0
#define inttype 1
#define strtype 2
struct tnode* create_tree(int val,int type,char *varname,int nodetype,struct tnode *l,struct tnode *r,struct tnode *m);
void inorder(struct tnode *t);
void print_node(struct tnode *t);
int sys_call(char *scall,int arg1, int arg2);
typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *left,*right,*mid;
}tnode;



typedef struct lbl
{
		int val;
		int address;
		struct lbl *next;
}lbl;
extern int ins_cnt,wrap_no;
extern struct lbl *head,*tail;

void insertlabel(int labelnum);
int searchlabel(int labelnum);
void print_lbl_tbl();

typedef struct Gsymbol {
  char* name;       // name of the variable
  int type;         // type of the variable
  int size;         // size of the type of the variable
  int binding;      // stores the static memory address allocated to the variable
  struct Gsymbol *next;
}Gsymbol;

struct Gsymbol *Lookup(char * name);
void Install(char *name, int type, int size);
void print_symbol_table();


extern int declflag;