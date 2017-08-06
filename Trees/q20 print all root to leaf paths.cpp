#include<iostream>
#include"Trees.h"

void printAllLeafToRootPaths(struct binaryTreeNode* root, int path[], int depth) 
{
    if(!root) {
        return;
    }
    path[depth++] = root->data;
    if(!root->left && !root->right) {
        //print the array
        cout<<"Path:\n";
        for(int i = 0; i< depth; i++) 
            cout<<path[i]<<" ";
        cout<<endl;
    }

    printAllLeafToRootPaths(root->left, path, depth);
    printAllLeafToRootPaths(root->right, path, depth);

}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();


    int path[getHeightOfTree(tree)];

    printAllLeafToRootPaths(tree, path, 0);

    return 0;
}