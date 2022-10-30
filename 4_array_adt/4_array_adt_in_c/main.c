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

int Rearrange(struct Array* ptr){
    int i=0;
    int j= ptr->length -1;

    while(i < j){
        while(ptr->A[i] < 0) i++;
        while(ptr->A[j] > 0) j--;

        if(i<j)
         Swap(&ptr->A[i], &ptr->A[j]);
    }
}

struct Array Merge(struct Array arr1, struct Array arr2){
    struct Array arr3;

    int i = 0, j=0, k=0 ;

    while(i < arr1.length && j <arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else 
           arr3.A[k++] = arr2.A[j++];    
    }

    for(; i< arr1.length; i++){
        arr3.A[k++] = arr1.A[i];
    }

    for(; j< arr2.length; j++){
        arr3.A[k++] = arr2.A[j];
    }

    arr3.length = arr1.length + arr2.length;
    arr3.size = arr1.size + arr2.size;

    return arr3;

}

//set operations
struct Array Union(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, j;

    for(i=0; i<arr1.length; i++){
        arr3.A[i] = arr1.A[i];
    }

    for(j=0; j<arr2.length; j++){
        if(LinearSearch(arr1, arr2.A[j]) == -1 )
            arr3.A[i++] = arr2.A[j];
    }

    arr3.length = i;
    arr3.size = arr1.size +arr2.size;

    return arr3;
}

//union for sorted set
struct Array Union2(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, j, k;
    i=j=k=0;

    while(i < arr1.length && j <arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            arr3.A[k++] = arr2.A[j++];
        else{
            arr3.A[k++] = arr1.A[i];
            i++; j++;
        }
    }

    for(; i< arr1.length; i++){
        arr3.A[k++] = arr1.A[i];
    }

    for(; j< arr2.length; j++){
        arr3.A[k++] = arr2.A[j];
    }

    arr3.length = k;
    arr3.size = arr1.size + arr2.size;

    return arr3;
}

struct Array Intersection(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, k=0;
    for(i=0; i < arr1.length; i++)
        if(LinearSearch(arr2, arr1.A[i] ) != -1)
            arr3.A[k++] = arr1.A[i];
    
    arr3.length = k;
    arr3.size = 20; //minimum of arr1.size and arr2.size

    return arr3;
}

//intersection for sorted array
struct Array Intersection2(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, j, k;
    i=j=k=0;

    while(i<arr1.length && j < arr2.length){
        if (arr1.A[i] < arr2.A[j])
            i++;
        else if (arr1.A[i] > arr2.A[j])
            j++;
        else{
            arr3.A[k++] = arr1.A[i];
            i++;
            j++;
        }   
    }

    arr3.length = k;
    arr3.size = 20; //minimum of arr1.size and arr2.size
    return arr3;
}

struct Array Difference(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, k=0;
    for(i=0; i < arr1.length; i++)
        if(LinearSearch(arr2, arr1.A[i] ) == -1)
            arr3.A[k++] = arr1.A[i];
    
    arr3.length = k;
    arr3.size = 20;//max of arr1.size and arr2.size

    return arr3;
}

//difference for sorted array
struct Array Difference2(struct Array arr1, struct Array arr2){
    struct Array arr3;
    int i, j, k;
    i=j=k=0;

    while(i<arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j])
            arr3.A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else{
            i++;
            j++;
        }
    }

    for(; i<arr1.length; i++)
        arr3.A[k++] = arr1.A[i];
    
    arr3.length = k;
    arr3.size = 20;//max of arr1.size and arr2.size

    return arr3;

}

int main()
{
    struct Array arr1 = {{3, 8, 16, 20, 25, 27}, 10, 6};
    struct Array arr2 = {{4, 8, 16, 22, 25}, 10, 5};
   
    struct Array arr3 = Difference2(arr1, arr2);
    printf("length : %d \n", arr3.length);
    Display(arr3);

   return 0;
}
