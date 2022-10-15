#include <iostream>

using namespace std;

int power1(int n, int pow){
    if(pow == 0) return 1;

    if(pow%2 == 0) return power1(n*n, pow/2);

    return n * power1(n*n, (pow-1)/2);
}

int power2(int n, int pow){
     if(pow == 0) return 1;

     return n * power2(n, pow-1);
}

int main()
{
  int n, pow;
  cout<<"enter number and power"<<endl;
  cin>>n>>pow;

  cout<< n<<" raise to "<<pow<<" = "<<power1(n, pow)<<endl;
  cout<< n<<" raise to "<<pow<<" = "<<power2(n, pow)<<endl;

  return 0;
}
