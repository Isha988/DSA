#include <iostream>

using namespace std;

//call by value
void swap1(int a, int b){
    int temp = a;
    a=b;
    b=temp;
    cout<< "after swap from swap1 : a = "<<a<<" b = "<<b<<endl;
}

//call by address
void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout<< "after swap from swap2 : a = "<<*a<<" b = "<<*b<<endl;
}

//call by address (only supported in c++)
void swap3(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    cout<< "after swap from swap3 : a = "<<a<<" b = "<<b<<endl;
}

int main()
{
    int x = 10, y=20;
    swap1(x,y);
    cout<< "after calling swap1 : x = "<<x<<" y = "<<y<<endl;

    swap2(&x,&y);
    cout<< "after calling swap2 : x = "<<x<<" y = "<<y<<endl;

    swap3(x,y);
    cout<< "after calling swap3 : x = "<<x<<" y = "<<y<<endl;

    return 0;
}
