#include<iostream>
#include"Trees.h"

int main(void)
{
    struct naryTreeNode* tree = getASampleGerericTree();
    cout<<getNumberOfChildren(tree)<<endl;
    return 0;
}