#include<iostream>
#include"Trees.h"

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<"Height of the tree: "<<getHeightOfTree(tree)<<endl;
    return 0;
}