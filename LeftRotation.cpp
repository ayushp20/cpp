#include<iostream>

using namespace std;

int main()
{
         int size,n;
         cin>>size>>n;
         int a[size],temp,j;
          for(int i=0;i<size;i++)
            cin>>a[i];
         for(int i=0;i<n;i++)
         {   j=0;
             temp=a[j];
             for(j=0;j<size-1;j++)
                a[j]=a[j+1];
             a[size-1]=temp;

         }
         for(int i=0;i<size;i++)
            cout<<a[i]<<" ";





return 0;
}
