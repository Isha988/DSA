#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int *A;
    int n;
};

void Create(struct Matrix *M, int n)
{
    M->A = (int *)(malloc((3 * M->n - 2) * sizeof(int)));
    M->n = n;
}

void Display(struct Matrix M)
{
    int i, j;
    for (i = 1; i <= M.n; i++)
    {
        for (j = 1; j <= M.n; j++)
        {
            if (abs(i - j) <= 1)
            {
                if (i - j == 1)
                    printf("%d ", M.A[i - 1]);
                else if (i - j == 0)
                    printf("%d ", M.A[M.n - 1 + i - 1]);
                else
                    printf("%d ", M.A[2 * M.n - 1 + i - 1]);
            }
            else
                printf("0 ");
        }

        printf("\n");
    }
}

void Set(struct Matrix *M, int i, int j, int x)
{
    if (abs(i - j) <= 1)
    {
        if (i - j == 1)
            M->A[i - 1] = x;
        else if (i - j == 0)
            M->A[M->n - 1 + i - 1] = x;
        else
            M->A[2 * M->n - 1 + i - 1] = x;
    }
}

int Get(struct Matrix M, int i, int j)
{
    if (abs(i - j) <= 1)
    {
        if (i - j == 1)
            return M.A[i - 1];
        else if (i - j == 0)
            return M.A[M.n - 1 + i - 1];
        else
            return M.A[2 * M.n - 1 + i - 1];
    }
    else
        return 0;
}

int main()
{
    struct Matrix M;
    Create(&M, 3);

    Set(&M, 1, 1, 15);
    Set(&M, 2, 2, 18);
    Set(&M, 3, 3, 10);
    Set(&M, 2, 1, 12);
    Set(&M, 3, 4, 17);
    Set(&M, 2, 3, 19);
    Set(&M, 1, 2, 13);

    printf("%d \n", Get(M, 2, 3));

    Display(M);
    return 0;
}