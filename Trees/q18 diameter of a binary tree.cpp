#include<iostream>
#include"Trees.h"

int findDiameterOfATree(struct binaryTreeNode* root, int *diameter)
{
    if(!root)
        return 0;
    
    int leftHeight = findDiameterOfATree(root->left, diameter);
    int rightHeight = findDiameterOfATree(root->right, diameter);

    if(*diameter < (leftHeight + rightHeight + 1))
        *diameter = (leftHeight + rightHeight + 1);

    if(leftHeight < rightHeight)
        return rightHeight + 1;
    else return leftHeight + 1;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    int *diameter = (int *)malloc(sizeof(int));
    *diameter = 0;
    findDiameterOfATree(tree, diameter);
    cout<<"Max dimater: "<<*diameter<<endl;

    return 0;
}