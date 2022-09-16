#include <iostream>

using namespace std;

int main()
{
    int a = 20;
    int &r = a; //reference must be initialized with declaration

    int b = 50;
    r = b;
    cout <<a<<endl<<r<< endl;
    return 0;
}
