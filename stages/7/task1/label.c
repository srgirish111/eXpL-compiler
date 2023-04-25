typedef struct lbl
{
	  char *name;
		int address;
		struct lbl *next;
}lbl;
struct lbl *head=NULL,*tail=NULL;
void insertlabel(char *name,int ins_cnt)
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
