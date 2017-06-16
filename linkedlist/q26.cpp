#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

bool isEven(struct node* head)
{
    struct node* fastPtr = head;
    
    while(fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
    }
    if(!fastPtr)
        return true;
    return false;
}

int main(void)
{
    int arr[] = {1,2,4,2};
    int arr2[] = {1,2,4,2,5};
    struct node* head = getALinkedList(arr, 4);
    struct node* head2 = getALinkedList(arr2, 5);

    cout<<"List one is even: "<<isEven(head)<<" with length: "<<getLength(head)<<endl;
    cout<<"List one is even: "<<isEven(head2)<<" with length: "<<getLength(head2)<<endl;
    return 0;
}