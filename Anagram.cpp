#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {


    int countAnagrams = 0;
    int n = s.length();
    for(int i = 0; i < n - 1; i++){
        map<string, int> strings;
        for(int j = 0; j < n - i; j++){
            string tmp = s.substr(j, i+1);
            sort(tmp.begin(), tmp.end());
            strings[tmp]++;
        }

        for(auto it:strings){
                if(it.second >= 2)
                countAnagrams += (it.second * (it.second - 1)) / 2;
        }

    }

    return countAnagrams;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
