#include<iostream>
#include"Stacks.h"

using namespace std;

bool isValidExpression(char *str)
{
    int i = 0;
    LLStack st;
    while(*(str+i)) {
        if(*(str + i) == '{' || *(str + i) == '[' || *(str + i) == '(')
            st.push(*(str+i));
        else if(*(str + i) == '}' || *(str + i) == ']' || *(str + i) == ')')
        {
            //st.printStack();
            char fromStack = st.pop();
            char comparator;
            switch(*(str+i))
            {
                case '}' : comparator = '{';
                            break;
                case ')' : comparator = '(';
                            break;
                case ']' : comparator = '[';
                            break;
            }
            if(fromStack != comparator)
            {
                return false;
            }
        }
        i++;
    }
    if(st.getLength())
        return false;
    return true;
}

int main(void)
{
    char* str = "1+2*(3+b)+[{}]{];";
    cout<<isValidExpression(str)<<endl<<"################"<<endl;
    return 0;
}