#include<iostream>
#include"Trees.h"

bool compareTrees(struct binaryTreeNode* root1, struct binaryTreeNode* root2)
{   
    if(!root1 && !root2)
        return true;
    
    if((!root1 && root2) || (root2 && !root2))
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    return (compareTrees(root1->left, root2->left) 
            && compareTrees(root1->right, root2->right));
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    struct binaryTreeNode* tree2 = getASampleTree();
    tree2->left->data = 123;

    cout<<compareTrees(tree, tree)<<endl;
    cout<<compareTrees(tree, tree2)<<endl;

    return 0;
}