#include<iostream>
#include"Trees.h"
#include<queue>

int findSumOfTree(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    return root->data + findSumOfTree(root->left) + findSumOfTree(root->right);
}

int findSumOfTreeWithoutRecurrsion(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    queue<binaryTreeNode*> q;
    q.push(root);
    int sum = 0;

    while(!q.empty()) {
        root = q.front();
        q.pop();
        sum += root->data;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return sum;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    cout<<"Sum of the tree is: "<<findSumOfTree(tree)<<endl;
    cout<<"Sum of the tree using level order: "<<findSumOfTreeWithoutRecurrsion(tree)<<endl;
    return 0;
}