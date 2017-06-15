#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;


struct node* getNthNode(struct node* head, int n)
{
    struct node* ptr = head;
    while(ptr && n) {
        n--;
        ptr = ptr->next;
    }
    if(!ptr && n) {
        cout<<"N is greater than the length of linked list!"<<endl;
        return NULL;
    }
    while(ptr) {
        ptr = ptr->next;
        head = head->next;
    }
    return head;
}

int main(int argc, char* argv[]){
    int arr[] = {1,2,3,4,5,6};
    struct node* head = getALinkedList(arr, 6);
    printList(head);
    struct node* nthNode = getNthNode(head, atoi(argv[1]));
    if(nthNode)
        cout<<nthNode->data<<endl<<"************"<<endl;
    return 0;
}