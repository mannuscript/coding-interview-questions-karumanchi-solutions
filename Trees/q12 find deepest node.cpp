#include<iostream>
#include"Trees.h"
#include<queue>

int findTheDeepestNode(struct binaryTreeNode* root)
{
    if(!root)
        return 0;

    queue<binaryTreeNode*> q;

    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();

        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        
    }
    return root->data;

}

int main(void) 
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<findTheDeepestNode(tree)<<endl;
    return 0;
}