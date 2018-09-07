#include <iostream>

using namespace std;
int pallindrome(int n)
{
    int temp=n,rev=0;

    while(temp!=0)
    {
        rev=rev*10+temp%10;
        temp/=10;
    }
    if(rev==n)
        return 1;
    else
        return 0;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n,flag=0;
        cin >> n;
        while(n>=101101&&flag==0)
        {
            int res=pallindrome(n);
            if(res==1)
            {
                for(int i=999;i>99;i--)
                {
                   if(n%i==0)
                   {
                       if(n/i<1000)
                       {cout<<n<<endl;flag=1;break;}
                   }
                }
            }
            n--;
        }
    }
    return 0;
}
