#include <iostream>

using namespace std;

int main()
{
    long long n,m,a,b,k,max=0;
    cin>>n>>m;
    long long arr[n]={};

    for(long long i=0;i<m;i++)
    {
        cin>>a>>b>>k;
        for(long long j=a-1;j!=b;j++)
        {
            if(arr[j]==0)
                arr[j]=k;
            else
                arr[j]+=k;

            if (arr[j]>max)
                max=arr[j];
        }

    }
    cout<<max;
    return 0;
}
