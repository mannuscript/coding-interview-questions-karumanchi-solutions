#include<iostream>
#include"Trees.h"

int findSumOfAllNodes(struct naryTreeNode* root) 
{
    if(!root)
        return 0;
    return  root->data + findSumOfAllNodes(root->child) + findSumOfAllNodes(root->nextSibling);
}

int main(void)
{
    struct naryTreeNode* tree = getASampleGerericTree();
    cout<<findSumOfAllNodes(tree)<<endl;
    return 0;
}