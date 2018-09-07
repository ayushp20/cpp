#include<iostream>
using namespace std;

void insert(int a[],int n)
{
    if(n==1)
        return;

    insert(a,n-1);

    int v=a[n-1];
    int j=n-2;
    while(j>=0&&v<a[j])
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=v;
}


int main()
{
    int a[]={10,2,45,56,12,23,98,87,65,23},i;
    insert(a,10);
      for(i=0;i<sizeof(a)/sizeof(int);i++)
        cout<<a[i]<<" ";

    return 0;
}
