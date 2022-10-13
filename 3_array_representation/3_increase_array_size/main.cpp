#include <iostream>

using namespace std;

int main()
{
    int *p, *q;
    int i;

    p = (int *)(malloc(5*sizeof(int)));
    for(i=0; i<5; i++){
        p[i] = i+10;
    }

    q = new int[10];
    for (i=0; i<5; i++){
        q[i] = p[i];
    }

    free(p);
    p=q;
    q=NULL;
    cout<<" memory size of array before allocation : "<<_msize(p)<<endl;

    p = (int *)(realloc(p, 20 * sizeof(int)));

    cout<<"length after reallocation: "<<_msize(p)/sizeof *p<<endl;

    return 0;
}
