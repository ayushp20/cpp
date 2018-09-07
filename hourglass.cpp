#include<iostream>
using namespace std;
int main()
{
    int a[6][6];
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            a[i][j]=i+1;

    for(int i=0;i<6;i++)
    {
        cout<<endl;
        for(int j=0;j<6;j++)
            cout<<a[i][j]<<" ";
    }
    int sum,maxsum=-9999;

    for(int k=0;k<4;k++)
      {
        for(int l=0;l<4;l++)
        {   sum=0;

            for(int i=k;i<k+3;i++){
                for(int j=l;j<l+3;j++)
                  {
                    if(i==k+1)
                      {
                         sum+=a[i][j+1];
                         break;
                      }
                    else
                        sum+=a[i][j];
                  }}
            if (sum>maxsum)
                maxsum=sum;

        }

      }
      cout<<endl<<maxsum;
    return 0;

}
