#include<iostream>
#include"Trees.h"
#include<queue>

int searchInATree(struct binaryTreeNode* root, int data) 
{
    queue <binaryTreeNode*> q;

    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(root->data == data)
            return true;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return false;
}

int main(void) 
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<searchInATree(tree,1011)<<endl;
    return 0;
}