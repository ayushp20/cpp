#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    double bal,withdraw;
    cin>>withdraw>>bal;
    cout<<fixed<<setprecision(2);

    if(fmod(withdraw,5)==0&&withdraw<=(bal-0.50))
    {
        bal-=withdraw+0.5;
        cout<<bal;
    }
    else
        cout<<bal;

    return 0;
}
