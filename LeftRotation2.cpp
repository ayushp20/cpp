#include<iostream>

using namespace std;

int main()
{
         int size,n;
         cin>>size>>n;
         int a[size],temp,j;
          for(int i=0;i<size;i++)
            cin>>a[i];
        if(n>=size)
            n=n%size;
        for(int i=n;i<size;i++)
            cout<<a[i]<<" ";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";



return 0;
}

