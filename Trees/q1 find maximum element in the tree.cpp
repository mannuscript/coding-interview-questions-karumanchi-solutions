#include<iostream>
#include"Trees.h"
#define NEG_INFINITY -99999;

int findMax(struct binaryTreeNode* root) {
    if(!root)
        return NEG_INFINITY;
    
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int currentData = root->data;

    if(leftMax > rightMax && leftMax > currentData)
        return leftMax;
    if(rightMax > leftMax && rightMax > currentData)
        return rightMax;
    else 
        return currentData;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<findMax(tree)<<endl;
}