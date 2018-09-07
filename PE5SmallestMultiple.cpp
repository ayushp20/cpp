#include <iostream>
#include<math.h>

using namespace std;

int checkprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int num=1;
        for(int i=2;i<=n;i++)
        {
            int res=checkprime(i);
            if(res==1)
            {
                for(int j=5;j>=1;j--)
                {
                    int gp=i*pow(i,j-1);
                    if(gp<=n)
                    {
                        num*=gp;
                        break;
                    }
                }

            }
        }
        cout<<num<<endl;
    }
    return 0;
}
