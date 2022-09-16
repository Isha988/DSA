#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 15;
    int *p1; //declaration
    p1 = &a; //initialization

    *p1 = 20; //changes value of a from 15 to 20

    printf("value of a : %d %d\n", *p1, a);
    printf("address of a : %d %d\n", p1, &a);

    //pointer to an array
    int A[5] = {3, 6, 9, 5, 7};
    int *p2 = A;

    printf("elements of A\n");
    for(int i=0; i<5; i++)
        printf("%d %d \n", p2[i], A[i]);

    //array inside heap
    int *p3;
    p3 = (int *)(malloc(3*sizeof(int))); // p = new int[5] in c++
    p3[0] = 5;
    p3[1] = 10;
    p3[2] = 15;

    printf("elements of p3\n");
    for(int i=0; i<3; i++)
        printf("%d\n", p3[i]);

    free(p3); //for c++ delete [] p3

    //size of pointers
    int *p4;
    char *p5;
    float *p6;
    double *p7;

    printf("sizes of pointers are: %d %d %d %d %d", sizeof(p3), sizeof(p4), sizeof(p5), sizeof(p6), sizeof(p7)); // gives 8 for all


    return 0;
}
