#include<iostream>
using namespace std;

unsigned long int nCr(int n,int r)
{
    unsigned long int res=1;

    if(r>n-r)
        r=n-r;

    for(int i=0;i<r;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }

    return res;
}
void generateCatalan(int n)
{
    //Cn = 2nCn/(n+1)

    unsigned long int C=nCr(2*n,n);

    cout<<C/(n+1)<<" ";

}

int main()
{
    int n;
    cin>>n;
    generateCatalan(n);
    return 0;
}
