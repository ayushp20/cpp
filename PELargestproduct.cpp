#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        int temp;
        vector<int>v;
        while(num[i]!='\0')
        {
            v[i]=num[i];
            i++;
            cout<<v[i]<<" ";

        }

        int i=0,prod,max=0;
        while(i<=n-k)
        {   prod=1;
            for(int j=i;j<=i+k-1;j++)
            {
                cout<<v[j]<<" ";
                prod*=v[j];
                cout<<prod<<" ";
            }
            cout<<prod<<endl;
            if (prod>max)
                max=prod;
            i++;
        }
        cout<<max<<endl;
    }
    return 0;
}
