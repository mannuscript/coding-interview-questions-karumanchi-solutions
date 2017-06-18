#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<stdlib.h>
using namespace std;

struct splNode {
    int data;
    struct splNode* next;
    struct splNode* random;
};

struct splNode* getASplNode(int data){
    
    struct splNode *newNode = (struct splNode*)malloc(sizeof(struct splNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;

}

int getLength(struct splNode* head)
{
    int i = 0;
    while(head)
    {
        head = head->next;
        i++;
    }
    return i;
}

int random(int n)
{
    return (rand()%n)+1; 
}

struct splNode* getARandomPointer(struct splNode* head)
{
    int len = getLength(head);
    //Get a random number between (1,len)
    int randomNumber = random(len);
    cout<<"Random number generated for len: "<<len<<" is: "<<randomNumber;
    while(--randomNumber)
        head = head->next;
    
    cout<<" Node assigned would be: "<<head->data<<endl;
    return head;
}

struct splNode* getAList(int arr[], int n)
{
    int i = 1;
    struct splNode* head = getASplNode(*(arr));
    struct splNode* ptr = head;
    while(i < n)
    {
        struct splNode* newNode = getASplNode(*(arr+i));
        ptr->next = newNode;
        newNode->random = getARandomPointer(head);
        ptr = ptr->next;
        i++;
    }
    return head;
}

void printList(struct splNode* head)
{
    while(head)
    {
        cout<<head->data;
        if(head->random)
            cout<<"("<<head->random->data<<")"<<" ";
        else
            cout<<" ";
        head = head->next;
    }
    cout<<endl;
}

class nodesHash {
    private:
    unordered_map<struct splNode*,struct splNode*> umap;

    public:
        void printMap()
        {
            for(auto it = this->umap.begin(); it != this->umap.end(); it++)
                cout<<it->first->data<<" : "<<it->second->data<<" ";
            cout<<endl;
        }
        struct splNode* findNode(struct splNode* nodePtr)
        {
            return this->umap[nodePtr];
        }
        void insert(struct splNode* node1, struct splNode* node2)
        {
            umap[node1] = node2;
        }
};


struct splNode* cloneUsingHashMap(struct splNode* head) 
{
    nodesHash umap;
    struct splNode* headCopy = head;
    while(head)
    {
        struct splNode* newNode = getASplNode(head->data);
        umap.insert(head, newNode);
        head = head->next;
    }
    head = headCopy;
    while(head)
    {
        struct splNode* node = umap.findNode(head);
        node->next = head->next;
        node->random = umap.findNode(head->random);
        head =  head->next;
    }
    return umap.findNode(headCopy);
}

int findRandomPtrDistance(struct splNode* head, struct splNode* randomPtr)
{
    int distance  = 1;
    while(head && randomPtr != head)
    {
        distance++;
        head = head->next;   
    }
    return distance;
}

struct splNode* findNodeAtDistance(struct splNode* head, int distance)
{
    while(--distance && head)
        head = head->next;
    return head;
}

struct splNode* clone(struct splNode* head)
{
    if(!head)
        return head;
    //First clone the list
    struct splNode* ptr = head->next;
    struct splNode* newHead = getASplNode(head->data);
    struct splNode* newPtr = newHead;
    while(ptr)
    {
        newPtr->next = getASplNode(ptr->data);
        ptr = ptr->next;
        newPtr = newPtr->next;
    }
    ptr = head;
    newPtr = newHead;
    while(ptr)
    {
        int distance = findRandomPtrDistance(head, ptr->random);
        newPtr->random = findNodeAtDistance(newHead, distance);
        ptr = ptr->next;
        newPtr = newPtr->next;
    }
    return newHead;
}

int main(void)
{
    srand((unsigned)time(0)); 
    int arr[] = {1,2,3,4,5,6};
    struct splNode* head = getAList(arr, 6);
    cout<<"Original list::"<<endl;
    printList(head);
    //struct splNode* newHead = cloneUsingHashMap(head);
    struct splNode* newHead = clone(head);
    printList(newHead);
    return 0;
}