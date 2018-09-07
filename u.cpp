#include <iostream>
#include <cstring>

using namespace std;



int main()
{
    int n, q;

    cin>>n;
    string inp[n];
    for(int i = 0 ; i< n; i++)
    {
        cin>>inp[i];
        }
    char check[25];
    cin>>q;
    while(q--)
    {
        cin>>check;

        int ans = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(strcmp(inp[i], c.c_str()heck) == 0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
