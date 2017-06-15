#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

//Assumption: Lists are intersecting
struct node* getIntersection(struct node* head1, struct node* head2)
{
    int 
        len1 = getLength(head1),
        len2 = getLength(head2),
        diff = 0;
    
    struct node* shorter = NULL;
    struct node* longer;

    if(len1 > len2) 
    {
        diff = len1-len2;
        shorter = head2;
        longer = head1;
    } else {
        diff = len2-len1;
        shorter = head1;
        longer = head2;
    }
    
    while(diff--)
        longer = longer->next;

    while(longer != shorter)
    {
        longer = longer->next;
        shorter = shorter->next;
    }

    return shorter;

}

struct node* getIntersectionUsingStack(struct node* head1, struct node* head2)
{
    int arr[] = {1,4,1,5};
    Stack s(arr,4);
    
    
    
}

int main(void)
{
    int arr1[] = {1,3};
    int arr2[] = {1,5,2,7,2,5};
    struct node * head1 = getALinkedList(arr1,2);
    struct node * head2 = getALinkedList(arr2,6);
    head1->next->next = head2->next->next;
    printList(head1);
    printList(head2);
    struct node* intersection = getIntersection(head1, head2);
    if(intersection)
        cout<<intersection->data<<endl<<"***********************";

}