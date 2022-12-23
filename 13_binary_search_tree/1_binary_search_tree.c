#include <stdio.h>
#include <stdlib.h>

struct TNode
{
    int data;
    struct TNode *lchild;
    struct TNode *rchild;
};

struct TNode *NewNode(int data)
{
    struct TNode *new = (struct TNode *)(malloc(sizeof(struct TNode)));
    new->data = data;
    new->lchild = new->rchild = NULL;
}

//recursive inorder
void Inorder(struct TNode *root)
{
    if (!root)
        return;

    Inorder(root->lchild);
    printf("%d ", root->data);
    Inorder(root->rchild);
}

//iterative insert
void Insert(struct TNode **ptrToRoot, int key)
{
    struct TNode *root = *ptrToRoot, *p = NULL, *new;

    if (!root)
    {
        *ptrToRoot = NewNode(key);
        return;
    }

    while (root)
    {
        p = root;
        if (key < root->data)
            root = root->lchild;
        else if (key > root->data)
            root = root->rchild;
        else
            return;
    }

    new = NewNode(key);
    if (key < p->data)
        p->lchild = new;
    else
        p->rchild = new;
}

//recursive insert
void RInsert(struct TNode **ptrToRoot, int key)
{
    struct TNode *root = *ptrToRoot;
    if (!root)
        *ptrToRoot = NewNode(key);

    else if (key < root->data)
        RInsert(&root->lchild, key);

    else if (key > root->data)
        RInsert(&root->rchild, key);
}

// iterative search
struct TNode *Search(struct TNode *root, int key)
{
    while (root)
    {
        if (key < root->data)
            root = root->lchild;
        else if (key > root->data)
            root = root->rchild;
        else
            return root;
    }

    return NULL;
}

struct TNode *RSearch(struct TNode *root, int key)
{
    if (!root)
        return NULL;

    else if (key < root->data)
        RSearch(root->lchild, key);

    else if (key > root->data)
        RSearch(root->rchild, key);

    else
        return root;
}

struct TNode *InPredecessor(struct TNode *p)
{

    p = p->lchild;

    while (p && p->rchild)
        p = p->rchild;

    return p;
}

struct TNode *InSuccessor(struct TNode *p)
{

    p = p->rchild;

    while (p && p->lchild)
        p = p->lchild;

    return p;
}

int IsLeaf(struct TNode *p)
{
    if (!p->lchild && !p->rchild)
        return 1;

    return 0;
}

void Swap(struct TNode *n1, struct TNode *n2)
{
    int temp;
    temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

//recursive delete

int RDelete(struct TNode *root, int key)
{

    struct TNode *dltNode, *replace;
    dltNode = Search(root, key);

    int x = -1;

    if (!dltNode)
        return -1;

    if (IsLeaf(dltNode))
    {
        x = dltNode->data;
        free(dltNode);
        return x;
    }

    replace = InPredecessor(dltNode);
    if (!replace)
        replace = InSuccessor(dltNode);

    Swap(dltNode, replace);

    RDelete(replace, key);
}

int main()
{
    struct TNode *root = NULL;
    struct TNode *search;
    int i;
    for (i = 60; i <= 100; i = i + 10)
    {
        RInsert(&root, i);
    }
    for (i = 10; i <= 50; i = i + 10)
    {
        RInsert(&root, i);
    }

    search = RSearch(root, 0);
    printf("\n %d \n", RDelete(root, 60));
    Inorder(root);

    return 0;
}