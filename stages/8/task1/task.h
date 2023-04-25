#define op_node        1
#define assg_node      2
#define conn_node      3
#define iconst_node    4
#define read_node      5
#define var_node       6
#define write_node     7
#define if_node        8
#define while_node     9
#define relop_node     10
#define break_node     11
#define continue_node  12
#define sconst_node    13
#define func_node      14
#define ret_node       15
#define log_node       16
#define initia_node    17
#define alloc_node     18
#define free_node      19
#define field_node     20 //typecheck done in productions itself
#define null_node      21
#define arr_node       22
#define self_fld_node  23 //done in prod
#define self_meth_node 24 //done in prod
#define cls_meth_node  25
#define mth_call_node  26
#define new_node       27
#define del_node       28


#define notype -1
#define booltype 0
#define inttype 1
#define strtype 2


typedef struct tnode{
    int val;                    // value of the constant
    char* varname;              // name of the variable
    struct Typetable *type;     // type of the variable
    struct Classtable *Ctype;
    int nodetype;               // node type information
    struct Gsymbol *Gentry;     // pointer to GST entry for global variables and functions
    struct Lsymbol *Lentry; 
    struct tnode *left,*right,*mid,*arg;  // left and right branches
}tnode;

typedef struct param 
{
    char *name;
    struct Typetable *type;
    struct param *next;
}param;

typedef struct Gsymbol {
  char* name;                   // name of the variable
  struct Typetable *type;                   // type of the variable
  struct Classtable *Ctype;
  int size;                     // size of the type of the variable or flag for whether function definition is present or not
  int binding;                  // stores the static memory address allocated to the variable
  int flabel;                   //a label for identifying the starting address of a function's code
  struct param *paramlist;//pointer to the head of the formal parameter list                    //in the case of functions
  struct Gsymbol *next;
}Gsymbol;

typedef struct Lsymbol{
    char *name; //name of the variable   
    struct Typetable *type;;  //type of the variable:(Integer / String)   
    struct Classtable *Ctype;
    int binding; //local binding of the variable   
    struct Lsymbol *next; //points to the next Local Symbol Table entry 
}Lsymbol;



struct tnode* create_tree(int val,struct Typetable *type,char* varname,int nodetype,struct tnode *l,struct tnode *r,struct tnode *m);

void inorder(struct tnode *t);
void print_node(struct tnode *t);
int sys_call(char *scall,int arg1, int arg2);
int codegen(struct tnode* t);


extern int ins_cnt,wrap_no;
extern int lcl_bind;
extern int line_no,field_flag;



struct Gsymbol *GLookup(char * name);
void GInstall(char *name, struct Typetable *type, int size,struct param *p,struct Classtable *class);
void print_symbol_table();

struct Lsymbol *LLookup(char *name);
void LInstall(char *name, struct Typetable *type);

void alocate_param(struct param *p);
struct param *create_par(char *name,struct Typetable *type);

extern int declflag;
void typecheck(struct tnode *t);
void check_name_equi(struct Typetable *type,char *name,struct param *p);
void free_lcl_tab();
void deletetree(struct tnode *t);
void func_starter(char *name);
void argcheck(struct tnode *t,struct Gsymbol *func);

//////////////////////////////////////
typedef struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
}Typetable;


struct Fieldlist{
 char *name;   //name of the field
 int fieldIndex;   //position of the field
 struct Typetable *type;  //pointer to typetable
 struct Classtable *ctype; //pointer to the class containing the field
 struct Fieldlist *next;  //pointer to next fieldlist entry
};

extern int size;
extern struct Classtable *Cptr;
void TypeTableCreate(); //Function to initialise the type table entries with primitive types (int,str) and special entries_(boolean,null,void).
struct Typetable* TLookup(char *name) ;
struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields);
struct Fieldlist* FLookup(Typetable *type, char *name);
struct Fieldlist* Fcreate(char *name,char *type);
int GetSize(Typetable * type);
int getaddr(tnode *t);

//////////////////////////////////////////////
///////////////////////////////////////////
typedef struct Classtable {
  char *name;                           //name of the class
  struct Fieldlist *Memberfield;        //pointer to Fieldlist
  struct Memberfunclist *Vfuncptr;      //pointer to Memberfunclist
  struct Classtable *Parentptr;         //pointer to the parent's class table
  int Class_index;                      //position of the class in the virtual function table
  int Fieldcount;                       //count of fields
  int Methodcount;                      //count of methods
  struct Classtable *next;              //pointer to next class table entry
}Classtable;

struct Memberfunclist {
    char *name;                    //name of the member function in the class
    struct Typetable *type;        //pointer to typetable
    int isdefined,isinherited;
    struct param *paramlist;        //pointer to the head of the formal parameter list
    int Funcposition;               //position of the function in the class table
    int Flabel;                     //A label for identifying the starting address of the function's code in the memory
    struct Memberfunclist *next;    //pointer to next Memberfunclist entry
};
void printVirtualTable();
struct Classtable* CInstall(char *name,char *parent_class_name) ;
struct Classtable* CLookup(char *name);
void Class_Finstall(struct Classtable *cptr, char *typname, char *name,int idx) ;
void Class_Minstall(struct Classtable *cptr, char *name, struct Typetable *type, struct param *Paramlist,int idx) ;
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* name) ;
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* name) ;


