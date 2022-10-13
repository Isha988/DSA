#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int A[5]; //static array
    int *p1, *p2;

    p1 = (int *)(malloc(5*sizeof(int))); //c language dynamic array and allocation in heap
    p2 = new int[5]; //c++ language dynamic array

    A[0] = 100;
    p1[0] = 200; p1[1] = 300;  p1[2] = 400;  p1[3] = 500;  p1[4] = 600;
    p2[0] = 300;

    printf("elements of p1 \n");
    for(int i = 0; i <5; i++){
        cout<<p1[i]<<endl;
    }

    cout<<"printing 1st ele of each array"<<endl;
    cout<<A[0]<<endl<<p1[0]<<endl<<p2[0]<<endl;

    free(p1); //c language code for deallocation from heap
    delete[] p2; //c++ language code

    cout<<"printing 1st ele of each array after freeing heap memory"<<endl;
    cout<<A[0]<<endl<<p1[0]<<endl<<p2[0]<<endl;

    return 0;
}
