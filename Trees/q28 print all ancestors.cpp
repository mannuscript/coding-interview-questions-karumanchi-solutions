#include<iostream>
#include"Trees.h"
#include<stdio.h>

void printAllAncestorsUsingMemory(struct binaryTreeNode* root, int data, int arr[], int depth) 
{
    if(!root)
        return;
    arr[depth++] = root->data;
    if(root->data == data) {
        //Node found print all the path
        for(int i = 0; i < depth; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printAllAncestorsUsingMemory(root->left, data, arr, depth);
    printAllAncestorsUsingMemory(root->right, data, arr, depth);
}

int main(int argc, char *argv[]) 
{
    struct binaryTreeNode* tree = getASampleTree();
    int arr[1000];
    int data = atoi(argv[1]);
    printAllAncestorsUsingMemory(tree, data, arr, 0);
    return 0;
}
