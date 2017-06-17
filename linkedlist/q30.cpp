#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

struct node* splitList(struct node* head)
{
    if(!head)
        return head;
    struct node* fastPtr = (head)->next;
    struct node* slowPtr = head;

    while(fastPtr->next != head && fastPtr->next->next != head)
    {
        cout<<"Finding nemo!"<<endl;
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    fastPtr->next = slowPtr->next;
    struct node* temp = slowPtr->next;
    slowPtr->next = head;
    return temp;
}

int main(void)
{
    int arr[] = {1,2,3,4,5};
    struct node* head = getALinkedList(arr, 5);
    head->next->next->next->next->next = head;
    //printList(head);
    struct node* head2 = splitList(head);
    //cout<<head2->data;
    printList(head2);
    return 0;
}