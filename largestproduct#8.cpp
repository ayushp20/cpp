#include<iostream>
#include<vector>
using namespace std;

int main()
{
    string str="123456";
    vector <int> v;
    for(int i=0;i<6;i++)
    {
        v.push_back((str[i]-'0')*1);
    }

    unsigned int max=0,temp;
    for(int i=0;i<2;i++)
    {   temp=1;
        for(int j=0;j<5;j++)
            temp*=v[i+j];
           if(temp>max)
            max=temp;
    }
    cout<<max;
    return 0;
}
