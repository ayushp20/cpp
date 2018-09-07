#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{

    int n,m;
    const int Max=500;
    unsigned long long grid[Max+1][Max+1],routes;

   for(int i=0;i<=Max;i++)
    {
        for(int j=0;j<=Max;j++)
            grid[i][j]=0;
    }

    for(int i=Max;i>=0;i--)
        grid[Max][i]=1;


    for(int i=Max;i>=0;i--)
        grid[i][Max]=1;

    for(int i=Max-1;i>=0;i--)
    {
        for(int j=Max-1;j>=0;j--)
           {
             routes=(grid[i+1][j]%1000000007)+(grid[i][j+1]%1000000007);
            grid[i][j]=routes;
           }
    }

/*for(int i=0;i<=Max;i++)
{
    for(int j=0;j<=Max;j++)
        cout<<grid[i][j];
    cout<<endl;
}*/


    int tests;
    cin>>tests;
    while(tests--)
    {
    cin>>n>>m;

    cout<<grid[Max-n][Max-m]%1000000007<<endl;
    }

    return 0;
}
