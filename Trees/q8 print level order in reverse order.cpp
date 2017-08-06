#include<iostream>
#include"Trees.h"
#include<queue>
#include"../Stacks/Stacks.h"

void levelOrder_print_reverse(struct binaryTreeNode* root)
{
    if(!root)
        return;
    
    queue<binaryTreeNode*> q;
    LLStack s;

    q.push(root);

    while(!q.empty()) {
        
        root = q.front();
        q.pop();
        s.push(root->data);
        
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        
    }
    s.printStack();
}

int main(void) 
{
    struct binaryTreeNode* tree = getASampleTree();
    levelOrder_print(tree);
    cout<<endl;
    levelOrder_print_reverse(tree);
    return 0;
}