#include<iostream>
#include"Stacks.h"
#include<stack>
using namespace std;

char* infixToPostFix(char *infixNotation)
{
    int i = 0;
    stack <char> st;
    int strLen = strlen(infixNotation);
    char *postfixNotation = (char *)malloc(sizeof(char *)*strLen);
    int ptr = 0;

    while(*(infixNotation+i)) {
        char current = *(infixNotation+i);
        //cout<<"processing:"<<current<<endl;
        if(isOprtr(current)) {
            if(isOpeningBracket(current)) {
                *(postfixNotation+ptr) = st.top();
                ptr++;
                st.pop();
            }
            //Check if Operator of low precedence (than the one at stack's top) 
            //appeared. pop stack until low/equal precedence operator appears
            while(!st.empty() && (isHighPrecedence(st.top(), current) 
                    || (isClosingBracket(current) && !isOpeningBracket(st.top())))) {
                *(postfixNotation+ptr) = st.top();
                ptr++;
                st.pop();
            }
            if(isClosingBracket(current) && isOpeningBracket(st.top())) {
                //Remove '(' too
                st.pop();
            } else {
                st.push(current);
            }
        } else {
           *(postfixNotation+ptr) = current; 
           ptr++;
        }
        i++;
    }
    while(!st.empty()) {
        //cout<<endl<<"popping: "<<st.top();
        *(postfixNotation+ptr) = st.top();
        ptr++;
        st.pop();
    }
    *(postfixNotation+ptr) = '\0';
    return postfixNotation;
}


int main(void)
{
    char infixStr[] = "A+B*C+D";
    cout<<infixToPostFix(infixStr)<<endl<<"######################";
    return 0;
}