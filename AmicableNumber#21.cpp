#include<iostream>
#include<set>
using namespace std;

unsigned int factorsum(int n)
{
    unsigned int sum=1;
    for(unsigned int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
             sum+=i;

            if((n/i)!=i)
                sum+=(n/i);

        }
    }
    return sum;
}

int main()
{
    set<unsigned int> amicables;
    int MAX=100000;

    for(int i=2;i<=MAX;i++)
    {
        unsigned int sibling=factorsum(i);

        if(factorsum(sibling)==i&&i!=sibling)
        {
            amicables.insert(i);
            amicables.insert(sibling);
        }
    }

    int tests;
    cin>>tests;
    while(tests--)
    {
        int n;
        cin>>n;
        unsigned int sum=0;

        for(set<unsigned int>iterator::it=amicables.begin();it!=amicables.end();it++)
        {

            if(*it>n)
                break;



            sum+=*it;
        }

        cout<<sum<<endl;
    }
    /*
    int n;
    cin>>n;
    cout<<factorsum(n);
    */
    return 0;
}
