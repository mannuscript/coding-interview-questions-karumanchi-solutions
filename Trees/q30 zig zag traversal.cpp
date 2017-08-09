#include<iostream>
#include"Trees.h"
#include<stack>
#include<queue>

void zigzagTraversal(struct binaryTreeNode *root)
{
    if(!root)
        return;
    
    queue <binaryTreeNode*> q;
    stack <int> s;
    int level = 1;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        root = q.front();
        q.pop();
        if(!root) {
            //cout<<endl<<"Null found "<<level<<endl;
            //Change the level
            level++;
            if(q.empty())
                break;
            //Mark the end of next level
            q.push(NULL);

            //But if level is even, then push the elements in stack and print
            if(level % 2 == 0) {
                while(q.front()) {
                    root = q.front();
                    q.pop();

                    s.push(root->data);

                    if(root->left)
                        q.push(root->left);
                    if(root->right)
                        q.push(root->right);
                }
                //pop null from front
                q.pop();
                level++;
                //push null at end of queue to mark the end of queue
                q.push(NULL);
                
                //empty the stack and print all elements
                //cout<<endl<<"going to print stack"<<endl;
                cout<<endl;
                while(!s.empty()) {
                    cout<<s.top()<<" ";
                    s.pop();
                }
                cout<<endl;
            }
            continue;
        }
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        cout<<root->data<<" ";
    }
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();
    zigzagTraversal(tree);
    return 0;
}