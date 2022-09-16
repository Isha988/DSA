#include <iostream>

using namespace std;

//function definition and declaration
int add(int a, int b){
    int c;
    c= a+ b;
    return(c);
}

int main()
{
    int x=100, y=900, sum;
    sum = add(x , y);
    cout <<"sum of x and y is : "<<sum<<endl;

    cout<<"Enter two number"<<endl;
    cin>>x>>y;

    sum = add(x , y);//function calling
    cout <<"sum of x and y is : "<<sum<<endl;
    return 0;
}
