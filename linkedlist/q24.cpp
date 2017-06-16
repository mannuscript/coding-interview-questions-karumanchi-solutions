#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

//Assumption: non circular linked list!
struct node* findMiddleNode(struct node* head)
{
    if(!head)
        return head;
    struct node* fastPtr = head;
    struct node* slowPtr = head;
    while(fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

int main(void)
{
    int arr[] = {4,1,8,2,10,12};
    struct node* head = getALinkedList(arr, 6);
    cout<<findMiddleNode(head)->data;
    return 0;
}