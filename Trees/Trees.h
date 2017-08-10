#include<iostream>
#include <stack>
#include <queue>
using namespace std;




/*
 * #####################Binary Tree library...
 */
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
struct binaryTreeNode* getASampleTree() {
    struct binaryTreeNode *root1 = getBinaryTreeNode(1);
    root1->left = getBinaryTreeNode(2);
    root1->left->right = getBinaryTreeNode(5);
    root1->left->right->left = getBinaryTreeNode(50);
    root1->left->left = getBinaryTreeNode(4);
    root1->left->left->left = getBinaryTreeNode(8);

    root1->right = getBinaryTreeNode(3);
    root1->right->left = getBinaryTreeNode(300);
    root1->right->right = getBinaryTreeNode(7);
    root1->right->right->right = getBinaryTreeNode(15);
    return root1;
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

void mirrorTree(struct binaryTreeNode* root)
{
    if(!root)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    //Swap child nodes
    struct binaryTreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    return;
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

void inorder_print(struct binaryTreeNode* root)
{

    if(root) {
        inorder_print(root->left);
        cout<<root->data<<" ";
        inorder_print(root->right);
    }
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


/*
 *  ####### generic tree library
 * Representation:
 * First child, next sibling representation:
 * E.g. Here Root has 4 children, but link to only one child (root.1) and further 
 * every children has pointer to next sibling
 *  [Root node]
 *    |
 *  [child root.1] - [child root.2] - [child root.3] - [child root.4] - NULL
 *    |                                                     |
 *  [child root.1.1] - [child root.1.2]                   [child root.4.1]
 */

struct naryTreeNode {
    int data;
    struct naryTreeNode* child;
    struct naryTreeNode* nextSibling;
};

struct naryTreeNode* getANaryTreeNode(int data) 
{
    struct naryTreeNode* newNode = (struct naryTreeNode*) malloc(sizeof(naryTreeNode));
    newNode->data = data;
    newNode->nextSibling = NULL;
    newNode->child = NULL;
    return newNode;
}

struct naryTreeNode* getASampleGerericTree() {
    struct naryTreeNode* 
        root = getANaryTreeNode(1);
    root->child = getANaryTreeNode(11);
    root->child->nextSibling = getANaryTreeNode(12);
    root->child->nextSibling->nextSibling = getANaryTreeNode(13);
    root->child->nextSibling->nextSibling->nextSibling = getANaryTreeNode(13);
    root->child->nextSibling->child = getANaryTreeNode(121);
    root->child->nextSibling->child->nextSibling = getANaryTreeNode(122);
    return root;
}

int getNumberOfChildren(struct naryTreeNode* root)
{
    if(!root)
        return 0;
    int counter = 0;
    root = root->child;

    while(root) {
        root = root->nextSibling;
        counter++;
    }
    return counter;
}