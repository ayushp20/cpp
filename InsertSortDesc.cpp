#include<iostream>
using namespace std;

int main()
{
int a[10]={15,45,56,67,78,9,3,5,7,100},v,j;

for(int i=8;i>=0;i--)
{
    v=a[i];
    for(j=i+1;j<=9&&v<a[j];j++)
    {
        a[j-1]=a[j];
    }
    a[j-1]=v;
}
for (int i=0;i<10;i++)
     cout<<" "<<a[i];
return 0;
}
