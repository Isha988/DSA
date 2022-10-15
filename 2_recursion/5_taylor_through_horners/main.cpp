#include <iostream>

using namespace std;

float taylor(int x, int n){
    static int denominator = 0;
    float product = 0;

    if(n == 0) return 1;

    denominator++;
    product = (float)x/denominator * taylor(x, n-1);

    return 1 + product;
}


float taylor1(int x, int n){
    static float sum =1;

    if(n == 0) return sum;

    sum = 1 + x*sum/n;

    return taylor1(x, n-1);
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
