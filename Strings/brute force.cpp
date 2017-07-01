#include<iostream>

using namespace std;

int isSubstring(char str1[], char str2[])
{
    int n = strlen(str1);
    int m = strlen(str2);

    if(m > n)
        return -1;
    
    for(int i = 0; i < n; i++) {
        int j = 0;
        int ptr = i;
        for(j = 0; j < m && ptr < n ; j++, ptr++) {
            //cout<<"Comparing "<<*(str1 + ptr)<<" with "<<*(str2+j)<<" "<<endl;
            if(*(str1+ptr) != *(str2+j)) {
                //cout<<"breaking"<<endl;
                break;
            }
        }
        if(j == m)
            return i;
    }
    return -1;
}

int main()
{
    char str[] = "hello world!";
    char str2[] = "world";
    cout<<isSubstring(str,str2)<<endl<<"########################";
    return 0;
}