#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

struct node* reverseUsingRecurrsionHelper(struct node** newHead, struct node* ptr)
{
    if(!ptr->next)
    {
        *newHead = ptr;
        return ptr;
    }
    struct node* pre = reverseUsingRecurrsionHelper(newHead, ptr->next);
    pre->next = ptr;
    return ptr;
}

struct node* reverseUsingRecurrsion(struct node* head)
{
    struct node** newHead = (struct node**)malloc(sizeof(struct node*));
    struct node* newTail = reverseUsingRecurrsionHelper(newHead, head);
    newTail->next = NULL;
    return *newHead;
}

int main(void)
{
    //int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int arr[] = {1,2};
    struct node* head = getALinkedList(arr, 2);
    printList(head);
    head = reverseUsingRecurrsion(head);
    printList(head);
    return 0;
}