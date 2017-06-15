#include<iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* getANode(int value)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node*));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* getALinkedList(int *arr, int len)
{

    if(!len)
        return NULL;
    
    struct node* head = getANode(*arr);
    struct node* ptr = head;

    for(int i = 1; i< len; i++)
    {
        ptr->next = getANode(*(arr+i));
        ptr = ptr->next;
    }
    return head;
}

void printList(struct node* head)
{
 while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
