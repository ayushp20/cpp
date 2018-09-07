#include<bits/stdc++.h>

using namespace std;

struct data
{
    string str;
    int l,r;

    void insert(int b,int c,string s)
    {
        l=b;r=c;str=s;
    }
    void update(int b,int c)
    {
        if(b<l)
            l=b;
        if(c>r)
            r=c;
    }
};
int find_string(data obj[10],string s,int n)
{
    for(int i=0;i<n;i++)
        if(obj[i].str==s)
            return i;

    return 0;
}

int main()
{
    int n,m,k,p=0;
    cin>>n>>m>>k;
    unordered_map<string,int> a[m];
    data obj[10];
    for(int i=0;i<k;i++)
    {
        int bc,b,c;
        string s;
        cin>>bc>>b>>c>>s;

        int temp=(find_string(obj,s,p));
        if(!temp)
        {
            obj[p++].insert(b,c,s);
        }

        else
        {
            obj[temp].update(b,c);
        }
    }
    for(int i=0;i<p;i++)
        for(int j=obj[i].l-1;j<obj[i].r;j++)
            a[j].insert(make_pair(obj[i].str,1));

    int mx=1;
    int freq=0;
    for(int i=0;i<m;i++)
    {
        if((int)a[i].size()>mx){
            mx = (int)a[i].size();
            freq=1;

        }else if((int)a[i].size()==mx){
            freq+=1;
        }
    }

    cout<<freq<<" "<<mx+1<<endl;
    return 0;
}

