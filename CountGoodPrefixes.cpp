#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;int N;
        cin>>s>>N;
        int n=s.size();
        int a[n],b[n],flag=0,noa=0,nob=0;
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
                noa++;

            else
                nob++;

            a[i]=noa;
            b[i]=nob;

        }
        //cout<<noa<<" "<<nob<<endl;

        int maxa=0,maxb=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<n;j++)
        {
            if(j==0)
                if(a[j]>b[n-1])
                {
                    ans+=n*(N-i);
                    flag=1;
                    break;
                }

                else if(b[j]>a[n-1])
                {
                    flag=1;
                    break;
                }

            if((a[j]+maxa)>(b[j]+maxb))
                ans++;


        }
            maxa+=a[n-1];
            maxb+=b[n-1];
        //cout<<ans<<endl;
        if(flag==1)
            break;
        }

        cout<<ans<<endl;
        }
    return 0;
}
