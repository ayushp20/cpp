#include <iostream>
#include<cstring>

using namespace std;

int main()
{
    int n,q,sum;
    cin>>n;
    char s[n][20];

    for(int i=0;i<n;i++)
        cin>>s[i];

    cin>>q;
    char qs[q][20];
      for(int i=0;i<q;i++)
        cin>>qs[i];

    for(int i=0;i<q;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
            if(strcmp(s[j],qs[i])==0)
                sum++;

        cout<<sum<<endl;
    }

        return 0;
}

