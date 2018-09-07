#include<iostream>
using namespace std;

long long count(long long m,long long n)
{
    return(n/m);
}

long long max(long long m,long long n)
{
    return count(m,n-1)*m;
}

long long sum_mult(long long m,long long n)
{
     return count(m,n-1)*(max(m,n)+m)/2;
}
int main()
{
long long sum_mult(long long,long long);
long long t,N;
cin>>t;
for(long long i=0;i<t;i++)
{
    cin>>N;
    long long sum_3,sum_5,sum_15;
    sum_3=sum_mult(3,N);
    sum_5=sum_mult(5,N);
    sum_15=sum_mult(15,N);

    cout<<sum_3+sum_5-sum_15<<endl;
}
return 0;
}
