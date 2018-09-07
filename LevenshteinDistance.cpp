#include<bits/stdc++.h>
using namespace std;

int editDistance(string a,string b)
{
    int n=a.length();
    int m=b.length();
    int dp[n+1][m+1];

    for(int i=0;i<n+1;i++)
        for(int j=0;j<m+1;j++)
        {
            if(i==0)
                dp[i][j]=j;

            else if(j==0)
                dp[i][j]=i;

            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];

            else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
        }
        for(int i=0;i<n+1;i++)
        {

        for(int j=0;j<m+1;j++)
            cout<<dp[i][j]<<" ";

            cout<<endl;
        }

        return dp[n][m];
}

int main()
{
    string a="sunday";
    string b="saunday";

    cout<<"Minimum No. of processes required to convert "<<a<<" to "<<b<<" is = "<<editDistance(a,b);
    return 0;
}
