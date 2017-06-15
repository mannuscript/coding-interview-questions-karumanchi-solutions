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

/*
 * Stack of linked list node
 * Uses stack DS to maintain a stack!
 */
class Stack {
    private:
        struct node* head;
        int length;
    public:
        Stack(int *arr, int n)
        {
            this->head = NULL;
            this->length = 0;
            int i =0;
            while(n--)
            {
                struct node* newNode = getANode(*(arr+i++));
                newNode->next = this->head;
                this->head = newNode;
            }
        }
        int pop()
        {
            struct node* ptr = this->head;
            this->head = this->head->next;
            this->length--;
            return ptr;
        }
        void push(int data)
        {
            struct node* newNode = getANode(data);
            newNode->next = this->head;
            this->length++;
            this->head = newNode;
        }
        int getLength()
        {
            return this->length;
        }
        
};


int getLength(struct node* head)
{
    int length = 0;
    while(head)
    {
        length++;
        head = head->next;
    }
    return length;
}