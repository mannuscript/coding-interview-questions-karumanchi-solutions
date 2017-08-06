#include<iostream>
#include"Trees.h"
#include<queue>

struct binaryTreeNode* insertANode(struct binaryTreeNode* root, int data) {
    
    struct binaryTreeNode* newNode = getBinaryTreeNode(data);
    
    if(!root)
        return newNode;
    
    queue <binaryTreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(!root->left) {
            root->left = newNode;
            return root;
        } else if(!root->right) {
            root->right = newNode;
            return root;
        }
        q.push(root->left);
        q.push(root->right);
    }
    //Should not reach here
}

int main(void) {
    struct binaryTreeNode* root = getASampleTree();
    levelOrder_print(root);
    cout<<endl<<endl;
    insertANode(root, 111);
    levelOrder_print(root);
    return 0;
}