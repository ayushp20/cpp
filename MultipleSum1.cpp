#include<iostream>
using namespace std;
int main()
{
int t,n;
cin>>t;
for(int i=0;i<t;i++)
{
    cin>>n;int sum=0;
    for(int j=3;j<n;j++)
    {
        if(j%3==0||j%5==0)
            sum+=j;
    }
    cout<<sum<<endl;
}
return 0;
}

