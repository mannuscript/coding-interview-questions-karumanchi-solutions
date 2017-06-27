#include<iostream>
#include"Stacks.h"
#include<stdio.h>
#include<stack>
using namespace std;

bool isOprtr(char oprtr)
{
    char oprtrList[] = "+-*/";
    if(strchr(oprtrList, oprtr)) {
        return true;
    } else {
        return false;
    }
}

//Unary operators not allowed
//TODO: support unary operator
int evalPostfix(char *str)
{
    stack <int> st;
    int i = 0;
    while(*(str+i)) {
        if(isOprtr(*(str+i))) {
            //Get top two oprands
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(performOperation(*(str+i),b,a));
        } else {
            st.push(*(str+i) - '0');
        }
        i++;
    }
    int result = st.top();
    st.pop();
    return result;
    return 0;
}

int main(void)
{
    char str[] = "99+2*5-";
    cout<<endl<<evalPostfix(str)<<endl;
    return 0;
}