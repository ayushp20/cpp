#include<bits/stdc++.h>
using namespace std;

const int N=2e6;
int t[2*N];
int n;
void build()
{
    for(int i=n-1;i>0;i--)
        t[i]=min(t[2*i+1],t[2*i]);
}

void modify(int idx,int value)
{
    t[idx+=n]=value;

    for(idx/=2;idx>1;idx/=2)
        t[idx]=min(t[2*idx],t[2*idx+1]);
}

int query(int l,int r) //[L,R)
{
    int minimum=INT_MAX;

    l+=n; r+=n;

    while(l<r)
    {
        if(l&1)
        {
            minimum=min(minimum,t[l]);
            l++;

        }
        if(r&1)
        {
            --r;
            minimum=min(minimum,t[r]);
        }
        l=l/2;
        r=r/2;
    }

    return minimum;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>t[i+n];
    }

    build();
    modify(3,7);
    cout<<query(1,5);

}
