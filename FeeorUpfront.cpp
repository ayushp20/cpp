#include <bits/stdc++.h>
using namespace std;

string feeOrUpfront(float n, float k, float x, float d, vector <float> p)
{
    // Complete this function
    float sum=0,temp,i=0;

    while(n--)
    {
        temp=(x/100.0*p[i]);
        if(temp>k)
            sum+=temp;
        else
            sum+=k;

        i++;
    }
    if(sum>d)
        return "upfront";
    else
        return "fee";
}

int main() {
    float q;
    cin >> q;
    for(float a0 = 0; a0 < q; a0++){
        float n;
        float k;
        float x;
        float d;
        cin >> n >> k >> x >> d;
        vector<float> p(n);
        for(float p_i = 0; p_i < n; p_i++){
           cin >> p[p_i];
        }
        string result = feeOrUpfront(n, k, x, d, p);
        cout << result << endl;
    }
    return 0;
}
