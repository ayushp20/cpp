#include<iostream>
#include<stack>

using namespace std;

int checkprime(unsigned long n)
{
    int flag=1;
    for(unsigned long i=2;i<=n/2;i++)
        if(n%i==0)
        {
            flag=0;
            break;
        }
    return flag;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        long n;
        cin >> n;
        stack <unsigned long>s;
        if(checkprime(n)==1)
            cout<<n<<endl;
        else
        {
        for(unsigned long i=2;i<=n/2;i++)
        {
            if(n%i==0)
            {
                int res=checkprime(i);
                if(res==1)
                    s.push(i);
            }
        }
            cout<<s.top()<<endl;
        }
    }
    return 0;
}
