#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Create(struct Matrix *M, int n)
{
    M->A = (int *)(malloc((2 * M->n - 1) * sizeof(int)));
    M->n = n;
}

void Display(struct Matrix M)
{
    int i, j;
    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            if (i <= j)
                printf("%d ", M.A[j - i]);
            else
                printf("%d ", M.A[M.n - 1 + i - j]);
        }

        printf("\n");
    }
}

void Set(struct Matrix *M, int i, int j, int x)
{
    if (i <= j)
        M->A[j - i] = x;
    else
        M->A[M->n - 1 + i - j] = x;
}

int Get(struct Matrix M, int i, int j)
{
    if (i <= j)
        return M.A[j - i];
    else
        return M.A[M.n - 1 + i - j];
}

int main()
{
    struct Matrix M;
    Create(&M, 3);

    Set(&M, 1, 1, 15);
    Set(&M, 3, 1, 10);
    Set(&M, 2, 1, 12);
    Set(&M, 1, 3, 19);
    Set(&M, 1, 2, 13);

    printf("%d \n", Get(M, 2, 3));

    Display(M);
    return 0;
}