#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;

int myComp(pair<int,int> a,pair<int,int> b)
{
    return (a.first<b.first)?1:0;
}

int main()
{
    int n,d;
    long long int max_ff=0;
    cin>>n>>d;

    for(int i=0;i<n;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        a.push_back(make_pair(t1,t2));
        if(t2>max_ff)
            max_ff=t2;
    }

    sort(a.begin(),a.end(),myComp);

    long long int sum=0;

    for(int i=0;i<n;i++)
    {
        int j=i;
        sum=0;
        while(abs(a[i].first-a[j].first)<d&&j<n)
            sum+=(long long int)a[j++].second;


        if(sum>max_ff)
            max_ff=sum;
        if(j==n)
            break;
    }
    cout<<max_ff<<endl;
}
