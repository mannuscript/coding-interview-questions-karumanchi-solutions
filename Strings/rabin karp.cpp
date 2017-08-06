#include<iostream>

using namespace std;

#define d 256

//calcuate the rolling hash value
int getHash(int oldHash, int oldNum, int newNum, int q)
{
    return (d*(oldHash - oldNum) + newNum) % q;
}

int subString(char text[], char ptrn[], int q)
{
    int 
        textLen = strlen(text),
        ptrnLen = strlen(ptrn),
        textHash = 0,
        ptrnHash = 0,
        h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < ptrnLen-1; i++)
        h = (h*d)%q;
    
    //calculate ptrnhash and initial value of text hash
    for(int i = 0; i < ptrnLen; i++) {
        ptrnHash = getHash(ptrnHash, 0, *(ptrn+i), q);
        textHash = getHash(textHash, 0, *(text+i), q);
    }

    cout<<"hash values: "<<ptrnHash<<" "<<textHash<<endl;
    for(int i = 0; i <= textLen - ptrnLen; i++) {
        if(textHash == ptrnHash) {
            //Hash mached, start matching the substring matching
            int 
                j = 0, 
                ptr = i;

            for(;j < ptrnLen; j++, ptr++) {
                cout<<"Comparing: "<<*(ptrn+j)<<" "<< *(text + ptr)<<endl;
                if(*(ptrn+j) != *(text + ptr))
                    break;
            }
            if(j == ptrnLen)
                return i;
        }
        if ( i < textLen - ptrnLen )
        {
            textHash = getHash(textHash, *(text + i)*h, *(text + i), q);
            if (textHash < 0)
            textHash = (textHash + q);
        }
        cout<<"hash values for: "<<ptrnHash<<" "<<textHash<<endl;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    cout<<subString(argv[1], argv[2], 101)<<endl<<"#############";
    return 0;
}