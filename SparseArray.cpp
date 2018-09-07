#include <iostream>

using namespace std;

int main()
{
    int n,q,sum,flag;
    cin>>n;
    char ch[n][20];
    for(int i=0;i<n;i++)
        cin>>ch[i];
    cin>>q;
    char qh[q][20];
    for(int i=0;i<q;i++)
        cin>>qh[i];

    for(int i=0;i<q;i++)
        {   sum=0;
            for(int k=0;k<n;k++)
            {flag=1;
              for(int j=0;ch[i][j]!='\0';j++)

                    if(qh[i][j]!=ch[k][j])
                    {
                        flag=0;
                        break;

                    }



            if (flag==1)
            sum++;
            }
            cout<<sum<<endl;
        }
        return 0;
}
