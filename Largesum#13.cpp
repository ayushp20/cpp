#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    char temp[50];
    int sum[53]={};
    while(N--)
    {
     cin>>temp;

     for(int i=49, j=0;i>=0;i--,j++)
     {
         sum[j]+=(temp[i]);
         if(sum[j]>9)
         {
             sum[j+1]++;
             sum[j]=sum[j]%10;
         }
     }

    }
    int i,j=10;
   for(i=52;i>50;i--)
   {
       if(sum[i]!=0)
           break;
   }
    while(j--)
    {
        cout<<sum[i];
    }


    return 0;
}
