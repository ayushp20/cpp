#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        vector<int>temp;
        stack<int> a;
        for(int a_i = 0; a_i < n; a_i++)
            cin >> temp[a_i];
        for(int a_i = n-1; a_i >-1; a_i--)
             a.push(temp[a_i]);

        stack<int> b;
        for(int b_i = 0; b_i < m; b_i++)
            cin >> temp[b_i];

        for(int a_i = m-1; a_i >-1; a_i--)
             b.push(temp[a_i]);

        // your code goes here
        int sum=0,i=0,count=0;
        while(sum<=x)
        {
            if(a.empty()&&!b.empty())
            {
                sum+=b.top();
                b.pop();
                count++;
            }
            else if(b.empty()&&!a.empty())
            {
                sum+=a.top();
                a.pop();
                count++;
            }
            else if(b.empty()&&a.empty())
            {   i=1;
                break;
            }
            else
            {
            if(a.top()<=b.top())
            {
                sum+=a.top();
                a.pop();
                count++;
            }
            else
            {
                sum+=b.top();
                b.pop();
                count++;
            }

            }
        }
        if(i==1)
        {
            cout<<count;
        }
        else
        cout<<count-1;

    }

    return 0;
}
