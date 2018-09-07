#include<bits/stdc++.h>
using namespace std;

void printCombination(int parent[],int coins[],int total)
{
    if(parent[total]==-1)
        cout<<"No Possible Combination";

    else
    {
        int start=total;

        while(start!=0)
        {
            int j=parent[start];


            cout<<coins[j]<<" ";

            start-=coins[j];
        }
        cout<<endl;
    }
}
int coinChange(int coins[],int total,int n)
{
    int T[total+1],parent[total+1];
    memset(parent,-1,sizeof(parent));

    for(int i=0;i<total+1;i++)
        T[i]=INT_MAX-total;

    T[0]=0;

    for(int i=0;i<n;i++)
        for(int j=1;j<total+1;j++)
            if(j>=coins[i])
                   if(1+T[j-coins[i]]<T[j])
                   {
                       T[j]=1+T[j-coins[i]];
                       parent[j]=i;
                   }

    printCombination(parent,coins,total);
    return T[total];
}


int main()
{
    int total=13,n=4;
    int coins[]={7,2,3,6};

    cout<<"Minimum Coins Needed = "<<coinChange(coins,total,n)<<endl;

    return 0;
}
