#include<iostream>
#include"Stacks.h"
#include<stack>
using namespace std;

bool isPalindrome(char str[])
{
    int i = 0;
    stack <char> st;

    while(*(str+i) && *(str+i) != 'X') {
        st.push(*(str+i));
        i++;
    }
    //Check if the string doesnt contain X at all
    if(!*(str+i))
        return false;
    
    i++;
    
    printSTLStack(st);

    while(*(str+i) || !st.empty() ) {
        if(!*(str+i))
            return false;
        if(st.empty())
            return false;
        if(*(str+i) != st.top())
            return false;
        //printSTLStack(st);
        i++;
        st.pop();
    }
    return true;
}

int main(void)
{
    char str[] = {'a','b','a','X','a', 'b', 'a', '\0'};
    cout<<isPalindrome(str)<<endl<<"###############";
    return 0;
}