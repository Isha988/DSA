#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Create(int A[], int n)
{
    struct Node *first, *last, *p;
    int i;

    if (n > 0)
    {
        p = (struct Node *)(malloc(sizeof(struct Node)));
        p->data = A[0];
        p->next = NULL;
        first = p;
        last = p;
    }

    for (i = 1; i < n; i++)
    {
        p = (struct Node *)(malloc(sizeof(struct Node)));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }

    return first;
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

void RDisplay(struct Node *p)
{
    if (p)
    {
        printf("%d \n", p->data);
        RDisplay(p->next);
    }
}

int Count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int RCount(struct Node *p)
{
    if (p == NULL)
        return 0;
    return 1 + RCount(p->next);
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//recursive sum
int RSum(struct Node *p)
{
    if (!p)
        return 0;

    return p->data + RSum(p->next);
}

//maximum 
int Max(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (max < p->data)
            max = p->data;

        p = p->next;
    }
    return max;
}

//resursive max
int RMax(struct Node *p)
{
    int max = INT_MIN;
    if (!p)
        return max;

    max = RMax(p->next);
    return p->data > max ? p->data : max;
}

//linear search 
struct Node *Search(struct Node *p, int x)
{
    while (p)
    {
        if (x == p->data)
            break;
        p = p->next;
    }
    return p;
}

//recursive search
struct Node *RSearch(struct Node *p, int x)
{
    if (!p)
        return NULL;

    if (x == p->data)
        return p;

    return RSearch(p, x);
}

//improved search
struct Node *ISearch(struct Node **head_ref, int x)
{
    struct Node *p = *head_ref, *q = NULL;

    if (p->data != x)
    {
        while (p)
        {
            if (x == p->data)
            {
                q->next = p->next;
                p->next = *head_ref;
                *head_ref = p;
                break;
            }
            q = p;
            p = p->next;
        }
    }

    return p;
}

int main()
{
    struct Node *head = NULL;
    int A[] = {95, 7, 62, 2, 75};
    head = Create(A, 5);
    ISearch(&head, 75);
    printf("%d \n", ISearch(&head, 62)->data);
    Display(head);
    return 0;
}