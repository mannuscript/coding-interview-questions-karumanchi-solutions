#include<iostream>
#include"Trees.h"

int getLCAHelper(struct binaryTreeNode* root, int a, int b)
{
    if(!root)
        return NULL;
    
    int 
        left = getLCAHelper(root->left, a, b),
        right = getLCAHelper(root->right, a, b);
    //cout<<"@#@#@#@#@#@#@:"<<left<<"    "<<right<<" "<<root->data<<endl;
    if( (left == a && right == b) 
        || (left == b && right == a) 
        || (root->data == a && (left == b || right == b))
        || (root->data == b && (left == a || right == a))
        ) {
        cout<<"LCA:: "<<root->data<<endl;
        return NULL;
    }
    if(root->data == a)
        return a;
    else if(root->data == b)
        return b;
    
    return left ? left : right;
        
}

void getLCANode(struct binaryTreeNode* root, int a, int b)
{
    getLCAHelper(root, a, b);
    return;    
}

int main(void) 
{
    struct binaryTreeNode* tree = getASampleTree();
    getLCANode(tree, 8, 2);
    return 0;
}