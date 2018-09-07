#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

bool patternSearch(vector<string> text, vector<string> pattern){

    unordered_map<string, int> words;

    for(auto it: text)
        words[it]++;

    for(auto it: pattern){
        if(words[it] > 0)
            words[it]--;
        else
            return false;
    }

    return true;
}

int main()
{
    int n , m;
    string text, pattern;
    cin>>n>>m;
    vector<string> magazine;
    vector<string> ransom;
    string tmp;

    for(int i = 0; i < n; i++){
        cin>>tmp;
        magazine.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        cin>>tmp;
        ransom.push_back(tmp);
    }

    patternSearch(magazine, ransom)?cout<<"Yes":cout<<"No";

    return 0;
}

