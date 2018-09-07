/* Time: April 13,2018 16:15
   Problem: Average Pairs
   Writer: Gandu Pandu
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(){
    ll n,ans=0; int tmp;
    cin>>n;
    unordered_map<int,int> freq;
    unordered_set<int> arr;
    for(int i=0;i<n;i++){
        cin>>tmp;
        freq[tmp]++;
        arr.insert(tmp);
    }
    for(auto i=arr.begin(); i!=arr.end();i++){
        for(auto j=i;j!=arr.end();j++){
            if(((*i+ *j)&1)==0 && freq[(*i+*j)/2]){
                ans+= (i==j)?(  ((ll)freq[*i]*(ll)(freq[*j]-1))/2  ):(  (ll)freq[*i]*(ll)(freq[*j])  );
            }
        }
    }
    return ans;
}
int main(void){
    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}
