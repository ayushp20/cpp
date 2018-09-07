#include<iostream>
#include<set>

using namespace std;

unsigned int factorsum(int n)
{
    unsigned int sum=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            int other=n/i;
            if(other!=i)
                sum+=other;
        }
    }
    return sum;
}

int main()
{
    set<int>numbers;
    for(int i=12;i<=28123;i++)
    {
        unsigned int result =factorsum(i);
        if(result>i)
            numbers.insert(i);
    }

    int tests;
    cin>>tests;
    while(tests--)
    {
        int n;
        cin>>n;
        if(n>28123)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(auto it:numbers)
        {
            if(it>n)
            {
                cout<<"NO"<<endl;
                break;
            }

            set<int>::iterator temp=numbers.find(n-it);
            if(temp!=numbers.end())
            {
                cout<<"YES"<<endl;
                break;
            }
        }

    }

    return 0;
}
