#include<iostream>
#include"Trees.h"
#include <queue>
int getSizeOfTree(struct binaryTreeNode* root) 
{
    if(!root)
        return 0;
    int leftSize = getSizeOfTree(root->left);
    int rightSize = getSizeOfTree(root->right);
    return leftSize + rightSize + 1;
}

int getSizeOfTreeUsingLevelOrder(struct binaryTreeNode* root) {
    
    int size = 0;
    queue <binaryTreeNode*> q;

    if(!root)
        return size;
    
    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        size++;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return size;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    levelOrder_print(tree);
    cout<<endl<<getSizeOfTree(tree)<<endl;
    cout<<getSizeOfTreeUsingLevelOrder(tree)<<endl;
    return 0;
}