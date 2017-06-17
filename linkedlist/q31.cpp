#include<stdio.h>
#include<iostream>
#include"linkedList.h"
using namespace std;

/*
 * Using a stack
 * O(N),O(N)
 */
bool isPalindrome(struct node* head)
{
    if(!head)
        return 0;

    struct node* fastPtr = head;
    struct node* slowPtr = head;
    int len = getLength(head);
    Stack s;

    while(fastPtr && fastPtr->next)
    {
        s.push(slowPtr->data);
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    //If length is odd, skip one node
    if(len%2 != 0)
        slowPtr = slowPtr->next;

    while(slowPtr)
    {
        if(slowPtr->data != s.pop()->data)
            return false;
        slowPtr = slowPtr->next;
    }

    return true;
}

/*
 * Using Recurrsion
 * O(N),O(1)
 */
bool isPalindromeOptimized(struct node* head)
{
    struct node* middleNode = getMiddleNode(head);
    struct node* temp;
    struct node* headPtr = head;
    bool palindromeFlag = true;

    middleNode->next = reverseLinkedList(middleNode->next);
    printList(head);

    temp= middleNode->next;

    while(temp)
    {
        if(head->data != temp->data)
        {
            palindromeFlag = false;
            break;
        }
        head = head->next;
        temp = temp->next;
    }

    middleNode->next = reverseLinkedList(middleNode->next);
    printList(headPtr);
    return palindromeFlag;
}

int main(void)
{
    int arr[] = {1,2,3,4,4,3,2,0};
    struct node* head = getALinkedList(arr, 8);
    cout<<"Palindrome found: "<<isPalindromeOptimized(head)<<endl;
    cout<<"####################"<<endl;
    return 0;
}