#include<iostream>

using namespace std;


/*
 * How it works:
 * Size of a subset is 2^n , where n is the size of set
 * E.g. set = {a,b,c}
 * power set: {}, {a}, {b}, {c}, {a,b}, {a,c}, {b,c}, {a,b,c}
 * when the representation is in terms of 2^n, we should take the hint of using 
 * binary representation. i.e.:
 * Following power set can be represented as:
 * 0 0 0 {}
 * 0 0 1 {a}
 * 0 1 0 {b}
 * 0 1 1 {a,b}
 * 1 0 0 {c}
 * 1 0 1 {a,c}
 * 1 1 0 {b,c}
 * 1 1 1 {a,b,c}
 * We just have to iterate from 0 (000) to 2^n (111) and 
 * use the bits to decide the subset (use another O(n) loop for this)
 * :) that easy
 */
void printPowerSet(char *arr, int n) 
{
    int powersetSize = 1 << n; //2 to the power n
    for(int i=0; i < powersetSize; i++) {
        cout<<"{";
        for(int j=0; j < n; j++) {
            //find if jth bit is set in i
            if(i & (1 << j)) {
                cout<<arr[j]<<", ";
            }
        }
            cout<<" }"<<endl;
    }
}

int main(void)
{
    char arr[] = {'a','b','c','d','e'};
    printPowerSet(arr, 5);
    return 0;
}