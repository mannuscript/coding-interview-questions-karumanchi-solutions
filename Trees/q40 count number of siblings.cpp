#include<iostream>
#include"Trees.h"

bool isChild(struct naryTreeNode* root, struct naryTreeNode* node)
{
    if(!root || !node)
        return false;
    root = root->child;

    while(root) {
        if(root == node)
            return true;
        root = root->nextSibling;
    }
    return false;
}

int getNumberOfSiblings(struct naryTreeNode* root, struct naryTreeNode* node)
{
    if(!root)
        return NULL;

    if(isChild(root, node)) {
        return getNumberOfChildren(root);
    }
    int child = getNumberOfSiblings(root->child, node);
    int sib = getNumberOfSiblings(root->nextSibling, node);
    return sib ? sib : child;
}


int main(void)
{
    struct naryTreeNode* tree = getASampleGerericTree();
    cout<<getNumberOfSiblings(tree, tree->child->nextSibling->child->nextSibling->child)<<endl;

    return 0;
}