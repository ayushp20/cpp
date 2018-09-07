#include<bits/stdc++.h>
using namespace std;
int Lis(int *a,int n)
{
    int memo[n],max;
    for(int i=0;i<n;i++)
        memo[i]=1;
    for(int i=1;i<n;i++)
    {
        max=0;
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
                if(memo[j]>max)
                    max=memo[j];

        memo[i]=max+1;
    }
    max=0;
    for(int i=0;i<n;i++)
        if(memo[i]>max)
            max=memo[i];
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        if(memo[i]==(max-count))
        {
            count++;
            cout<<a[i]<<"<-";
        }
    }
   return max;

}
int main()
{
    cout<<"\nEnter Size : ";
    int n;cin>>n;
    cout<<"\nEnter Values : ";
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<endl<<"Max LIS = "<<Lis(a,n);
    return 0;
}
