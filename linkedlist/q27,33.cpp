#include<stdio.h>
#include<iostream>

#include"linkedList.h"
using namespace std;



int main(void)
{
    int arr[] = {10,123,14,534};
    HashedList hl(arr, 4);
    hl.printMap();
    struct node* newNode = hl.findNode(0);
    if(newNode)
        cout<<newNode->data<<endl;
    else
        cout<<"Node not found in the list!"<<endl;
    cout<<"#####################"<<endl;
    return 0;
}
