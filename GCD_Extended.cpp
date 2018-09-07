#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

/*int gcde(int a,int b)

{
    if(a==0)
        return b;

    int g=gcde(b%a,a);

    return g;
}*/

int gcd(int a,int b,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }

    int x1,y1;
    int g=gcd((b%a),a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;

    return g;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int x,y;
    int g=gcd(a,b,&x,&y);

    cout<<endl<<"gcd is "<<g<<endl<<"x= "<<x<<" y = "<<y;

    return 0;
}
