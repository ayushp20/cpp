#include<bits/stdc++.h>
using namespace std;


int getMinSteps(int n)
{
    int memo[n+1];

    memo[1]=0;
    for(int i=2;i<=n;i++)
    {
        memo[i]=1+memo[i-1];
        if(n%2==0)memo[i]=min(memo[i],1+memo[i/2]);
        if(n%3==0)memo[i]=min(memo[i],1+memo[i/3]);
    }
    return memo[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<getMinSteps(n);

    return 0;
}
