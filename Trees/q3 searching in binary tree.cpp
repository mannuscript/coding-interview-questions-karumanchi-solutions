#include"Trees.h"
#include<iostream>

bool searchInATree(struct binaryTreeNode* root, int data) {

    if(!root)
        return false;

    if(root->data == data)
        return true;
    
    bool onLeft = searchInATree(root->left, data);
    bool onRight = searchInATree(root->right, data);

    if(onLeft || onRight)
        return true;
    else return false;

}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<searchInATree(tree, 11)<<endl;
    return 0;
}