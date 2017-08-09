#include<iostream>
#include"Trees.h"

int preIndex = 0, postIndex = 0;

int linearSearch(int *arr, int data, int start, int end) 
{
    for(int i = start; i <= end; i++) {
        //cout<<i<<" "<<data<<" "<<arr[i]<<" "<<end<<endl;
        if(data == arr[i])
            return i;
    }
    return -1;
}

struct binaryTreeNode* constructTreeFromPostorder(int * inorder, int * postorder, int start, int end)
{
    if(start > end)
        return NULL;
    cout<<"@#@#@#@#@# "<<postIndex<<" "<<start<<" "<<end<<" #@$@#$@#$"<<endl;
    struct binaryTreeNode* root = getBinaryTreeNode(postorder[postIndex--]);
    int index = linearSearch(inorder, root->data, start, end);
    
    if (start == end)
        return root;
    
    root->left = constructTreeFromPostorder(inorder, postorder , start, index - 1);
    root->right = constructTreeFromPostorder(inorder, postorder , index + 1, end);
    
    
    return root;
}

struct binaryTreeNode* constructTreeFromPreorder(int * inorder, int * preorder, int start, int end)
{

    if(start > end)
        return NULL;
    struct binaryTreeNode* root = getBinaryTreeNode(preorder[preIndex++]);
    int index = linearSearch(inorder, root->data, start, end);

    root->left = constructTreeFromPreorder(inorder, preorder , start, index-1);
    root->right = constructTreeFromPreorder(inorder, preorder , index + 1, end);
    return root;
}

int main(void)
{
    int inorder[] = {4,2,5,1,6,3},
        pre[] = {1,2,4,5,3,6},
        post[] = {};
    struct binaryTreeNode* root = constructTreeFromPreorder(inorder, pre, 0, 5);
    levelOrder_print(root);
    cout<<endl;
    postIndex = 5;
    levelOrder_print(constructTreeFromPostorder(inorder,post,0 ,5));
    cout<<endl;
    return 0;
}