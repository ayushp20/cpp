#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        cin>>a[0];
        long long int res=(long long int)a[0];
        for(int i=1;i<n;i++)
            {
                cin>>a[i];
                res=res^(long long int)a[i];
            }
        cout<<(long long int)(2*res)<<endl;
    }

    return 0;
}
