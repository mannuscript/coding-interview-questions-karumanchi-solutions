#include<iostream>
#include"Trees.h"
#include<queue>

int getNumberOfFullNodes(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    int onLeft = getNumberOfFullNodes(root->left);
    int onRight = getNumberOfFullNodes(root->right);

    if(root->left && root->right)
        return (onLeft + onRight + 1);
    else 
        return (onLeft + onRight);
}

int getNumberOfFullNodesWithoutRecurrsion(struct binaryTreeNode* root)
{

    if(!root)
        return 0;

    queue <binaryTreeNode*> q;
    int counter = 0;

    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(root->left && root->right)
            counter++;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return counter;
}

int getNumberOfHalfNodes(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    int onLeft = getNumberOfHalfNodes(root->left);
    int onRight = getNumberOfHalfNodes(root->right);

    if((root->left || root->right) && !(root->right && root->left))
        return (onLeft + onRight + 1);
    else 
        return (onLeft + onRight);
}

int getNumberOfHalfNodesWithoutRecurrsion(struct binaryTreeNode* root)
{

    if(!root)
        return 0;

    queue <binaryTreeNode*> q;
    int counter = 0;

    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if((root->left || root->right) && !(root->right && root->left))
            counter++;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return counter;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    cout<<"Number of full nodes: "<<getNumberOfFullNodes(tree)<<endl;
    cout<<"Number of full nodes: "<<getNumberOfFullNodesWithoutRecurrsion(tree)<<endl;
    cout<<"Number of Half nodes: "<<getNumberOfHalfNodes(tree)<<endl;
    cout<<"Number of Half nodes: "<<getNumberOfHalfNodesWithoutRecurrsion(tree)<<endl;
    return 0;
}