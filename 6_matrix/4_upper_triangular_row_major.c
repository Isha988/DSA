#include <stdio.h>

struct Matrix {
    int A[50];
    int n;
};

void Display(struct Matrix M){
    int i, j;

    for(i = 1; i <= M.n; i++){
        for(j=1; j <= M.n; j++){
            if(i<=j)
                printf("%d ", M.A[M.n*(i-1) - (i-2)*(i-1)/2 + (j-i)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Set(struct Matrix* M, int i, int j, int x ){
    if(i <=j)
        M->A[M->n*(i-1) - (i-2)*(i-1)/2 + (j-i)] = x;
}

int Get(struct Matrix M, int i, int j ){
    if(i <= j)
        return M.A[M.n*(i-1) - (i-2)*(i-1)/2 + (j-i)];
    else 
        return 0;
}

int main(){
    struct Matrix M;
    M.n =3;

    Set(&M, 1,1,5);
    Set(&M, 2,2,8);
    Set(&M, 3,3,10);
    Set(&M, 1,2,2);
    Set(&M, 1,3,7);
    Set(&M, 2,3,9);

    printf("%d \n", Get(M, 2, 3));

    Display(M);
    
    return 0;
}