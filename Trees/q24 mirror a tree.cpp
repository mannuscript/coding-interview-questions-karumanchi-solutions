#include<iostream>
#include"Trees.h"

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    levelOrder_print(tree);
    cout<<endl;
    mirrorTree(tree);
    levelOrder_print(tree);
    cout<<endl;
    return 0;
}