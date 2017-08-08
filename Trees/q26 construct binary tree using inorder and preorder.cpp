#include<iostream>
#include"Trees.h"

int linearSearch(int *arr, int data, int start, int end) 
{
    for(int i = start; i <= end; i++) {
        //cout<<i<<" "<<data<<" "<<arr[i]<<" "<<end<<endl;
        if(data == arr[i])
            return i;
    }
    return -1;
}

struct binaryTreeNode* constructTreeFromPreOrder(int * inorder, int * preorder, int start, int end)
{

    if(start > end)
        return NULL;
    struct binaryTreeNode* root = getBinaryTreeNode(preorder[start]);
    int index = linearSearch(inorder, preorder[start], start, end);

    root->left = constructTreeFromPreOrder(inorder, preorder + 1 , start, index-1);
    root->right = constructTreeFromPreOrder(inorder, preorder , index + 1, end);
    return root;
}

int main(void)
{
    int inorder[] = {4,2,5,1,6,3},
        pre[] = {1,2,4,5,3,6};

    levelOrder_print(constructTreeFromPreOrder(inorder, pre, 0, 5));
    cout<<endl;
    return 0;
}