#include<iostream>

using namespace std;

void swap(char str[], int from, int to)
{
    char temp = str[from];
    str[from] = str[to];
    str[to] = temp;
}

void printAllPermutations(char str[], int fixedPointer)
{
    if(fixedPointer == strlen(str) - 1) {
        cout<<str<<endl;
    }
    char str2[strlen(str)];
    strcpy(str2, str);
    for(int i = fixedPointer; i < strlen(str); i++) {
        swap(str2, fixedPointer, i);
        printAllPermutations(str2, fixedPointer+1);
        swap(str2, fixedPointer, i);
    }
    
}

int main(void)
{
    char str[] = "Hello world";
    printAllPermutations(str, 0);
    return 0;
}