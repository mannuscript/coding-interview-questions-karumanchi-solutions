#include<iostream>
#include"Stacks.h"

using namespace std;


int main(void)
{
    int arr[] = {5,14,3,2,10};
    //LLStack_min_max st(arr,5);
    //st.printStack();

    LLStack_min_max_optimized st3(arr,5);
    st3.printStack();
    //cout<<st3.getMin();
    cout<<st3.pop()<<endl;
    cout<<st3.pop()<<endl;
    cout<<st3.pop()<<endl;
    cout<<st3.pop()<<endl;
    cout<<st3.pop()<<endl;
    return 0;
}