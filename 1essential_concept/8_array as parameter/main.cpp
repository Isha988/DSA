#include <iostream>

using namespace std;

void fun1(int a[], int length){
    /*
        array can only be passed through address
        int a[] is a pointer to array
        int *a can also be used in place of int a[]
    */

    cout<<"size of a : "<<sizeof(a)<<endl; //return size of pointer not of array

    for(int i=0; i<length; i++){
        //for each loop don't works with pointers, its works with actual array
        cout<<a[i]<<endl;
    }

    a[3] = 500;
}

//function returning an array
int * fun2(int length){
    int *arr;

    arr = new int[length]; //same as : arr = (int*)malloc(sizeof(int)*length);
    for(int i=0; i<length; i++){
        arr[i] = i+1;
    }

    return arr;
}

int main()
{
    //passing array
    int arr[] = {10,20,30,40,50};
    int n= 5;

    fun1(arr, n);

    cout<<"size of arr : "<<sizeof(arr)<<endl;

    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;

    //getting array in return
    int *ptr, len=7;

    ptr = fun2(len);
    for(int i = 0; i<len; i++){
        cout<<ptr[i]<<" ";
    }

    return 0;
}
