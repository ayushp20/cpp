#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_asc(pair<int , int> a, pair<int, int > b){

    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int p, s;
    cin>>p>>s;
    int j = 1;
    vector<pair< int, int > > ans;
    while(j <= p){

        vector<pair<int, int> > v;
        vector<int> score;
        vector<int> n;
        int diff_n = 0;

        for(int i = 0; i < s; i++){
            int tmp;
            cin>>tmp;
            score.push_back(tmp);
        }
        for(int i = 0; i < s; i++){
            int tmp;
            cin>>tmp;
            n.push_back(tmp);
        }

        for(int i = 0; i < s; i++)
            v.push_back(make_pair(score[i], n[i]));


        sort(v.begin(),v.end(), cmp_asc);

        for(int i = 0; i < s-1; i++){
            if(v[i].second > v[i+1].second)
                diff_n++;
        }
        ans.push_back(make_pair(diff_n, j));
        j++;
    }
    sort(ans.begin(), ans.end(),cmp_asc);

    for(int i = 0; i < p; i++)
        cout<<ans[i].second<<endl;

    return 0;
}
