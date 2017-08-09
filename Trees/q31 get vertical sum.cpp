#include<iostream>
#include"Trees.h"

/*
 * Get width of sub tree 
 * direction 1->left, 2->right
 */
int getWidth(struct binaryTreeNode* root, int direction)
{
    if(!root)
        return 0;
    if(direction == 1)
        return getWidth(root->left, direction) + 1;
    else 
        return getWidth(root->right, direction) + 1;
}

void getVerticalLevelSum(struct binaryTreeNode* root, int *arr, int verticalLevel)
{
    if(!root)
        return;
    arr[verticalLevel] += root->data;
    getVerticalLevelSum(root->left, arr, verticalLevel-1);
    getVerticalLevelSum(root->right, arr, verticalLevel+1);
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    int 
        leftWidth = getWidth(tree, 1),
        rightWidth = getWidth(tree, 2);
    int arr[leftWidth + rightWidth - 1];
    
    //Initialize the array with all zeros
    for(int i = 0; i < leftWidth + rightWidth - 1; i++) {
        arr[i] = 0;
    }
    getVerticalLevelSum(tree, arr, leftWidth - 1);
    for(int i = 0; i < leftWidth + rightWidth - 1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}