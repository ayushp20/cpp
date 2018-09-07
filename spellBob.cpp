#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

string spellBob(string s1, string s2){

    vector<int> f1(3, 0),f2(3, 0);
    unordered_set<int> b_idx,o_idx;
    int res = 1, b = 0, o = 0;



    for(int i = 0; i < 3; i++){

        if(s1[i] == 'b')
            f1[i] = 1, b++, b_idx.insert(i);
        if(s1[i] == 'o')
            f1[i] = 1, o++, o_idx.insert(i);
        if(s2[i] == 'b')
            f2[i] = 1, b++,b_idx.insert(i);
        if(s2[i] == 'o')
            f2[i] = 1, o++, o_idx.insert(i);

        res = res & (f1[i]|f2[i]);
        }

    if(res && b>=2 && o>=1 && o_idx.size()>=1 && b_idx.size()>=2 )
        return "yes";

    return "no";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;

        cout<<spellBob(s1,s2)<<endl;

    }
    return 0;
}
