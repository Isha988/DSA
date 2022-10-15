#include <iostream>

using namespace std;

int factorial(int n){
    int fact;

    if(n <= 0) return 1;

    fact = n * factorial(n-1);
    return fact;
}

int main()
{
    int n =0, fact=1;

    cout<<"enter number"<<endl;
    cin>>n;

    fact = factorial(n);
    cout<<"factorial = "<<fact<<endl;

    return 0;
}
