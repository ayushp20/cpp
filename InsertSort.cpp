#include<iostream>
using namespace std;

int main()
{
    int a[10]={20,45,12,56,78,98,45,67,34,53},t,j;

    for(int i=1;i<10;i++)
    {   t=a[i];
        for(j=i-1;j>=0&&t<a[j];j--)
        {
                a[j+1]=a[j];
        }

    a[j+1]=t;
    }

    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    return 0;
}
