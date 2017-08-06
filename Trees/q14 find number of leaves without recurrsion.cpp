#include<iostream>
#include"Trees.h"
#include<queue>

int getNumberOfLeavesWithoutRecurssion(struct binaryTreeNode* root) 
{
    if(!root)
        return 0;

    queue <binaryTreeNode*> q;
    int counter = 0;
    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(!root->left && !root->right) {
            counter++;
        } else {
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
    return counter;
}

int getNumberOfLeaves(struct binaryTreeNode* root) 
{
    if(!root)
        return 0;
    
    if(!root->left && !root->right)
        return 1;
    
    //Number of leaves at left
    int leftLeaves = getNumberOfLeaves(root->left);
    //Number of leaves at right
    int rightLeaves = getNumberOfLeaves(root->right);

    return leftLeaves + rightLeaves;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    cout<<"Number of leaves:"<<getNumberOfLeaves(tree)<<endl;
    cout<<"Number of leaves:"<<getNumberOfLeavesWithoutRecurssion(tree)<<endl;   

    return 0;
}