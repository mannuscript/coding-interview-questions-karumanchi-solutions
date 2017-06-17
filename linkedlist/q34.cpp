#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;


/*
 * Assumptions:
 * List is non empty
 * List is circular
 */
struct node* josephusCircle(struct node* head, int n)
{
    int counter;
    
    while(head != head->next)
    {
        counter = n-1;
        while(--counter)
        {
            head = head->next;
        }
        //Remove the node
        struct node* temp = head->next;
        //cout<<"Going to remove node:"<<head->next->data<<endl;
        head->next = head->next->next;
        head = head->next;
        free(temp);
        temp = NULL;
        //printList(head);
    }
    return head;
}

int main(int argc, char * args[])
{
    
    if(argc == 1)
    {
        cout<<"Please pass N as command line input!"<<endl;
        return 1;
    }
    int arr[] = {1,2,3,4,5};
    struct node* head = getALinkedList(arr, 5);
    //Make the list circular
    getTail(head)->next = head;
    struct node* ptr = josephusCircle(head, atoi(args[1]));
    if(ptr)
        cout<<"Last remaining node is:"<<ptr->data<<endl<<"##################"<<endl;
    return 0;
}