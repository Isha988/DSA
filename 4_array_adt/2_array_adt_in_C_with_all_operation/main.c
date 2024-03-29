#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[20];
    int size;
    int length;
};

void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void Display(struct Array arr){
    int i;

    printf("Elements of array are : \n");
    for(i=0; i<arr.length; i++)
        printf("%d\n", arr.A[i]);
}

void Append(struct Array * ptr, int value){

    if(ptr->length < ptr->size) {
        ptr->A[ptr->length++] = value;
    }
}

void Insert(struct Array * ptr, int index, int data){
    int i;

    if(index >= 0 && index <= ptr->length && index < ptr->size) {
        for(i= ptr->length; i > index; i-- )
            ptr->A[i] = ptr->A[i-1];

        ptr->A[index] = data;
        ptr->length++;
    }
}

int Delete(struct Array * ptr, int index ){
    int i , x;
    x = ptr->A[index];
    if(index>=0 && index < ptr->length){
        for(i=index; i<ptr->length - 1; i++)
            ptr->A[i] = ptr->A[i+1];
        ptr->length--;
        return x;
    }
    return -1;
}

int LinearSearch(struct Array arr, int value){
    int i;
    for(i=0; i<arr.length; i++)
        if(arr.A[i] == value)
            return i;

    return -1;
}

// improved linear search using transposition
int LinearSearch2(struct Array* ptr, int value){
    int i;
    for(i=0; i < ptr->length; i++)
        if(value == ptr->A[i]){
            Swap(&ptr->A[i], &ptr->A[i-1]);
            return i-1;
        }

    return -1;
}


// improved linear search using move to head
int LinearSearch3(struct Array* ptr, int value){
    int i;
    for(i=0; i < ptr->length; i++)
        if(value == ptr->A[i]){
            Swap(&ptr->A[i], &ptr->A[0]);
            return 0;
        }

    return -1;
}

int BinarySearch(struct Array arr, int value){
    int low = 0, high = arr.length-1, mid;

    while(low <= high){
        mid = (low + high)/2;
        if(value < arr.A[mid])
            high = mid-1;
        else if(value > arr.A[mid])
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

//recursive version of binary search
int BinarySearch2(int A[], int value, int low, int high){
    int mid = (low+high)/2;

    if(low > high) return -1;

    if(value < A[mid])
        return BinarySearch2(A, value, low, mid-1);
    else if(value > A[mid])
        return BinarySearch2(A, value, mid+1, high);
    else
        return mid;
}

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length )
        return arr.A[index];
}
void Set(struct Array* ptr, int index, int value){
    if(index >= 0 && index < ptr->length )
        ptr->A[index] = value;
}
int Max(struct Array arr){
    int max = arr.A[0],i;
    for(i=1; i < arr.length; i++)
        if(max < arr.A[i])
            max = arr.A[i];

    return max;
}

int Min(struct Array arr){
    int min = arr.A[0],i;
    for(i=1; i < arr.length; i++)
        if(min > arr.A[i])
            min = arr.A[i];

    return min;
}

int Sum(struct Array arr){
    int sum = 0, i;
    for(i=0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

float Avg(struct Array arr){
    float sum = Sum(arr);
    return sum/arr.length;
}

void Reverse(struct Array* ptr){
    int i;
    for(i=0; i <= ptr->length/2; i++)
        Swap(&ptr->A[i], &ptr->A[ptr->length -1 -i]);
}

void Reverse2(struct Array* ptr){
    int i, j;
    for(i=0, j=ptr->length; i < j; i++, j--)
        Swap(&ptr->A[i], &ptr->A[j]);
}

void Reverse3(struct Array* ptr){
    int B[ptr->length];
    int i,j;
    for(i=0, j=ptr->length-1; i<ptr->length; i++,j-- ){
        B[j] = ptr->A[i];
    }
    for(i=0; i<ptr->length; i++){
        ptr->A[i] = B[i];
    }
}

//this is of order n
void InsertSort(struct Array* ptr, int value){
    int i = ptr->length-1;
    if(ptr->length == ptr->size)
        return;

    while(i>=0 && ptr->A[i] > value){
        ptr->A[i+1] = ptr->A[i];
        i--;
    }

    ptr->A[i+1]= value;
    ptr->length++;
}
//this of order n^2
void InsertSort2(struct Array* ptr, int value){
    int i;
    for(i=0; i<ptr->length; i++)
        if(value < ptr->A[i]){
            Insert(ptr, i, value);
            break;
        }
}
int isSorted(struct Array arr){
    int i;
    for(i=0; i<arr.length-1; i++)
        if(arr.A[i] > arr.A[i+1])
            return 0;

    return 1;
}

int Rearrange(){

}
int main()
{
    struct Array arr = {{2, 5, 7, 9, 23, 33, 38, 42, 45, 56}, 20, 10};
    InsertSort(&arr, 24);

    Display(arr);

   return 0;
}
