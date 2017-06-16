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
    Stack s1;
    Stack s2;
    while(!head1)
    {
        s1.push(head1->data);
        head1 = head1->next;
    }
    while(!head2)
    {
        s2.push(head2->data);
        head2 = head2->next;
    }
    struct node* ptr1;
    struct node* ptr2;
    struct node* result;
    while(true)
    {
        ptr1 = s1.pop();
        ptr2 = s2.pop();
        if(ptr1 != ptr2)
        {
            return result;
        }
        result = ptr1;
    }
    
}

int main(void)
{
    int arr1[] = {1,3};
    int arr2[] = {1,5,2,7,2,5};
    struct node * head1 = getALinkedList(arr1,2);
    struct node * head2 = getALinkedList(arr2,6);
    head1->next->next = head2->next->next->next;
    printList(head1);
    printList(head2);
    struct node* intersection = getIntersection(head1, head2);
    if(intersection)
        cout<<intersection->data<<endl<<"***********************";
    struct node* inter = getIntersectionUsingStack(head1, head2);
    if(inter)
        cout<<intersection->data<<endl<<"***********************";
}