#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {   unsigned long long t1=0,t2=2,temp,sum=0,n;
        cin>>n;
        while(t2<n)
        {
            sum+=t2;
            temp=t2;
            t2=4*t2+t1;
            t1=temp;

        }
        cout<<sum<<endl;
    }

}
