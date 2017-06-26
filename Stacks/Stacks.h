#include<iostream>
#include<climits>
#include"../linkedlist/linkedList.h"

using namespace std;

class LLStack {
    protected:
        struct node* head;
        int length;
    public:
        LLStack(int *arr, int n)
        {
            this->head = NULL;
            this->length = 0;
            int i =0;
            while(n--)
            {
                this->push(*(arr+i++));
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

struct minMaxNode {
    int data;
    struct minMaxNode* next;
    struct minMaxNode* min;
    struct minMaxNode* max;
};

struct minMaxNode* getAMinMaxNode(int data)
{
    struct minMaxNode* newNode = (struct minMaxNode*)malloc(sizeof(struct minMaxNode));
    newNode->data = data;
    newNode->min = NULL;
    newNode->max = NULL;
    newNode->next = NULL;
    return newNode;
}

class LLStack_min_max: public LLStack
{
    private:
        struct minMaxNode* head;
    public:
        LLStack_min_max() : LLStack() 
        {}
        LLStack_min_max(int *arr, int len)
        {
            this->head = NULL;
            this->length = 0;
            int i =0;
            int data;
            while(len--)
            {
                data = *(arr+i++);
                this->push(data);
            }    
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
            struct minMaxNode* newNode = getAMinMaxNode(data);
            newNode->next = this->head;
            if(this->head)
            {
                if(this->head->min->data >= data)
                    newNode->min = newNode;
                else
                    newNode->min = this->head->min;
                
                if(this->head->max->data <= data)
                    newNode->max = newNode;
                else
                    newNode->max = this->head->max;
                
            } else {
                //First node
                newNode->min = newNode;
                newNode->max = newNode;
            }
            this->length++;
            this->head = newNode;
        }
        void printStack()
        {
            struct minMaxNode* ptr = this->head;
            while(ptr)
            {
                cout<<ptr->data<<"("<<ptr->min->data<<")("<<ptr->max->data<<") ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
};


class LLStack_min_max_optimized: public LLStack
{
    private:
        int min;
        int max;
    public: 
         LLStack_min_max_optimized():  LLStack(){
             this->min = INT_MAX;
             this->max = INT_MIN;
         }
         LLStack_min_max_optimized(int arr[], int n)
         {
            this->min = INT_MAX;
            this->max = INT_MIN;
            this->head = NULL;
            this->length = 0;
            int i =0;
            while(n--)
            {
                this->push(*(arr+i++));
            }
         }

        int pop()
        {
            if(!this->head)
            {
                cout<<"Empty stack!"<<endl;
                return NULL;
            }
            int data;
            if(this->head->data > this->min) {
                data = this->head->data;
            } else {
                this->min = this->head->data + 2*this->min;
                data = this->min;
            }
            this->head = this->head->next;
            this->length--;
            return data;
        }
        void push(int data)
        {
            struct node* newNode;
            if(data < this->min) {
                newNode = getANode(2*data - this->min);
                this->min = data;
            }
            else
                newNode = getANode(data);
            newNode->next = this->head;
            this->length++;
            this->head = newNode;
        }
        int getMin(void) 
        {
            return this->min;
        }
        void print(void)
        {
            struct node* ptr = this->head;

            while(ptr) {
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
};