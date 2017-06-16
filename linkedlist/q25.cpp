#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

void printInReverseOrder(struct node* head)
{
    if(!head)
        return;
    printInReverseOrder(head->next);
    cout<<head->data<<" ";
}

int main(void)
{
    int arr[] = {1};
    struct node* head = getALinkedList(arr, 1);
    printInReverseOrder(head);
    return 0;
}