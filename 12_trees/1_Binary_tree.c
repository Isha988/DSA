#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

//creating new tree node
struct TNode *NewTNode(int x)
{
    struct TNode *n = (struct TNode *)(malloc(sizeof(struct TNode *)));
    if (n)
    {
        n->data = x;
        n->lChild = n->rChild = NULL;
    }

    return n;
}

//linked representation of binary tree
struct TNode *CreateTree()
{
    struct TNode *root = NULL;
    struct TNode *p, *t;
    int x;
    struct Queue q = NewQueue();

    printf("Enter root value\n");
    scanf("%d", &x);

    root = NewTNode(x);
    Enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = Dequeue(&q);

        printf("Enter left child %c \n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = NewTNode(x);

            if (!t)
                break; //tree is full

            p->lChild = t;
            Enqueue(&q, t);
        }

        printf("Enter right child of %c \n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = NewTNode(x);

            if (!t)
                break;

            p->rChild = t;
            Enqueue(&q, t);
        }
    }

    return root;
}

//recursive traversals

void Preorder(struct TNode *p)
{
    if (!p)
        return;

    printf("%c ", p->data);
    Preorder(p->lChild);
    Preorder(p->rChild);
}

void Inorder(struct TNode *p)
{
    if (!p)
        return;

    Inorder(p->lChild);
    printf("%c ", p->data);
    Inorder(p->rChild);
}

void Postorder(struct TNode *p)
{
    if (!p)
        return;

    Postorder(p->lChild);
    Postorder(p->rChild);
    printf("%c ", p->data);
}

//iterative traversals

void Pre(struct TNode *p)
{

    struct SNode *top = NULL;

    while (p || !isStackEmpty(top))
    {
        if (p)
        {
            printf("%c ", p->data);
            Push(&top, p);
            p = p->lChild;
        }
        else
        {
            p = Pop(&top);
            p = p->rChild;
        }
    }
}

void In(struct TNode *p)
{

    struct SNode *top = NULL;

    while (p || !isStackEmpty(top))
    {
        if (p)
        {
            Push(&top, p);
            p = p->lChild;
        }
        else
        {
            p = Pop(&top);
            printf("%c ", p->data);
            p = p->rChild;
        }
    }
}



// void Post(struct TNode *p)
// {

//     struct SNode *top = NULL;

//     while (p || !isStackEmpty(top))
//     {
//         if (p)
//         {
//             Push(&top, p);
//             p = p->lChild;
//         }
//         else
//         {
//             p = Pop(&top);

//             if(p > 0){
//                 Push(&top, p);
//                 p = p->rChild;
//             }else{
//                 p = p;
//                 printf("%c ", p->data);
//                 p=NULL;
//             }
//         }
//     }
// }

//level order traversal

void Level(struct TNode *p)
{

    struct Queue q = NewQueue();

    if (!p)
        return;

    printf("%c ", p->data);
    Enqueue(&q, p);

    while (!isEmpty(q))
    {
        p = Dequeue(&q);

        if (p->lChild)
        {
            printf("%c ", p->lChild->data);
            Enqueue(&q, p->lChild);
        }
        if (p->rChild)
        {
            printf("%c ", p->rChild->data);
            Enqueue(&q, p->rChild);
        }
    }
}

//height and count

int NodeCount(struct TNode *p)
{
    int leftCount, rightCount;
    leftCount = rightCount = 0;

    if (!p)
        return 0;

    leftCount = NodeCount(p->lChild);
    rightCount = NodeCount(p->rChild);

    return leftCount + rightCount + 1;
}

int Height(struct TNode *p)
{
    int leftHeight, rightHeight, height;
    leftHeight = rightHeight = 0;

    if (!p)
        return -1;

    leftHeight = Height(p->lChild);
    rightHeight = Height(p->rChild);

    height = (leftHeight >= rightHeight) ? leftHeight + 1 : rightHeight + 1;

    return height;
}

//main function
int main()
{
    struct TNode *root = CreateTree();

    printf("\n level: \n");
    Level(root);

    printf("Height: %d \n", Height(root));

    printf("\n pre: \n");
    Preorder(root);
    printf("\n pre iterative: \n");
    Pre(root);

    printf("\n in: \n");
    Inorder(root);
    printf("\n in iterative: \n");
    In(root);

    printf("\n post: \n");
    Postorder(root);
    // printf("\n post iterative: \n");
    // Post(root);
    return 0;
}