#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ones=0;
    int i=0;
    while(s[i]=='1')i++;
    ones =i;
    int zeros = (int)s.size() - ones;

    if(ones==1)
    {
        cout<<s<<" 0"<<endl;
    }
    else
    {
        string f((int)s.size()+1,'0');
        f[0]='1';
        string F(zeros+1,'0');
        F[0]='1';
        cout<<f<<" "<<F<<endl;
    }



    return 0;
}
