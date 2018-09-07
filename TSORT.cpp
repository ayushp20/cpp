#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin>>t;
    int k=t;
    int a[t],i=0;
    while(k--)
        cin>>a[i++];

    sort(a,a+t);

    for(i=0;i<t;i++)
        cout<<a[i]<<"\n";

    return 0;
}
