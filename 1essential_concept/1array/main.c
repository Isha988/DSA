#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr1[5] = {2, 8, 4, 5, 3}; // declaration with initialisation
   int arr2[5]; // declaration
   arr2[1] = 7; //initialisation
   arr2[2] = 6;
   arr2[3] = 5;

   int n = 8;
   int arr3[n]; //variable size array can only be created not initialised
   arr3[0] = 100;

   printf("size of arr1 is : %d \n", sizeof(arr1));  // size of array = no of ele * size of element
   printf("size of integer is : %d \n", sizeof(arr1[0])); //size of interger

   printf("elements of arr1\n");
   for(int i=0; i<5; i++){
    printf("%d\n", arr1[i]);
   }

   printf("elements of arr2\n");
   for(int i=0; i<5; i++){
    printf("%d\n", arr2[i]);
   }

   printf("elements of arr3\n");
   for(int i=0; i<n; i++){
    printf("%d\n", arr3[i]);
   }

   printf("add of arr2 : %d\n", &arr2);
   printf("add of arr2 : %d\n", &arr2[0]);
   arr2[0] = 90;
   printf("add of arr2 : %d\n", &arr2[1]);

   return(0);
}
