#include"Trees.h"
//Test functions

int main(void) {
    struct binaryTreeNode *root1 = getBinaryTreeNode(4);
    root1->left = getBinaryTreeNode(5);
    root1->left->left = getBinaryTreeNode(50);
    root1->right = getBinaryTreeNode(101);
    
    cout<<"Inorder::\n";
    inorder_print(root1);
    cout<<"\n\nPreorder::\n";
    preorder_print(root1);
    cout<<"\n\nPostorder::\n";
    postorder_print(root1);
    cout<<endl<<"Inorder loop::\n";
    //inorder_print_loop(root1);
    cout<<endl<<"Level order::\n";
    levelOrder_print(root1);
    cout<<endl<<endl;
    cout<<endl;
    return 0;
}