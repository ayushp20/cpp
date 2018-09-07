#include<bits/stdc++.h>
using namespace std;

void fib(int n)
{
    int memo[n+1];
    memo[0]=0;memo[1]=1;

    for(int i=2;i<=n;i++)
        memo[i]=memo[i-1]+memo[i-2];

    cout<<memo[n];

}


int main()
{
    int n;
    cin>>n;
    fib(n);
    return 0;
}

