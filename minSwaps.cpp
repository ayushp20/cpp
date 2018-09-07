#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr){

    int count = 0;

    for(int i = 0;i<arr.size();i++)
        if(arr[i] != i+1){
            swap(arr[i],arr[arr[i]-1]);
            count++;
        }
    return count;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }
    int res = minimumSwaps(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}


