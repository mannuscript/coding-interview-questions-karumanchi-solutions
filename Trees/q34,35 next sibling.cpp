#include<iostream>
#include"Trees.h"
#include<queue>

struct binaryTreeNode2{
    struct binaryTreeNode2* left;
    struct binaryTreeNode2* right;
    struct binaryTreeNode2* nextSibling;
    int data;
};
struct binaryTreeNode2* getBinaryTreeNode2(int data) 
{
    struct binaryTreeNode2* newNode = (struct binaryTreeNode2*) malloc(sizeof(struct binaryTreeNode2));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
struct binaryTreeNode2* getATree() {
    struct binaryTreeNode2 *root1 = getBinaryTreeNode2(1);
    root1->left = getBinaryTreeNode2(2);
    root1->left->right = getBinaryTreeNode2(5);
    root1->left->right->left = getBinaryTreeNode2(50);
    root1->left->left = getBinaryTreeNode2(4);
    root1->left->left->left = getBinaryTreeNode2(8);

    root1->right = getBinaryTreeNode2(3);
    root1->right->left = getBinaryTreeNode2(300);
    root1->right->right = getBinaryTreeNode2(7);
    root1->right->right->right = getBinaryTreeNode2(15);
    return root1;
}

void assignNextSibling(struct binaryTreeNode2* root)
{
    if(!root)
        return;
    
    queue<binaryTreeNode2*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(!root) {
            if(q.empty())
                return;
            q.push(NULL);
        } else {
            root->nextSibling = q.front();
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
    return;
}

void printNextSiblings(struct binaryTreeNode2* root) 
{

     if(root) {
        printNextSiblings(root->left);
        if(root->nextSibling)
            cout<<"Next sibling of "<<root->data<<" is: "<<root->nextSibling->data<<endl;
        else
            cout<<"Next sibling of "<<root->data<<" is: NULL"<<endl;
        printNextSiblings(root->right);
    }
   
}

void assignNextSiblingRecursion(struct binaryTreeNode2* root)
{
    if(!root)
        return;
    if(root->left)
        root->left->nextSibling = root->right;
    if(root->right) {
        if(root->nextSibling)
            root->right->nextSibling = root->nextSibling->left;
        else 
            root->right->nextSibling = NULL;
    }
    assignNextSiblingRecursion(root->left);
    assignNextSiblingRecursion(root->right);
}

int main(void) 
{
    struct binaryTreeNode2* tree = getATree();
    assignNextSibling(tree);
    printNextSiblings(tree);
    return 0;
}