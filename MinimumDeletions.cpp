#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(a==0)
        return b;

    return gcd(b%a,a);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        int tmp=a[0];

        for(int i=1;i<n;i++)
        {
            tmp=gcd(a[i],tmp);
            if(tmp==1)
                break;
        }

        if(tmp==1)
            cout<<"0"<<endl;
        else
            cout<<"-1"<<endl;

    }

    return 0;
}
