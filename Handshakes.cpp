#include<iostream>

using namespace std;

int C[50][50]={};

int nCr(int n,int r)
{
C[0][0]=1;
    if(r>(n-r))
        r=(n-r);
    if(C[n][r]!=0)
        return C[n][r];

    for(int i=1;i<n;i++)
        for(int j=min(i,r);j>0;j++)
            C[j]=C[j]+C[j-1];

    return C[n][r];
}



int main()
{
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++)
    {
        int N,R;
        cin >> N>>R;

        cout<<nCr(N,R)<<endl;

    }
}
