#include<bits/stdc++.h>
using namespace std;

#define MAX 1310730

int a[2*MAX];
int n;

void build()
{
    int op=1;
    int sz=n;
    for(int i=0;i<log2(n);i++,sz/=2)
    {
        if(op&1)
        {
            for(int j=sz-1;j>=sz/2;j--)
                a[j]=a[2*j+1]|a[2*j];

            op=0;
        }
        else
        {
            for(int j=2*i-1;j>=i;j--)
                a[j]=a[2*j+1]^a[2*j];

            op=1;
        }
    }
}

void modify(int i,int value)
{
    i=i+n-1;
    a[i]=value;

    int op=1;
    for(i/=2;i>0;i/=2)
    {
        if(op&1)
        {
            a[i]=a[2*i+1]|a[2*i];
            op=0;
        }
        else
        {
            a[i]=a[2*i+1]^a[2*i];
            op=1;
        }
    }
}

int main()
{
    int m;
    cin>>n>>m;
    n=pow(2,n);

    for(int i=0;i<n;i++)
        cin>>a[i+n];

    build();
    /*for(int i=0;i<2*n;i++)
        cout<<a[i]<<" ";*/

    while(m--)
    {
        int idx,value;
        cin>>idx>>value;
        modify(idx,value);

        /*for(int i=0;i<2*n;i++)
            cout<<a[i]<<" ";
        cout<<endl;*/
        cout<<a[1]<<endl;
    }

}
