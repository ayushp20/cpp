#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int k=1,max_length=1;

    for(int i=1;i<n;i++)
    {
        if(a[i]>=a[i-1])
        {
            k++;
            if(k>max_length)
                max_length=k;
        }
        else k=1;

    }
    cout<<max_length<<endl;

    return 0;
}
