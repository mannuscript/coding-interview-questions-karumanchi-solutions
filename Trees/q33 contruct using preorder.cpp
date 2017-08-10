#include<iostream>
#include"Trees.h"

/*
 * 1 -> Internal node
 * 2 -> Leave node
 */

struct binaryTreeNode* getTheTree(char *pre, int len, int counter)
{
    if(len <= counter)
        return NULL;

    struct binaryTreeNode* newNode = getBinaryTreeNode(pre[counter]);

    if(pre[counter] == 1) {
        newNode->left = getTheTree(pre, len, ++counter);
        newNode->right = getTheTree(pre, len, ++counter);
    }

    return newNode;
}

int main(void) 
{
    char pre[] = {1,2,1,2,2};
    int length = 5, counter = 0;
    struct binaryTreeNode* tree = getTheTree(pre, length, counter);
    preorder_print(tree);
    cout<<endl;
    inorder_print(tree);
    cout<<endl;
    return 0;
}