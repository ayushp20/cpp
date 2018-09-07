#include<iostream>
using namespace std;

int main()
{
    int Max=100;
    int prev1[Max+1]={0},prev2[Max+1]={0},digits=1,pos[Max+1],*prev1ptr=&prev1[0],*prev2ptr=&prev2[0],*ansptr;
    prev1[Max]=prev2[Max]=1;
    for(int i=3;digits<=Max;i++)
    {   cout<<i<<" "<<digits<<endl;

        int ans[Max+1]={0};ansptr=&ans[0];
        for(int j=Max;ans[j]!=0;j--)
        {
            ansptr[j]=prev1ptr[j]+prev2ptr[j];
            if(ansptr[j]>9)
            {
                if(ansptr[j-1]==0)
                {
                    ansptr[j-1]=ansptr[j]/10;
                    ansptr[j]%=10;
                    digits++;
                    pos[digits]=i;
                    break;
                }

                else
                {
                    ansptr[j-1]=ansptr[j-1]+1;
                    ansptr[j]%=10;
                }
            }

            prev1ptr=prev2ptr;
            prev2ptr=ansptr;
        }

    }
    for(int i=Max;pos[i]!=0;i--)
        cout<<pos[i]<<" ";
    return 0;
}
