#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k,temp;
        cin>>n>>k;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(m.find(temp)==m.end())
                m.insert(make_pair(temp,1));
            else
                m[temp]++;
        }

     long long sum=0;
     bool gotIt=false;
     unordered_map<int,int>::iterator it;
     for(it=m.begin();it!=m.end();it++)
     {
         temp=it->second;

         if(temp==k){
            sum+=(long long)it->first;
            gotIt = true;
         }

     }
      if(gotIt==false)
        cout<<"-1"<<endl;
      else
        cout<<sum<<endl;
    }


    return 0;
}
