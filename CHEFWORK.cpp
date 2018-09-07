#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int coins[N],type[N];
    for(int i=0;i<N;i++)
        cin>>coins[i];
    for(int i=0;i<N;i++)
        cin>>type[i];

    int min1=100001,min2=100001,min3=100001;

    for(int i=0;i<N;i++)
    {
        if(type[i]==1)
        {
            if(coins[i]<min1)
                min1=coins[i];
        }

        else if(type[i]==2)
        {
            if(coins[i]<min2)
                min2=coins[i];
        }
        else
        {
            if(coins[i]<min3)
                min3=coins[i];
        }
    }

    cout<<min((min1+min2),min3)<<endl;
    return 0;
}
