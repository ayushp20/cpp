#include<iostream>
using namespace std;

int maxval(int a,int b,int arr[])
{
    int maxelement=0;
    for(int i=a;i<=b;i++)
    {
        if(arr[i]>maxelement)
            maxelement=arr[i];
    }
    return maxelement;
}


int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    {
        int TotalRows;
        cin>>TotalRows;

        int FinalSums[TotalRows];
        cin>>FinalSums[0];
        for(int i=1;i<TotalRows;i++)
        {
            int Current[i+1];
            for(int j=0;j<=i;j++)
            {
                int x;
                cin>>x;

                if(j==0)
                    Current[0]=x+FinalSums[0];
                else if(j==i)
                    Current[i]=x+FinalSums[i-1];

                else
                    Current[j]=x+maxval(j-1,j,FinalSums);

            }

            for(int j=0;j<=i;j++)
                FinalSums[j]=Current[j];

            for(int j=0;j<=i;j++)
                cout<<FinalSums[j]<<" ";
            cout<<endl;
        }
        cout<<"Max Sum of Paths = "<<maxval(0,TotalRows-1,FinalSums);
    }
    return 0;
}
