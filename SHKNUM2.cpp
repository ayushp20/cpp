#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int bSearch(int n, vector<int> v, int l, int r){
    int mid = (l + r - 1)/2;

    while(l <= r){

        mid = (l + r  )/ 2;
        //cout<< l<<" "<<r<<" "<<mid<<endl;
        if(v[mid] == n)
            return mid;

        else if(v[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;


    }

    return mid;
}

int func(int n, vector <int> v){

    /*if(n == 1)return 2;

    int t1 = log2(n);
    if(n == pow(2,t1))return 1;

    int t2 = log2(n - pow(2,t1));
    if(n == pow(2, t1) + pow(2, t2))return 0;*/

    int idx = bSearch(n,v,0,v.size()-1);
    //cout<<idx<<" ";

    if(v[idx] == n)
        return 0;

    else if(v[idx] < n){
        if(idx < v.size() - 1)
            return min(n - v[idx], v[idx+1] - n);
        else
            return n - v[idx];
    }
    else {
        if(idx > 0)
            return min(v[idx] - n, n - v[idx - 1]);
        else
            return v[idx] - n;
    }

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int> v;
    for(int i = 0; i <= 29; i++){
        int c = pow(2,i);
        for(int j = i+1; j <= 30; j++)
                v.push_back(c + pow(2,j));

    }

    sort(v.begin(), v.end());
    while(t--){
        int n;
        cin>>n;

        cout<<func(n, v)<<endl;
    }
    return 0;
}

