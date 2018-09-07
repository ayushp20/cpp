#include<iostream>
#include<stdlib.h>

using namespace std;
int peak(int a[][6])
{
    int i,j,temp;

    for(i=0,j=2;i<6&&j<6;i++)
    {

    if(a[i][j]>=a[i+1][j]&&a[i][j]>=a[i-1][j])
    {
        if(a[i][j]>=a[i][j+1]&&a[i][j]>=a[i][j-1])
            return a[i][j];
    }
    }
}
int main()
{
    int a[6][6];

    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            a[i][j]=rand();
    for(int i=0;i<6;i++)
    {
        cout<<endl;
        for(int j=0;j<6;j++)
            cout<<a[i][j]<<"\t";
    }

    int p=peak(a);
    cout<<endl<<p;

    return 0;
}
