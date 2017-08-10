#include<iostream>
#include"Trees.h"

int getHeight(int *parentArray, int length)
{
    int 
        maxHeight = 0;

    for(int i=0 ; i < length; i++) {
        int nextIndex = i;
        int currentHeight = 0;
        while(parentArray[nextIndex] != -1) {
            currentHeight++;
            nextIndex = parentArray[nextIndex];
        }
        if(currentHeight > maxHeight)
            maxHeight = currentHeight;
        cout<<"Max height after "<<i<<"th iteration is: "<<maxHeight<<endl;
    }
    return maxHeight;
}

int main(void)
{
    int parentArray[] = {-1, 0, 1, 1, 1, 1, 3, 3, 5, 5};
    cout<<"Depth of the tree is: "<<getHeight(parentArray, 10)<<endl;
    return 0;
}