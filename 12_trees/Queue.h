#include <stdio.h>
#include <stdlib.h>
#ifndef Queue_h
#define Queue_h
//tree node structure
struct TNode
{
    struct TNode *lChild;
    int data;
    struct TNode *rChild;
};

//queue node structure
struct QNode
{
    struct TNode *data;
    struct QNode *next;
};

struct QNode *NewQNode(struct TNode *x)
{
    struct QNode *n = (struct QNode *)(malloc(sizeof(struct QNode)));

    if(n){
        n->data = x;
         n->next = NULL;
    } 

    return n;
}

// queue structure
struct Queue
{
    struct QNode *front;
    struct QNode *rare;
};

//queue operation
struct Queue NewQueue()
{
    struct Queue q;
    q.front = q.rare = NULL;

    return q;
}

void Display(struct Queue q)
{
    struct QNode *p = q.front;

    while (p)
    {
        printf("%d", p->data->data);
        p = p->next;
    }
}

int isEmpty(struct Queue q)
{
    if (q.front)
        return 0;
    return 1;
}

void Enqueue(struct Queue *q, struct TNode *x)
{
    struct QNode *n = NewQNode(x);
    if(!n) return; //queue is full

    if (isEmpty(*q))
    {
        q->rare = n;
        q->front = n;
    }
    else
    {
        q->rare->next = n;
        q->rare = n;
    }
}

struct TNode *Dequeue(struct Queue *q)
{
    struct QNode *p;
    struct TNode *x = NULL;

    if (isEmpty(*q)) return x; //queue is empty

    p = q->front;
    x = q->front->data;
    q->front = q->front->next;

    free(p);
    return x;
}

#endif //Queue_h