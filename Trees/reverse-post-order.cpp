#include<iostream>
#include"Trees.h"

using namespace std;

/*
 *  Given a Tree:
 *              10
 *            /   \
 *           1     20
 *         /  \   /  \
 *        3    4  50   60
 * 
 * Post order will be: 3,4,1,50,60,20,10  (i.e. Left->right->root)
 * For reverse Post order we would follow: right->left->root
 * i.e.:  60,50,20,4,3,10
 *
 * Application:
 * 1) Given BST, print all the leaves in descending order!
 */
void reversePostOrder(struct binaryTreeNode* root)
{
    if(root) {
        reversePostOrder(root->right);
        reversePostOrder(root->left);
        cout<<root->data<<" ";
    }
}

/*
 * Print the leave nodes of a BST in descending order.
 * Uses reverse Post order as shown above.
 * Assumption: Given tree must be a BST 
 */
void printLeavesInDescending(struct binaryTreeNode* root) {
    if(root) {
        printLeavesInDescending(root->right);
        printLeavesInDescending(root->left);
        if(!root->left && !root->right) {
            cout<<root->data<<" ";
        }
    }
}

int main(void)
{
    struct binaryTreeNode *root = getASampleBST();
    printLeavesInDescending(root);
    cout<<endl;
    return 0;
}