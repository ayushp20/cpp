#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    while(n--)
    {
        string u;
        cin>>u;

        for(int i=0;i<u.length()-1;i++)
        {
            if(u[i]=='c'&&u[i+1]=='h')
                {count++;break;}

            else if(u[i]=='h'&&u[i+1]=='e')
                {count++;break;}

            else if(u[i]=='e'&&u[i+1]=='f')
                {count++;break;}

        }
    }

    cout<<count<<endl;
    return 0;
}
