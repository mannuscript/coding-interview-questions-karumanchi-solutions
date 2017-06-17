#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

struct node* mergeList(struct node* head1, struct node* head2)
{
    struct node* head3 = getANode(0);
    struct node* ptr = head3;
    
    while(head1 || head2)
    {
        if((head1 && head2 && head1->data < head2->data) || (head1 && !head2))
        {
            ptr->next = getANode(head1->data);
            head1 = head1->next;
            ptr = ptr->next;
        } else if((head2 && head1 && head2->data <= head1->data) || (!head1 && head2)){
            ptr->next = getANode(head2->data);
            head2 = head2->next;
            ptr = ptr->next;
        }
    }
    return head3->next;
}

int main(void)
{
    int
     arr1[] = {1,4,7,15,67},
     arr2[] = {3,7,32,78,345};

    struct node* head1 = getALinkedList(arr1,5);
    struct node* head2 = getALinkedList(arr2,5);
    //printList(head2);
    struct node* head3 = mergeList(head1, head2);
    printList(head3);
    return 0;
}