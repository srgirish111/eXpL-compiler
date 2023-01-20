

int q = -1;
struct tnode *makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode *makeOperatorNode(char c, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int getreg()
{
    ++q;
    if (q > 20)
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
    FILE *tg = fopen("ex2.xsm", "a");
    fprintf(tg, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", 0, 2056, 0, 0, 0, 0, 0, 0);
    fclose(tg);
}

int codegen(struct tnode *t)
{
    FILE *tg = fopen("ex2.xsm", "a");

    if (t->op == NULL)
    {
        int a;
        a = getreg();
        fprintf(tg, "MOV R%d,%d\n", a, t->val);
        fclose(tg);
        return a;
    }
    int l, r;
    l = codegen(t->left);
    r = codegen(t->right);
    switch (*(t->op))
    {
    case '+':
    {
        fprintf(tg, "ADD R%d,R%d\n", l, r);
        break;
    }

    case '-':
    {
        fprintf(tg, "SUB R%d,R%d\n", l, r);
        break;
    }
    case '*':
    {
        fprintf(tg, "MUL R%d,R%d\n", l, r);
        break;
    }
    case '/':
    {
        fprintf(tg, "DIV R%d,R%d\n", l, r);
        break;
    }
    }
    freereg();
    fclose(tg);
    return l;
}

void write_gen(int outp)
{
    int x = getreg();
    FILE *tg = fopen("ex2.xsm", "a");
    fprintf(tg, "MOV R%d, \"Write\"\n", x);
    fprintf(tg, "PUSH R%d\n", x);
    fprintf(tg, "MOV R%d ,-2\n", x);
    fprintf(tg, "PUSH R%d\n", x);
    fprintf(tg, "MOV R%d,R%d\n", x, outp);
    fprintf(tg, "PUSH R%d\n", x);
    fprintf(tg, "PUSH R%d\n", x);
    fprintf(tg, "PUSH R%d\n", x);
    fprintf(tg, "CALL 0\n");
    int a = getreg();
    fprintf(tg, "POP R%d\n", a);
    fprintf(tg, "POP R%d\n", x);
    fprintf(tg, "POP R%d\n", x);
    fprintf(tg, "POP R%d\n", x);
    fprintf(tg, "POP R%d\n", x);
    freereg();
    freereg();
    fclose(tg);
}

void exit_gen()
{
    FILE *tg = fopen("ex2.xsm", "a");
    int r = getreg();
    fprintf(tg, "MOV R%d,\"Exit\"\n", r);
    fprintf(tg, "PUSH R%d\n", r);
    fprintf(tg, "PUSH R%d\n", r);
    fprintf(tg, "PUSH R%d\n", r);
    fprintf(tg, "PUSH R%d\n", r);
    fprintf(tg, "PUSH R%d\n", r);
    fprintf(tg, "CALL 0\n");
    int i = getreg();
    fprintf(tg, "POP R%d\n", i);
    fprintf(tg, "POP R%d\n", r);
    fprintf(tg, "POP R%d\n", r);
    fprintf(tg, "POP R%d\n", r);
    fprintf(tg, "POP R%d\n", r);
    freereg();
    freereg();
    fclose(tg);
}