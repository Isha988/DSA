#include <iostream>

using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r={10,20};
    cout <<" length: " << r.length<< endl<<" breadth: " << r.breadth<<endl;

    struct Rectangle *p = &r;
    cout <<" length: " << (*p).length<< endl<<" breadth: " << p->breadth<<endl;

    //*p.length give error because "." operator have high precedence than "*"

    // creating structure variable in heap

    struct Rectangle *p1, *p2;

    p1 = (struct Rectangle *)malloc(sizeof(struct Rectangle)); //in c
    p1 -> length = 100;
    p1 -> breadth = 200;
    cout <<" length: " << p1->length<< endl<<" breadth: " << p1->breadth<<endl;

    p2 = new Rectangle; // in c++
    p2 -> length = 500;
    p2 -> breadth = 600;
    cout <<" length: " << p2->length<< endl<<" breadth: " << p2->breadth<<endl;

    return 0;
}
