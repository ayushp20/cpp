#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

int func(int n){

    if(n == 1)return 2;
    int t1 = log2(n);
    if(n == pow(2,t1))return 1;

    int t2 = log2(n - pow(2,t1));
    if(n == pow(2, t1) + pow(2, t2))return 0;

    return min(n - (pow(2,t1) + pow (2, t2)), (pow(2,t1)+pow(2,t2 + 1) - n));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        cout<<func(n)<<endl;
    }
    return 0;
}
