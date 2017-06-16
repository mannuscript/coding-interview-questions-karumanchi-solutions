#include<stdio.h>
#include<iostream>
#include<unordered_map>

#include"linkedList.h"
using namespace std;

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



int main(void)
{
    int arr[] = {10,123,14,534};
    HashedList hl(arr, 4);
    hl.printMap();
    struct node* newNode = hl.findNode(0);
    if(newNode)
        cout<<newNode->data<<endl;
    else
        cout<<"Node not found in the list!"<<endl;
    cout<<"#####################"<<endl;
    return 0;
}
