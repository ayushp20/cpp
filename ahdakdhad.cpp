#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <int> arr) {
    // Complete this function
    int n=arr.size();
    sort(arr.begin(),arr.begin()+5);

    for(int arr_i = 0; arr_i < 5; arr_i++){
            cout<<arr[arr_i];
    }
    long long res=0;

     for(int i=0;i<4;i++)
    {
        res+=static_cast<long long>(arr[i]);
    }

    cout<<res<<" ";
    res=0;
     for(int i=0;i<4;i++)
    {
        res+=static_cast<long long>(arr[4-i]);
    }

    cout<<res;
}

int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
            cin>>arr[arr_i];
    }
    for(int arr_i = 0; arr_i < 5; arr_i++){
            cout<<arr[arr_i]<<" ";
    }
    cout<<endl;
    miniMaxSum(arr);
    return 0;
}
