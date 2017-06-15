#include<stdio.h>
#include<iostream>
#include"linkedList.h"

using namespace std;

struct node* push(struct node* head, int data)
{
    struct node* newNode = getANode(data);
    newNode->next = head;
    return newNode;
}



int pop(struct node** head)
{
    if(!*head)
        return 0;
    int data = (*head)->data;
    struct node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    free(temp);
    return data;
}

int main(void)
{
    struct node* head = getANode(1);
    int arr[] = {2,3,4,5};

    for(int i=0;i<4;i++)
    {
        head = push(head, *(arr+i));    
    }
    printList(head);
    cout<<pop(&head)<<endl;
    cout<<pop(&head)<<endl;
    printList(head);
    return 0;
}
