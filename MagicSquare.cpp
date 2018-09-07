#include<iostream>
#include<cstring>
using namespace std;

void magicSquare(int n)
{
    int matrix[n][n],i=n/2,j=n-1;
    memset(matrix,0,sizeof(matrix));

    for(int count=1;count<=n*n;)
    {
        if(i==-1&&j==n)
        {
            i=0;
            j=n-2;
        }
        else
        {
            if(i==-1)
                i=n-1;
            if(j==n)
                j=0;
        }

        if(matrix[i][j]==0)
        {
            matrix[i][j]=count++;

            i--;
            j++;
        }
        else
        {
            j-=2;
            i+=1;
        }
    }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                cout<<matrix[i][j]<<" ";

        cout<<endl;}
}

int main()
{

    int n;
    cin>>n;

    magicSquare(n);

    return 0;
}
