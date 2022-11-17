#include <iostream>
using namespace std;

class Diagonal
{
    private:
        int* A;
        int n;
    public:
        Diagonal(int n);
        void Display();
        void Set(int i, int j, int x);
        int Get(int i, int j);
        ~Diagonal();
};

Diagonal::Diagonal(int n)
{
    this->n = n;
    A = new int(n);
}

void Diagonal::Display(){
    int i,j;

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }

}

void Diagonal::Set(int i, int j, int x){
    if(i==j)
        A[i-1] = x;
}

int Diagonal::Get(int i, int j){
    if(i==j)
        return A[i-1];
    else
        return 0;
}

Diagonal::~Diagonal()
{
    delete[] A;
    A = nullptr;
}



int main(){

    Diagonal D(4);

    D.Set(1,1,5);
    D.Set(2,2,7);
    D.Set(3,3,8);
    D.Set(4,4,9);

    cout<<D.Get(4,4)<<endl;
    D.Display();


    return 0;
}
