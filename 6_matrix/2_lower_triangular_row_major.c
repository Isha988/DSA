#include <stdio.h>

struct Matrix {
    int A[50];
    int n;
};

void Display(struct Matrix M){
    int i, j;

    for(i = 1; i <= M.n; i++){
        for(j=1; j <= M.n; j++){
            if(i>=j)
                printf("%d ", M.A[i*(i-1)/2 + (j-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Set(struct Matrix* M, int i, int j, int x ){
    if(i >=j)
        M->A[i*(i-1)/2 + (j-1)] = x;
}

int Get(struct Matrix M, int i, int j ){
    if(i >=j)
        return M.A[i*(i-1)/2 + (j-1)];
    else 
        return 0;
}

int main(){
    struct Matrix M;
    M.n =3;

    Set(&M, 1,1,5);
    Set(&M, 2,2,8);
    Set(&M, 3,3,10);
    Set(&M, 2,1,2);
    Set(&M, 3,1,7);
    Set(&M, 3,2,9);
    Set(&M, 1,5,2);

    printf("%d \n", Get(M, 3, 3));

    Display(M);
    
    return 0;
}