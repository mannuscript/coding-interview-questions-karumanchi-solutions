#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;


struct node* insertNodeInSortedList(struct node* head, struct node* newNode)
{
    if(!newNode)
        return head;
    if(!head || head->data > newNode->data) {
        newNode->next = head;
        return newNode;
    }
    struct node* ptr = head;
    while(ptr->next && ptr->next->data < newNode->data)
        ptr = ptr->next;
    //Insert node
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}


int main(int argc, char* argv[])
{
    int arr[] = {10,20,30,40,50};
    struct node* head = getALinkedList(arr, 5);
    printList(head);
    struct node* newNode = getANode(atoi(argv[1]));
    head = insertNodeInSortedList(head, newNode);
    printList(head);
    return 0;
}