#include <iostream>

using namespace std;

int add (int n){
    int sum;
if (n <=0)
    return 0;

sum = n + add(n-1);

return sum;
}


int main()
{
int n =0, sum = 0;
cout<<"Enter nth natural number"<<endl;
cin>>n;
sum = add(n);

cout<<"sum = "<<sum<<endl;

return 0;
}
