#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

struct node* reverseNnode(struct node* head, int n)
{
    if(!head || !head->next)
        return head;
    struct node* nextPtr = head->next;
    struct node* prePtr = NULL;
    struct node* oldHead = head;

    while(--n)
    {
        head->next = prePtr;
        prePtr = head;
        head = nextPtr;
        nextPtr = nextPtr->next;
    }
    oldHead->next = nextPtr;
    head->next = prePtr;

    return head;
}

struct node* moveNnodes(struct node* head, int n)
{
    cout<<head->next<<"Got list:";
    printList(head);
    while(n-- && head)
    {
        cout<<endl<<"Loop over "<<head<<endl;
        if(head){
            head = head->next;
            cout<<endl<<"Inside it:   "<<head->data<<"#";
        }
    }
    cout<<"terminating!!";
    return head;
}

int main(int argc, char* argv[])
{
    int arr[] = {1,2,3,4,5,6};
    struct node* head = getALinkedList(arr, 6);
    struct node* ptr = head;
    int n = atoi(argv[1]);
    //struct node* newH = reverseNnode(head,);
    //printList(newH);
    
    while(ptr->next)
    {
        if(head == ptr) {
            head = reverseNnode(ptr, n);
            printList(head);
            ptr = moveNnodes(head, n-1);
            printList(ptr);
        }
        else { 
            ptr->next = reverseNnode(ptr->next, n);
            cout<<"oops!";
            printList(head);
            cout<<"REaching here?";
            ptr = moveNnodes(ptr,n);
            cout<<"REaching there?";
            printList(ptr);
        }
        printList(ptr);
        //cout<<ptr->data;
    }
    printList(head);
    return 0;
}