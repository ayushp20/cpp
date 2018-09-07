#include<iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        unsigned long long n,max=0;
        cin >> n;
        for(long i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                max=i;
                while(n%i==0)
                    n/=i;

            }


        }
        if(n!=1)
            cout<<n<<endl;
        else cout<<max<<endl;
        }

return 0;

}
