#include<iostream>
#include"Trees.h"

struct binaryTreeNode* delANode(struct binaryTreeNode* root, int data)
{
    if(!root)
        return root;
    //Find the deepest root and remove it from there.
    
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    levelOrder_print(tree);
    tree = delANode(tree, 50);
    levelOrder_print(tree);
}