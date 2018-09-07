#include<iostream>
using namespace std;

int main()
{
    string str="AAABABA";
    string strpat="AB";

    for(int i=0;i<=str.length()-strpat.length();i++)
    {
        int j;
        for(j=0;j<strpat.length();j++)
            if(strpat[j]!=str[i+j])
                break;


        if(j==strpat.length())
                    cout<<"Found at position "<<i+1<<endl;

    }
return 0;
}
