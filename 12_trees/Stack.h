#include <stdio.h>
#include <stdlib.h>
#ifndef Stack_h
#define Stack_h

//tree node structure
// struct TNode
// {
//     struct TNode *lChild;
//     int data;
//     struct TNode *rChild;
// };

//stack Node structure
struct SNode
{
    struct TNode *data;
    struct SNode *next;
};

struct SNode *NewSNode(struct TNode *x)
{
    struct SNode *n = (struct SNode *)(malloc(sizeof(struct SNode)));

    if (n)
    {
        n->data = x;
        n->next = NULL;
    }

    return n;
} 

//stack opearation

int isStackEmpty(struct SNode *top)
{
    if (top)
        return 0;

    return 1;
}

void Push(struct SNode **p, struct TNode *x) // p = pointer to stack top
{
    struct SNode *n = NewSNode(x);

    if (!n)
        return;

    n->next = *p;
    *p = n;
}

struct TNode *Pop(struct SNode **p) // p = pointer to stack top
{
    struct TNode *x = NULL;

    if(isStackEmpty(*p)) return x;

    x = (*p)->data;
    *p = (*p)->next;

    return x;
}

#endif //Stack_h