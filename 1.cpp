#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long long unsigned countTriplets(vector<long long unsigned> arr, long long unsigned r) {

    unordered_map <long long unsigned, int> mmap;
    long long unsigned count_triplets = 0;
    for(int i = 0; i < arr.size(); i++)
        mmap[arr[i]]++;

    for(int i = 0; i < arr.size() - 2; i++){
            long long unsigned t1 = arr[i]*r;
            long long unsigned t2 = t1*r;

            if(mmap[t1] != 0  && mmap[t2] != 0 )
                count_triplets += max(mmap[arr[i]],max(mmap[t1], mmap[t2]));

            mmap[arr[i]]--;
    }

    return count_triplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long long unsigned r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long long unsigned> arr(n);

    for (int i = 0; i < n; i++) {
        long long unsigned arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long long unsigned ans = countTriplets(arr, r);

    fout << ans << "\n";
    cout<< ans <<"\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
