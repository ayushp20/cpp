#include <iostream>
#include<vector>
#include<math.h>
#include<time.h>
using namespace std;
vector <int> primelist;
int checkprime(int n)
{
    int i;
    for(i=0;i<primelist.size()&&primelist[i]*primelist[i]<=n;i++)
    {
        if(n%primelist[i]==0)
            return 0;
    }
    primelist.push_back(n);

        return 1;
}
int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int i=2,j=0;
        time_t start=clock();
        while(j<=10001)
        {
            int res=checkprime(i);
            if(res==1)
            {
                j++;
                if(j==n)
                {
                    cout<<i<<endl;
                    double time_diff=(clock()-start);
                    cout<<time_diff<<" ms\n";
                    break;
                }
            }
            i++;
        }
    }
    return 0;
}
