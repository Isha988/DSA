#include <iostream>

using namespace std;

int main()
{
    //different methods of array declaration
    int A[5];
    int B[5] = {2,4,6,8,10};
    int C[5] = {7,8,9};
    int D[5] = {0};
    int E[] = {30,15,2,7,9,50};

    //showing contiguous memory  of array
   for (int i=0; i<5; i++){
    cout<<&A[i]<<endl;
   }

    return 0;
}
