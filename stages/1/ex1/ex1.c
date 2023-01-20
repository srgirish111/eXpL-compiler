struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

void prefix(struct tnode *x)
{
    if(x==NULL)
    return;
    if(x->op==NULL)
    printf("%d ",x->val);
    else
    printf("%c ",*(x->op));

    prefix(x->left);
    prefix(x->right);
}

void postfix(struct tnode *x)
{
    if(x==NULL)
    return;

    postfix(x->left);
    postfix(x->right);
    if(x->op==NULL)
    printf("%d ",x->val);
    else
    printf("%c ",*(x->op));
}