#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,ch;
    stack <string> s;
    cin>>n;
    string str,temp;
    while(n--)
    {
        cin>>ch;
        if(ch==1)
        {//First element of stack should be empty string.
                cin>>temp;
                s.push(str);
                str = str+temp;

            }

        else if(ch==2)
        {
            int del,j;
            cin>>del;
            s.push(str);
            str.erase(str.length()-del);

        }
        else if(ch==3)
        {
            int k;
            cin>>k;
            cout<<str[k-1]<<endl;
        }
        else
        {
            if(!s.empty())
            {
                str=s.top();
                s.pop();
            }
            else
                str="";
        }
    }
    return 0;
}

