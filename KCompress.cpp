#include<iostream>
#include<vector>
#include<limits>
#define INT_MAX 2147483647
using namespace std;


int find_min(int* arr, vector<int>visited , int n){
    int idx_min = 0;
    int min_val = arr[0];

    for(int i = 1; i<n;i++){
        if(arr[i] < min_val && visited[i] == 0){
            min_val = arr[i];
            idx_min = i;
        }
    }
    return idx_min;
}
int find_max(vector<int> priority, int idx, int k){
    int l= idx, r = idx + k;
    int n = priority.size();
    if(l < 0)
        l = 0;
    if(r>=n)
        r = n;
    int idx_max = l;
    int max_val = priority[l];
    for(int i = l+1; i <= r; i++){
        if(priority[i] > max_val){
            max_val = priority[i];
            idx_max = i;
        }
    }
    return idx_max;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n,s;
        cin>>n>>s;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        if(s < n){
            cout<<0<<endl;

        }
        else if(s >= n*(n+1)/2)
            cout<<n+1<<endl;

        else{
            vector<int> priority(n, 0);
            vector<int> visited(n, 0);
            int idx = find_min(arr, visited, 0), i = n/2, ans;
            visited[idx] = 1;
            priority[idx]++;

            while(i > 0){
               for(int j = 0;j < n;j++){
                   int idx = find_min(arr, visited, n);
                   int idx_p = find_max(priority, idx, i);

                   if(arr[idx] == arr[idx_p])
                        priority[idx] = priority[idx_p];
                   else
                        priority[idx] = priority[idx_p] + 1;
                }
                unsigned long long sum =0;
                for(int j = 0;j<n;j++)
                    sum += priority[j];

                ans = i + 1;
                if(sum > s){

                    i = i / 2;

                }

                else{
                    i = i + i/2;

                }
            }
            cout<<ans<<endl;

        }

    }

}
