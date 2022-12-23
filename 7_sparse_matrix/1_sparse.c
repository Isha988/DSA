#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int r;
    int c;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *E;
};

void Create(struct Sparse *S)
{
    int i;

    printf("Enter Dimensions of Matrix \n");
    scanf("%d %d", &S->m, &S->n);

    printf("Enter no of non zero element in matrix \n");
    scanf("%d", &S->num);

    S->E = (struct Element *)(malloc(S->num * sizeof(struct Element)));

    printf("Enter row column and value of element \n");
    for (i = 0; i < S->num; i++)
    {
        scanf("%d %d %d", &S->E[i].r, &S->E[i].c, &S->E[i].x);
    }
}

void Display(struct Sparse S)
{
    int i, j, e = 0;

    for (i = 1; i <= S.m; i++)
    {
        for (j = 1; j <= S.n; j++)
        {
            if (S.E[e].r == i & S.E[e].c == j)
            {
                printf("%d ", S.E[e].x);
                e++;
            }
            else
                printf("0 ");
        }

        printf("\n");
    }
}

struct Sparse *Add(struct Sparse *S1, struct Sparse *S2)
{
    struct Sparse *Sum;
    int i = 0, j = 0;

    if (S1->m != S2->m || S1->n != S2->n)
        return NULL;

    Sum = (struct Sparse *)(malloc(sizeof(struct Sparse)));
    Sum->m = S1->m;
    Sum->n = S1->n;
    Sum->num = 0;
    Sum->E = (struct Element *)(malloc((S1->num + S2->num) * sizeof(struct Element)));

    while (i < S1->m && j < S2->m)
    {
        if (S1->E[i].r < S2->E[j].r)
            Sum->E[Sum->num++] = S1->E[i++];
        else if (S1->E[i].r > S2->E[j].r)
            Sum->E[Sum->num++] = S2->E[j++];
        else if (S1->E[i].c < S2->E[j].c)
            Sum->E[Sum->num++] = S1->E[i++];
        else if (S1->E[i].c > S2->E[j].c)
            Sum->E[Sum->num++] = S2->E[j++];
        else
        {
            Sum->E[Sum->num] = S2->E[j];
            Sum->E[Sum->num++].x = S1->E[i++].x + S2->E[j++].x;
        }
    }

    for (; i < S1->num; i++)
        Sum->E[Sum->num++] = S1->E[i];

    for (; j < S2->num; j++)
        Sum->E[Sum->num++] = S2->E[j];

    return Sum;
}

int main()
{
    struct Sparse S1, S2, *S3;

    Create(&S1);
    Create(&S2);

    S3 = Add(&S1, &S2);
    printf("Matrix 1\n");
    Display(S1);

    printf("Matrix 2\n");
    Display(S2);

    printf("result\n");
    Display(*S3);

    return 0;
}