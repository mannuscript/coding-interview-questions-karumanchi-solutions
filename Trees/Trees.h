#include<iostream>
#include <stack>
#include <queue>
using namespace std;

struct binaryTreeNode{
    struct binaryTreeNode* left;
    struct binaryTreeNode* right;
    int data;
};

struct binaryTreeNode* getBinaryTreeNode(int data) 
{
    struct binaryTreeNode* newNode = (struct binaryTreeNode*) malloc(sizeof(struct binaryTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int getHeightOfTree(struct binaryTreeNode* root)
{
    if(!root)
        return 0;
    
    int leftHeight = getHeightOfTree(root->left);
    int rightHeight = getHeightOfTree(root->right);

    if(leftHeight > rightHeight)
        return (leftHeight + 1);
    else return (rightHeight + 1);
}

void inorder_print(struct binaryTreeNode* root)
{

    if(root) {
        inorder_print(root->left);
        cout<<root->data<<" ";
        inorder_print(root->right);
    }
}

struct binaryTreeNode* getASampleTree() {
    struct binaryTreeNode *root1 = getBinaryTreeNode(1);
    root1->left = getBinaryTreeNode(2);
    root1->left->right = getBinaryTreeNode(5);
    root1->left->left = getBinaryTreeNode(4);
    root1->left->left->left = getBinaryTreeNode(8);

    root1->right = getBinaryTreeNode(3);
    root1->right->right = getBinaryTreeNode(7);
    root1->right->right->right = getBinaryTreeNode(15);
    return root1;
}

void inorder_print_loop(struct binaryTreeNode* root)
{

    stack <binaryTreeNode*> s;
    do {
        while(root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        cout<<root->data<<" ";
        if(root->right)
            s.push(root->right);
    } while(!s.empty());
}

void preorder_print(struct binaryTreeNode* root)
{
    if(root) {
        cout<<root->data<<" ";
        preorder_print(root->left);
        preorder_print(root->right);
    }
}

void postorder_print(struct binaryTreeNode* root)
{
    if(root) {
        postorder_print(root->left);
        postorder_print(root->right);
        cout<<root->data<<" ";
    }
}

void levelOrder_print(struct binaryTreeNode* root)
{
    if(!root)
        return;
    
    queue <binaryTreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        cout<<root->data<<" ";
    }
}