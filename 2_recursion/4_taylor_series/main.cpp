#include <iostream>

using namespace std;

float taylor(int x, int n){
    static float p=1, f=1;
    float sum = 0;

    if(n == 0) return 1;

    sum = taylor(x, n-1);
    p = p*x;
    f = f*n;

    return (sum + p/f);

}

int main()
{
   int x  = 0, n = 0;
   float sum = 0;

   cout<<"Enter number and highest order of series"<<endl;
   cin>>x>>n;

   sum = taylor(x,n);

   cout<<"sum of series is : "<<sum<<endl;

   return 0;

}
