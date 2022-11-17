#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Create(struct Matrix *M, int n)
{
    M->A = (int *)(malloc(n * (n + 1) / 2 * sizeof(int)));
    M->n = n;
}

void Display(struct Matrix M)
{
    int i, j;
    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            if (i >= j)
                printf("%d ", M.A[i * (i - 1) / 2 + (j - 1)]);
            else
                printf("%d ", M.A[j * (j - 1) / 2 + (i - 1)]);
        }
        printf("\n");
    }
}

void Set(struct Matrix *M, int i, int j, int x)
{
    if (i >= j)
        M->A[i * (i - 1) / 2 + (j - 1)] = x;
    else
        M->A[j * (j - 1) / 2 + (i - 1)] = x;
}

int Get(struct Matrix M, int i, int j)
{
    if (i >= j)
        M.A[i * (i - 1) / 2 + (j - 1)];
    else
        return M.A[j * (j - 1) / 2 + (i - 1)];
}

int main()
{
    struct Matrix M;
    Create(&M, 3);

    Set(&M, 1,1,15);
    Set(&M, 2,2,18);
    Set(&M, 3,3,10);
    Set(&M, 2,1,12);
    Set(&M, 3,1,17);
    Set(&M, 3,2,19);

    printf("%d \n", Get(M, 2, 3));

    Display(M);
    return 0;
}