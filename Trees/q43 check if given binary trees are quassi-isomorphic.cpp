#include<iostream>
#include"Trees.h"

bool areQuassiIsomorphic(struct binaryTreeNode* root1, struct binaryTreeNode* root2)
{
    if(!root1 && !root2) {
        return true;
    }
    if((!root1 && root2) || (!root2 && root1)) {
        return false;
    }

    return areQuassiIsomorphic(root1->left, root1->left)

}

int main(void)
{
    //Tree 1
    struct binaryTreeNode* root1 = getBinaryTreeNode(1);
    root1->left = getBinaryTreeNode(1);
    root1->left->left = getBinaryTreeNode(1);
    root1->left->right = getBinaryTreeNode(1);
    root1->left->right->left = getBinaryTreeNode(1);
    
    root1->right = getBinaryTreeNode(1);
    root1->right->left = getBinaryTreeNode(1);
    root1->right->left->left = getBinaryTreeNode(1);

    struct binaryTreeNode* root2 = getBinaryTreeNode(1);
    root2->left = getBinaryTreeNode(1);
    root2->left->left = getBinaryTreeNode(1);
    root2->left->left->right = getBinaryTreeNode(1);
    
    root2->right = getBinaryTreeNode(1);
    root2->right->left = getBinaryTreeNode(1);
    root2->right->left->left = getBinaryTreeNode(1);
    root2->right->right = getBinaryTreeNode(1);
}