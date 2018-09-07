#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,min_value=INT_MAX;
    cin>>n>>m;
    int a[m];

    for(int i=0;i<m;i++)
        cin>>a[i];

    sort(a,a+m);

    for(int i=0;i<=m-n;i++)
    {
        int diff=a[i+n-1]-a[i];
        if(diff<min_value)
            min_value=diff;
    }


    cout<<min_value<<endl;

    return 0;
}
