#include<iostream>
#define mod 1000000007

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        int w;
        cin>>w;

        if(w>8||w<-9)
        {
            cout<<0<<endl;
        }
        else
        {
            int combinations;
            if(w>=0)
                combinations=9-w;
            else
                combinations=w+10;


        long long int res=1;
        long long int y=N-2;
        long long int x=10;
        while(y>0)
        {

            if(y&1)
            {
                res=(res*x)%mod;
            }

            y=y>>1;
            x=(x*x)%mod;
        }
        res=(res*combinations)%mod;
        cout<<res<<endl;

        }
    }

    return 0;
}
