#include<iostream>
#include"Trees.h"

int getHeightOfTree(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    int leftHeight = getHeightOfTree(root->left);
    int rightHeight = getHeightOfTree(root->right);

    if(leftHeight > rightHeight)
        return (leftHeight + 1);
    else return (rightHeight + 1);
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<"Height of the tree: "<<getHeightOfTree(tree)<<endl;
    return 0;
}