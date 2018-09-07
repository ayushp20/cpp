#include<iostream>
#include<set>
//using factorial number system
using namespace std;
/*void swapchar(char&a,char&b)
{
    char temp;
    temp=a;
    a=b;
    b=temp;
}

void permute(string str,int start,int end)
{
    int j;
    if(start==end)
        permutations.insert(str);
    else
    {
    for(j=start;j<=end;j++)
    {
        swapchar(str[start],str[j]);
        permute(str,start+1,end);
        swapchar(str[start],str[j]);

    }
    }
}*/
int main()
{
    string str="abcdefghijklm";
    int tests;
    cin>>tests;
    while(tests--)
    {
        unsigned long long factorials[14]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800};

        unsigned long long n;
        cin>>n;

        n%=factorials[13];
        n--;

        auto temp=str;
        string result;
        while(!temp.empty())
        {
            unsigned long long curr=factorials[temp.size()-1];
            int pos=n/curr;

            result +=temp[pos];
            temp.erase(pos,1);

            n%=curr;
        }
        cout<<result<<endl;


    }
    return 0;
}
