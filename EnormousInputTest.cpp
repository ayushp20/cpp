#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t,k,ans=0;
    cin>>t>>k;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%k==0)
            ans++;

    }
    cout<<ans;
    return 0;
}
