#include<iostream>
#include<vector>

using namespace std;


int main()
{
    int ch;
    long long n,q,x,y,lastAnswer=0;

    cin>>n>>q;
    vector <vector<long long> >a(n);
    for(int i=0;i<q;i++)
    {
        cin>>ch>>x>>y;
        if(ch==1)
        {
            a[((lastAnswer^x)%n].push_back(y);
        }
        else if (ch==2)
        {
            lastAnswer= a[((lastAnswer^x)%n][(int)y%(int)( a[((lastAnswer^x)%n]%n].size())];
            cout<<lastAnswer<<endl;
        }
    }

    return 0;
}
