#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
//int gen_perm(int n){
//
//    map<string,int> mp;
//    for(int i = 0; i<n; i++){
//
//        vector<int> arr(n);
//        for(int j = 1; j <=n; j++)
//            arr[j-1] = j;
//
//        for(int j = i; j < n ; j++){
//
//            for(int k =j; k < n; k++)
//                swap(arr[i],arr[k]);
//        }
//        string p="";
////        for(int j = 0; j <n ;j++)
////            cout<<arr[j]<<" ";
//
//        for(int j = 0; j <n ;j++)
//            p += arr[j]+'0';
//        cout<<p<<endl;
//        mp[p]++;
//    }
//
//    map<string, int>::iterator it;
//
//for ( it = mp.begin(); it != mp.end(); it++ )
//{
//    std::cout << it->first  // string (key)
//              << ':'
//              << it->second   // string's value
//              << std::endl ;
//}
//
//}
int main(){

    int n;
    cin>>n;

    if(n == 1)
        cout<<"1"<<endl<<"1"<<endl;

    else{
        int mid = n/2;

        for(int i = 1; i < mid; i++)
            cout<<i+1<<" ";
        cout<<"1 ";
        for(int i = mid + 1; i < n; i++)
            cout<<i+1<<" ";
        cout<<mid + 1<<endl;

        cout<<n<<" ";
        for(int i = 1; i < n; i++)
            cout<<i<<" ";

    }

    return 0;
}
































