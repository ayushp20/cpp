#include <iostream>
#include <algorithm>
using namespace std;
int myfun(int a, int b, int c, int N){
    int ans=0;
    for(int i=1;i<=a;i++){
        for(int j=1;(i*j<=N&&j<=b);j++){
            if((N%(i*j))==0 && N/(i*j) <= c)ans++;
        }
    }
    return ans;
}
int main(void){
    int N;
    int a[3];
    int t;
    cin>>t;
    while(t--){
        cin>>N;
        cin>>a[0];
        cin>>a[1];
        cin>>a[2];
        sort(a,a+3);
        cout<<myfun(a[0],a[1],a[2],N)<<endl;
    }
    return 0;
}
