#include<iostream>
#include"Trees.h"
#include<queue>

int findLevelWithMAxSum(struct binaryTreeNode* root) 
{
    if(!root)
        return 0;
    
    queue<binaryTreeNode*> q;
    q.push(root);
    q.push(NULL);
    int currentLevel = 1;
    int currentSum = 0;
    int maxSum = 0;
    int levelWithMaxSum = 0;

    while(!q.empty()) {
        root = q.front();
        q.pop();

        if(!root) {
            if(currentSum > maxSum) {
                maxSum = currentSum;
                levelWithMaxSum = currentLevel;
            }
            currentLevel++;
            currentSum = 0;
            if(q.empty())
                break;
            q.push(NULL);
        } else {
            currentSum += root->data;
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
    }
    return levelWithMaxSum;
}

int main(void)
{
    struct binaryTreeNode* tree = getASampleTree();

    cout<<findLevelWithMAxSum(tree)<<endl;

    return 0;
}