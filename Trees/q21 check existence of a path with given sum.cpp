#include<iostream>
#include"Trees.h"

bool checkExistenceOfAPath(struct binaryTreeNode* root, int sum, int sumUntillNow)
{
    if(!root)
        return false;
    sumUntillNow = root->data + sumUntillNow;
    if(sumUntillNow == sum)
        return true;
    return checkExistenceOfAPath(root->left, sum, sumUntillNow) || checkExistenceOfAPath(root->right, sum, sumUntillNow);
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    cout<<checkExistenceOfAPath(tree, 6, 0)<<endl;

    return 0;
}