#include <iostream>

using namespace std;

int main()
{
    /* method 1 of creating 2d array
    every thing is present in stack */
    int A[3][4] = { {1,2,3,4}, {1,3,5,7}, {2,4,6,8} };

    /* method 2 : array of pointer in stack and arrays of int in heap*/
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    /* method 3 : everything in heap expect pointer to array of pointers*/
    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    /* accessing elements of matrix*/
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
