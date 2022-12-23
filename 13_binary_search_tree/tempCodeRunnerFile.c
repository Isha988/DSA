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
void Inorder(struct TNode* root){
    if(!root) return;

    Inorder(root->lchild);
    printf("%d ", root->data);
    Inorder(root->rchild);
}

//iterative insert
void Insert(struct TNode **ptrToRoot, int key)
{
    struct TNode *new, *p = NULL, *root = *ptrToRoot;

    if(!*ptrToRoot){
       *ptrToRoot = NewNode(key);
       return;
    }

    while(root){
        p = root;
        if(key < root->data) 
            root = root->lchild;
        else if (key > root->data) 
            root = root->rchild;
        else 
            return;    
    }

    new = NewNode(key);
    if(key < p->data)
        p->lchild = new;
    else
        p->rchild = new;

}

// //recursive insert
// struct TNode *RInsert(struct TNode *root)
// {
// }

int main()
{
    struct TNode* root = NULL;
    int i;
    for(i = 60; i<=100;  i= i+10){
        Insert(&root, i);
    }
    for(i = 10; i<=50; i = i + 10){
        Insert(&root, i);
    }

    Inorder(root);

    return 0;
}