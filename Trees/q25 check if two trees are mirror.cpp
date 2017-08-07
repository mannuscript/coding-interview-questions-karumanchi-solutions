#include<iostream>
#include"Trees.h"


bool checkIfMirror(struct binaryTreeNode* root1, struct binaryTreeNode* root2) {

    if(!root1 && !root2)
        return true;
    
    if(!root1 || !root2)
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    return checkIfMirror(root1->left, root2->right) && checkIfMirror(root1->right, root2->left);
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    struct binaryTreeNode* tree2 = getASampleTree();

    mirrorTree(tree2);

    cout<<checkIfMirror(tree,tree2)<<endl;

    return 0;
}