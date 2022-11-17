#include<stdio.h>

struct Matrix
{
    int A[10];
    int n;
};

void Display(struct Matrix M){
    int i, j;
     
    for(i=0; i< M.n; i++){
        for(j=0; j< M.n; j++){
            if(i==j)
                printf("%d ", M.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void Set(struct Matrix* M, int i, int j, int x){
    // i is row and j is column 
    if(i == j)
        M -> A[i - 1] = x;
} 

int Get(struct Matrix M, int i, int j){
    // i is row and j is column 
    if(i == j)
        return M.A[i -1];
    else
        return 0;
} 

int main(){
    struct Matrix M ;
    M.n = 4;

    Set(&M, 1,1,5);
    Set(&M, 2,2,8);
    Set(&M, 3,3,10);
    Set(&M, 4,4,2);

    printf("%d \n", Get(M, 3, 3));

    Display(M);

    return 0;
}