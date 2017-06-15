#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

struct node* findCycle(struct node* head)
{
    if(!head) {
        cout<<"List is fucking empty you fool!"<<endl;
        return NULL;
    }
    struct node *fastPtr = head->next;
    struct node *slowPtr = head;
    cout<<"Testing";
    while(fastPtr != slowPtr) {
        if(!fastPtr->next) {
            cout<<"No cycle found!"<<endl;
            return NULL;
        }
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        cout<<"Cycling....fastPtr: "<<fastPtr->data<<" SlowPtr: "<<slowPtr->data<<endl;
    }
    slowPtr = head;
    while(slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    return slowPtr;
}

int main(int argc, char* argv[])
{
    int arr[] = {1,2,3,4};
    struct node* head = getALinkedList(arr, 4);
    printList(head);
    struct node* cycleHead = findCycle(head);
    //Introducing cycle
    //head->next->next->next->next = head->next;
    head->next->next->next = head->next;
    cycleHead = findCycle(head);
    cout<<(cycleHead->data)<<endl<<"**************"<<endl;
    return 0;
}