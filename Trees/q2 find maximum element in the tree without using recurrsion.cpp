#include<iostream>
#include"Trees.h"
#include<queue>

using namespace std;

int findMaximumUsingLevelOrder(struct binaryTreeNode* root)
{
    queue <binaryTreeNode*> q;
    int max = INT_MIN;
    q.push(root);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(max < root->data)
            max = root->data;
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
    }
    return max;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    cout<<findMaximumUsingLevelOrder(tree)<<endl;
    return 0;
}