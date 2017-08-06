#include"Trees.h"
#include<iostream>

void delTheTree(struct binaryTreeNode* root) 
{
    //Lets del the tree in post order
    if(!root)
        return;
    delTheTree(root->left);
    delTheTree(root->right);
    cout<<"Going to del the node: "<<root->data<<endl;
    root->right = NULL;
    root->left = NULL;
    free(root);
    root = NULL;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    levelOrder_print(tree);
    cout<<endl;
    delTheTree(tree);
    return 0;
}