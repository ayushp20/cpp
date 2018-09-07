#include<iostream>

using namespace std;

int main()
{
    int Max=10000,carry,i;
    int sums[1001]={0},a[Max+1];

    for(i=0;i<=Max;i++)
        a[i]=-1;



    sums[0]=1;a[Max]=1;

    for(i=1;i<=1000;i++)
    {
        carry=0;
        for(int j=Max;a[j]!=-1;j--)
        {
            a[j]=a[j]*i+carry;

            carry=0;
            if(a[j]>9)
            {
                if(a[j-1]==-1)
                {
                    int temp=a[j];
                    while(temp>9)
                    {
                        a[j-1]=a[j]/10;
                        a[j]=a[j]%10;
                        temp/=10;
                        sums[i]+=a[j];
                        j--;
                    }
                    sums[i]+=a[j];
                    break;
                }
                else
                {
                    carry=a[j]/10;
                    a[j]%=10;
                }

            }
            sums[i]+=a[j];
        }
    }
    i=0;
    while(a[i]==-1)
        i++;
    cout<<Max-i<<endl;
     for(;i<=Max;i++)
        cout<<a[i];
    cout<<endl;

   for(i=0;i<=1000;i++)
        cout<<sums[i]<<" ";

        int test;
        cin>>test;
        while(test--)
        {
            int N;
            cin>>N;
            cout<<sums[N]<<endl;
        }


    return 0;
}
