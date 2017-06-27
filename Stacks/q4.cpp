#include<iostream>
#include"Stacks.h"
#include<stack>
using namespace std;

int evalInfixUsingStack(char *str)
{
    stack <int> operandsStack;
    stack <char> operatorsStack;
    int i;

    while(*(str+i))
    {
        char current = *(str+i);
        //cout<<"processing:"<<current;
        if(isOprtr(current)) {

            if(isOpeningBracket(current)) {
                operatorsStack.push(current);
                i++;
                continue;
            }

            while(!operatorsStack.empty() && (isHighPrecedence(operatorsStack.top(), current) || 
                (isClosingBracket(current) && !isOpeningBracket(operatorsStack.top())))) {
                
                int operand1 = operandsStack.top();
                operandsStack.pop();
                int operand2 = operandsStack.top();
                operandsStack.pop();

                char oprtrToEval = operatorsStack.top();
                operatorsStack.pop();

                operandsStack.push(
                    performOperation(oprtrToEval, operand2, operand1)
                );
            }

            if(isClosingBracket(current) && isOpeningBracket(operandsStack.top())) {
                //Remove '(' too
                operandsStack.pop();
            } else {
                operandsStack.push(current);
            }

        } else {
            cout<<"pushing in operators:  "<<current - '0'<<endl;
            operandsStack.push(current - '0');
        }
        i++;
    }
    cout<<endl<<"#######################";
    operandsStack.pop();
    
    cout<<"#######################"<<endl;
    //cout<<endl<<endl<<operatorsStack.size()<<"------"<<operandsStack.size()<<endl;
    // while(!operatorsStack.empty()) {
    //     int operand1 = operandsStack.top();
    //     operandsStack.pop();
    //     int operand2 = operandsStack.top();
    //     operandsStack.pop();

    //     char oprtrToEval = operatorsStack.top();
    //     operatorsStack.pop();

    //     operandsStack.push(
    //         performOperation(oprtrToEval, operand2, operand1)
    //     );
    // }
   // int data = operandsStack.top();
    //operandsStack.pop();
    //return data;
}

int main(void)
{
    char str[] = "1*2+6";
    cout<<"Result:"<<evalInfixUsingStack(str)<<endl;
    return 0;
}