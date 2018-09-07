#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int side=sqrt(n);
    int sq=side*side;

    if(sq==n)
        cout<<side*4;
    else
    {
        long long int row=n/side;
        long long int perimeter=2*(row+side);

        if(n%side!=0)
            perimeter+=2;

        cout<<perimeter;
    }


   return 0;
}

