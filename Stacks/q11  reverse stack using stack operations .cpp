#include<iostream>
#include"Stacks.h"

using namespace std;

void insert(LLStack *st, int data)
{
    if(!st->getLength())
    {
        st->push(data);
        return;
    }
    int storage = st->pop();
    insert(st,data);
    st->push(storage);
}

void reverseStack(LLStack *st)
{
    if(!st->getLength())
        return;
    int data = st->pop();
    reverseStack(st);
    insert(st, data);
}

int main(void)
{
    int arr[] = {1,2,3,4,5};
    LLStack st(arr,5);
    st.printStack();
    reverseStack(&st);
    st.printStack();
    return 0;
}