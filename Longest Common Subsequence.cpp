#include<bits/stdc++.h>
using namespace std;

int LCS(string str1,string str2,int n,int m)
{
    int memo[n+1][m+1];

    //Building Bottom Up
    for(int i=0;i<n+1;i++)
        for(int j=0;j<m+1;j++)
            {
                if(i==0||j==0)
                    memo[i][j]=0;
                else if(str1[i-1]==str2[j-1])
                    memo[i][j]=memo[i-1][j-1]+1;
                else
                    memo[i][j]=max(memo[i][j-1],memo[i-1][j]);

            }
    return memo[n][m];
}

int main()
{
    string str1,str2;
    cout<<"Enter String 1 : ";
    cin>>str1;
    cout<<"Enter String 2 : ";
    cin>>str2;

    cout<<"Longest Common Subsequence Length = "<<LCS(str1,str2,str1.length(),str2.length());
    return 0;
}
