#include <iostream>

using namespace std;

class Array {
    int A[20];
public :
    int size;
    int length;

public:
    Array(int s, int a[]){
        A = a;
        size = s;
        length = sizeof(a)/sizeof(int);
    }
};


int main()
{
    Array A = {5,{2, 3, 5}};
    return 0;
}
