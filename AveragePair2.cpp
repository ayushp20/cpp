#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long res=0;
        int a[n];
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;

        for(int i=0;i<n;i++)
            {
                cin>>a[i];
                it=m.find(a[i]);
                if(it==m.end())
                {
                    m.insert(make_pair(a[i],1));
                }
                else
                {
                    m[a[i]]++;
                }

            }

        for(int i=0;i<(int)m.size();i++)
            for(int j=0;j<(int)m.size();j++)
            {

            }


        cout<<res<<endl;
    }
    return 0;
}
