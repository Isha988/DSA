#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term
{
    int coff;
    int exp;
};

struct Polynomial
{
    int n;
    struct Term *t;
};

void Create(struct Polynomial *p)
{
    int i;

    printf("Enter number of non-zero elements in polynomial\n");
    scanf("%d", &p->n);

    p->t = (struct Term *)(malloc(p->n * sizeof(struct Term)));

    for (i = 0; i < p->n; i++)
    {
        printf("Enter coff and exponenet of term  %d \n", i + 1);
        scanf("%d %d", &p->t[i].coff, &p->t[i].exp);
    }
}

void Display(struct Polynomial p){
    int i;

    for(i=0; i < p.n; i++){
        printf("%dx^%d ", p.t[i].coff, p.t[i].exp);
    }
    printf("\n");
}

int Evaluate(struct Polynomial p, int x)
{
    double res = 0;
    int i;

    for (i = 0; i < p.n; i++)
    {
        res += p.t[i].coff * pow((double)x, (double)p.t[i].exp);
    }
    return res;
}

struct Polynomial Add(struct Polynomial *a, struct Polynomial *b)
{
    int i, j, k;
    i = j = k = 0;
    struct Polynomial c;
    c.t = (struct Term *)(malloc((a->n + b->n) * sizeof(struct Term)));

    while (i < a->n && j < b->n)
    {
        if(a->t[i].exp > b->t[j].exp)
            c.t[k++] = a->t[i++];
        else if(a->t[i].exp < b->t[j].exp)
            c.t[k++] = b->t[j++];
        else{
            c.t[k].exp = a->t[i].exp;
            c.t[k++].coff = a->t[i++].coff + b->t[j++].coff;
        }
    }

    for(; i < a->n; i++){
        c.t[k++] = a->t[i];
    }

    for(; j < b->n; j++){
        c.t[k++] = b->t[j];
    }

    c.n = k;
    return c;

}

int main()
{
    struct Polynomial p1,p2,p3;
    Create(&p1);
     Create(&p2);
    
    p3 = Add(&p1, &p2);

    Display(p1);
    Display(p2);
    Display(p3);
    return 0;
}