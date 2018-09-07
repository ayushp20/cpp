#include<bits/stdc++.h>
using namespace std;

int binaryKnapsack(int *val,int *wt,int W,int n)
{


    int memo[n+1][W+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(j==0||i==0)
                memo[i][j]=0;

            else if(wt[i-1]<=j)
                memo[i][j]=max(val[i-1]+memo[i-1][j-wt[i-1]],memo[i-1][j]);

            else
                memo[i][j]=memo[i-1][j];
        }
    }


    return memo[n][W];
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int W=7;
    int n=4;

    cout<<binaryKnapsack(val,wt,W,n)<<endl;
    return 0;
}
