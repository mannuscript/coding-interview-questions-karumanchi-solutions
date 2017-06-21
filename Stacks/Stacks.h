#include<iostream>
#include"../linkedlist/linkedList.h"

using namespace std;

class LLStack {
    private:
        struct node* head;
        int length;
    public:
        LLStack(int *arr, int n)
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
        LLStack()
        {
            this->length = 0;
            this->head = NULL;
        }
        int pop()
        {
            if(!this->head)
            {
                cout<<"Empty stack!"<<endl;
                return NULL;
            }
            int data = this->head->data;
            this->head = this->head->next;
            this->length--;
            return data;
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