#include<iostream>
#include"Stacks.h"
#include<Stack>
using namespace std;

bool isHighPrecedence(char oprtr, char fromOprtr)
{
    /*
    Higher the class higer the precedence.
    Class 3: * /
    Class 2: + -
    Class 1: =
    */

    int oprtrClass = 0, fromOprtrClass = 0;
    if(strchr("*/", oprtr))
    {
        oprtrClass = 3;
    } else if(strchr("+-", oprtr)) {
        oprtrClass = 2;
    } else if(strchr("=", oprtr)) {
        oprtrClass = 1;
    }

    if(strchr("*/", fromOprtr))
    {
        fromOprtrClass = 3;
    } else if(strchr("+-", fromOprtr)) {
        fromOprtrClass = 2;
    } else if(strchr("=", fromOprtr)) {
        fromOprtrClass = 1;
    }

    if(oprtrClass > fromOprtrClass)
    {
        return true;
    }

    return false;
}

bool isClosingBracket(char c) {
    return (c == ')' || c == ']' || c =='}');
}

bool isOprtr(char oprtr)
{
    char oprtrList[] = "+-()*/[]{}";
    if(!strchr(oprtrList, oprtr)) {
        return true;
    } else {
        return false;
    }
}

char* infixToPostFix(char *infixNotation)
{
    int i = 0;
    stack <char> st;
    int strLen = strlen(infixNotation);
    char *postfixNotation = (char *)malloc(sizeof(char *)*strLen);
    int ptr = 0;

    while(*(infixNotation+i)) {
        char current = *(infixNotation+i);
        cout<<"processing:"<<current<<endl;
        if(isOprtr(current)) {
            cout<<"@@#@#@#@#@#@#@#@#@#@#@#@#@";
            //Check if Operator of low precedence (than the one at stack's top) 
            //appeared. pop stack until low/equal precedence operator appears
            while(isHighPrecedence(current, st.top()) && !st.empty()) {
                *(postfixNotation+ptr) = st.top();
                st.pop();
            }
            if(isClosingBracket(current)) {
                // ")" encountered, start poping operators from stack until 
                //"(" appears
                while(st.top() != '(' && !st.empty()) {
                    *(postfixNotation+ptr) = st.top();
                    st.pop();
                }
                if(st.empty()) {
                    perror("Invalid infix notation provided!");
                    return infixNotation;
                }
                //Remove '(' too
                st.pop();
            } else if(isHighPrecedence(current, st.top())) {
            }
            //Push into stack
            st.push(current);
        } else {
           *(postfixNotation+ptr) = current; 
        }
        i++;
    }
    while(!st.empty()) {
        *(postfixNotation+ptr) = st.top();
        st.pop();
    }
    return postfixNotation;
}


int main(void)
{
    char infixStr[] = "a+b";
    cout<<infixToPostFix(infixStr);
    return 0;
}