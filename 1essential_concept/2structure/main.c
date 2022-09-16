#include <stdio.h>
#include <stdlib.h>

//definition of structure
// definition does not consume memory
struct Rectangle {
    int length;
    int breadth;
}r,r2; //declaration

struct Rectangle2{
    int length;
    int breadth;
    char x;
};
int main()
{
   struct Rectangle r3; //declaration
   struct Rectangle r1 = {10, 20} ; //declaration with initialization

   printf("length: %d, breadth: %d \n", r1.length, r1.breadth);//accessing elements of structure
   printf("size of struct rectangle is: %lu\n", sizeof(r1));
   printf("size of struct rectangle2 is: %lu", sizeof(struct Rectangle2)); //gives 12 instead of 9 due to padding in structure

   return(0);
}
