#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findmin(vector<int>v)
{
    int min=v[0];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<min)
            min=v[i];
    }
    return min;
}

int main() {

    int n,q,d;
    cin>>n>>q;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    while(q--)
    {
        cin>>d;
        int min;
        vector <int> maxm(n-(d-1));
        for(int k=0;k<n-(d-1);k++)
        {
            int maxf=v[k];
            for(int i=k+1;i<k+d;i++)
            {
                if(v[i]>maxf)
                   maxf=v[i];
            }
            maxm[k]=maxf;

        }
        min=findmin(maxm);
        cout<<min<<endl;
    }
    return 0;
}
