#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int test,sq,max=0;
    string win_name;
    cin>>test;
    while(test--)
    {
        string name;
        int d,j;
        cin>>name>>d>>j;

        sq=j-d;
        if(sq>max)
        {
            win_name=name;
            max=sq;
        }

    }
    cout<<win_name<<" "<<max;
    return 0;
}
