#include <iostream>
#include <cmath>

using namespace std;

int MOD = 100000007;
int prime = 101;

long long createHash(string str, int size_){

    long long hashValue = 0;
    for(int i = 0; i < size_; i++)
        hashValue += ((int)str[i] * pow(prime, i)) ;

    return hashValue;
}

long long recalculateHash(string str, int beg, int en, long long prevHash){

    long long newHash = prevHash - str[beg];
    newHash /= prime;
    newHash += (str[en] * pow(prime, en-beg-1));

    return newHash;
}

bool checkEqual(string str1, int i, int en, string str2){


    for(int j = 0;i < en ;i++,j++)
        if(str1[i] != str2[j])
            return false;

    return true;

}

int patternSearch(string text, string pattern){

    int m = pattern.size();
    int n = text.size();

    long long patternHash = createHash(pattern, m);
    long long textHash = createHash(text, m);

    for(int i = 0; i< n-m+1; i++){

        if(patternHash == textHash ){
            if(checkEqual(text, i, i + m , pattern))
                return i;

        }

        if(i < n - m + 1)
            textHash = recalculateHash(text, i, i + m, textHash);
    }

    return -1;
}

int main()
{
    int n , m, k = 0, matches = 0, flag = 0;
    string text, pattern;
    cin>>n>>m>>text>>pattern;

    for(int i = 0;i < pattern.length();i++){
        string currPat;
        if(pattern[i] != ' ')
            currPat[k++] = pattern[i];

        else{
            k = 0;
            if(patternSearch(text, currPat) == -1){
                flag = 1;
                break;
            }

        }
    }

    if(flag)
        cout<<"No";
    else
        cout<<"Yes";
}

