#include <iostream>
using namespace std;

int main() {
    int n,i;
    cin>>n;
    unsigned long long count[1024]={};
    unsigned long long win_pair=0;

    string x;

    for (int i = 0; i< n; i++)
    {
       cin>>x;
       int mask=0;
       for(int j=0;x[j]!='\0';j++)
           mask|=(1<<(x[j]-'0'));

        ++count[mask];
    }


    for(int i=0;i<=1023;i++)
        for(int k=0;k<=1023;k++)
            if((i|k)==1023)
                win_pair+=i==k?1LL*count[i]*(count[i]-1):1LL*count[i]*count[k];

       cout<<(win_pair/2LL)<<endl;

      return 0;
}
/*SETTER's CODE
#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int cnt[1 << 10];


void readInp() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  string x;
  cin >> n;
  for(int i = 1; i <= n; ++i) {
  	cin >> x;
    int mask = 0;
  	for(int j = 0; j < x.size(); ++j) mask |= (1 << (x[j] - '0'));
  	++cnt[mask];
  }
}

long long solve() {
   long long ans = 0;
   for(int m1 = 0; m1 <= 1023; ++m1)
   	for(int m2 = 0; m2 <= 1023; ++m2)
   	 if((m1 | m2) == 1023)
   	 	ans += m1 == m2 ? 1LL * cnt[m1] * (cnt[m1] - 1) : 1LL * cnt[m1] * cnt[m2];
    return ans / 2LL;
}

void out(long long x) {
	cout << x << endl;
}

int main() {
	readInp();
	out(solve());
	return 0;
}*/
