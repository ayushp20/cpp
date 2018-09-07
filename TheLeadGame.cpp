#include<iostream>
using namespace std;

int main()
{
    int n,maxlead=0,winner=0,p1=0,p2=0;
    cin>>n;
    while(n--)
    {
        int si,ti,lead;
        cin>>si>>ti;
        p1+=si;
        p2+=ti;
        if(p1>=p2)
        {
            lead=p1-p2;
            if(lead>maxlead)
                {
                    maxlead=lead;
                    winner=1;
                }
        }
        else
        {
            lead=p2-p1;
            if(lead>maxlead)
                {
                    maxlead=lead;
                    winner=2;
                }

        }
    }
    cout<<winner<<" "<<maxlead<<endl;

    return 0;
}
