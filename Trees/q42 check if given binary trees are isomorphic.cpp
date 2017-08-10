#include<iostream>
#include"Trees.h"

bool areTreesIsomorphic(struct binaryTreeNode* root1, struct binaryTreeNode* root2)
{
    if(!root1 && !root2) {
        //cout<<root1<<" "<<root2<<endl;
        return true;
    }
    levelOrder_print(root2);
    cout<<endl;
    
    if((root1 && !root2) || (!root1 && root2))
        return false;
    bool leftFlag = areTreesIsomorphic(root1->left, root1->left);
    bool rightFlag = areTreesIsomorphic(root1->right, root2->right);
    return leftFlag && rightFlag;
}

int main(void)
{
    struct binaryTreeNode* tree1 = getASampleTree();
    struct binaryTreeNode* tree2 = getASampleTree();
    tree2->right->left->left = getBinaryTreeNode(100);
    //cout<<tree2->right->left->right->data<<tree2->right->left->data<<endl;
    //levelOrder_print(tree1);
    //cout<<endl;
    //levelOrder_print(tree2);
    //cout<<endl;
    cout<<areTreesIsomorphic(tree1, tree2)<<endl;
    return 0;
}