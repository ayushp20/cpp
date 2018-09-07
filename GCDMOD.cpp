    #include <iostream>
    #include <limits>
    #include <algorithm>

    using namespace std;

    unsigned long long MOD1 = 1000000007;
    unsigned long long MOD = 1e9;

    unsigned long long fuck(unsigned long long a, unsigned long long b, unsigned long long m){

            unsigned long long a1 = a/MOD;
            unsigned long long a2 = a%MOD;
            unsigned long long b1 = b/MOD;
            unsigned long long b2 = b%MOD;

            return ((((MOD*MOD)%m)*(a1*b1)%m)%m + ((((b2*MOD)%m)*a1)%m)  + ((((a2*MOD)%m)*b1)%m) + ((a2*b2)%m))%m;

    }
    unsigned long long power(unsigned long long x, unsigned long long n, unsigned long long m ){

        unsigned long long res = 1;

        while( n > 0){

            if(n & 1)
                res = fuck(res,x,m);

            n = n>>1;
            x = fuck(x,x,m);
        }

        return res;
    }



    unsigned long long gcd(unsigned long long a, unsigned long long b){

        if(a == 0)
            return b;

        return gcd(b%a, a);
    }

    int main(){

        int t;
        cin>>t;

        while(t--){

            unsigned long long a,b,n;

            cin>>a>>b>>n;
            unsigned long long t1;
            if((a-b) == 0){
                cout << (power(a,n,MOD1) + power (b,n,MOD1))%MOD1 << "\n";
                continue;
            }

            t1 = (power(a,n,a-b) + power (b,n,a-b))%(a-b);

            unsigned long long t2 = (a - b);
            unsigned long long ans = gcd(t2, t1) % MOD1;

            cout<<ans<<endl;
        }

        return 0;
    }

