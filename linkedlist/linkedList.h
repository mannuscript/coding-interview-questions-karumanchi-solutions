#include<iostream>
#include<unordered_map>

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
    if(!head)
        return;
        
    struct node* ptr = head;
    do
    {
        cout<<head->data<<" ";
        head = head->next;
    } while(head && head != ptr);
    cout<<endl;
}

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

//Returns one node previos to middle node
struct node* getMiddleNode(struct node* head)
{
    struct node* fastPtr = head->next;
    struct node* slowPtr = head;

    while(fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    return slowPtr;
}

struct node* getTail(struct node* head)
{
    while(head->next)
        head = head->next;
    return head;
}

/*
 * Time complexity: O(n)
 * Space Complexity Null
 */
struct node* reverseLinkedList(struct node* head)
{
    if(!head)
        return head;

    struct node * forwardPtr = head->next;
    struct node * ptr = head;
    struct node * prePtr = NULL;
    
    while(ptr)
    {
        ptr->next = prePtr;
        prePtr = ptr;
        ptr = forwardPtr;
        if(forwardPtr)
            forwardPtr = forwardPtr->next;
    }
    return prePtr;
}

/*
 * Stack of linked list node
 * Uses linked list to maintain a stack!
 */
class Stack {
    private:
        struct node* head;
        int length;
    public:
        Stack(int *arr, int n)
        {
            this->head = NULL;
            this->length = n;
            int i =0;
            while(n--)
            {
                struct node* newNode = getANode(*(arr+i++));
                newNode->next = this->head;
                this->head = newNode;
            }
        }
        Stack()
        {
            this->length = 0;
            this->head = NULL;
        }
        struct node* pop()
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
        void printStack()
        {
            struct node* ptr = this->head;
            while(ptr){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
        
};

class HashedList {
    private: 
        struct node* head;
        unordered_map<int, struct node*> umap;
    
    public:
        void printMap()
        {
            for(auto it = this->umap.begin(); it != this->umap.end(); it++)
                cout<<it->first<<" ";
            cout<<endl;
        }

        HashedList(int *arr, int n)
        {
            this->head = getALinkedList(arr, n);
            struct node* ptr = head;
            while(ptr)
            {
                this->umap[ptr->data] = ptr;
                ptr = ptr->next;
            }
        }

        struct node* findNode(int n)
        {
            return this->umap[n];
        }
};