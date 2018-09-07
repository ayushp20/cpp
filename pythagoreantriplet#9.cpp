#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int N;
        cin >> N;
        int sum=0,a,b,c=0,max=-1,temp;
        for(int m=2,n=1;(m*m)+(n*n)<N/2;m++,n++)
        {
            a=(m*m)-(n*n);
            b=2*m*n;
            c=(m*m)+(n*n);
            sum=a+b+c;
            if(sum==N)
             {
                temp=a*b*c;
                 if(temp>max)
                 {
                     max=temp;
                 }
             }
             else if(sum<N)
             {
                 for(int i=2;sum<=N;i++)
                {
                    a*=i;b*=i;c*=i;
                    sum=a+b+c;
                    if(sum==N)
                    {
                        temp=a*b*c;
                        if(temp>max)
                        {
                            max=temp;
                        }
                    }
                }
             }
        }

            cout<<max;
    }
    return 0;
}
