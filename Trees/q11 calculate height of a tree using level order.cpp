#include<iostream>
#include"Trees.h"
#include <queue>

int getHeight(struct binaryTreeNode* root) 
{
    int level = 0;
    queue <binaryTreeNode*> q;

    if(!root)
        return 0;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        root = q.front();
        q.pop();

        if(root == NULL) {
            level++;
            if(!q.empty())
                q.push(NULL);
        } else {
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
    return level;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<"Height of tree: "<<getHeight(tree)<<endl;
    return 0;
}