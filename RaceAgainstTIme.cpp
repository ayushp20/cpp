#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int h_curr,heights[n-1],time=1,cost=0;
    long long price[n-1];

    cin>>h_curr;

    for(int i=0;i<n-1;i++)
        cin>>heights[i];

    for(int i=0;i<n-1;i++)
        cin>>price[i];


    for(int i=0;i<n-1;i++)
    {
        //Height Greater than Pass
        if(heights[i]>h_curr)
        {
            time+=(heights[i]-h_curr);
            cost+=price[i];
            h_curr=heights[i];
        }


        time++;
    }

    cout<<time+cost<<endl;



    return 0;
}

