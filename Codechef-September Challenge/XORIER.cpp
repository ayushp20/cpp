#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

// Generate all prime numbers less than n.
bool SieveOfEratosthenes(int n, bool isPrime[])
{
    // Initialize all entries of boolean array
    // as true. A value in isPrime[i] will finally
    // be false if i is Not a prime, else true
    // bool isPrime[n+1];
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i<=n; i++)
        isPrime[i] = true;

    for (int p=2; p*p<=n; p++)
    {
        // If isPrime[p] is not changed, then it is
        // a prime
        if (isPrime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                isPrime[i] = false;
        }
    }
}
int main(){

//    bool isPrime[1000000];
//    SieveOfEratosthenes(1000000,isPrime);
    int t;
    cin>>t;


    while(t--){
        int n,odds = 0, evens = 0;
        cin>>n;
        vector<int> arr(n);
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            int tmp;
            cin>>tmp;
            mp[tmp]++;
            arr[i] = tmp;
            if(tmp&1)
                odds++;
            else
                evens++;
        }

        ull cnt = 0;

        for(int i = 0; i < n-1; i++){
            if(arr[i]&1)odds--;
            else evens--;
            mp[arr[i]]--;

            if(arr[i]&1)
                cnt+=odds - mp[arr[i]];
            else
                cnt+=evens- mp[arr[i]];

            if((arr[i]&2) == 2)
                cnt -= mp[arr[i]-2];
            else
                cnt -= mp[arr[i]+2];
        }



        cout<<cnt<<endl;
    }

    return 0;
}
