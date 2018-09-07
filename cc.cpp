#include<bits/stdc++.h>
#define SZ(x) (long long)(x).size()
#define dbg(x) cout << #x << " is: " << x << endl
using namespace std;
int tt;
const int N = 1e5 + 10;
int n;
int s;
vector<int> arr(N,0), temp(N,0);
set<int> mys;
pair<int,int> q[N];
queue<pair<int,int> > qu;
vector<int> p(2*N + 20,0);
vector<int> ids;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first!=b.first){
        return (a.first < b.first);
    }
    return (a.second < b.second);
}
int findMaxCompress(){
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int fmc=0;
    sort(temp.begin(),temp.begin()+n);
    int m=0;
    for(int i=0;i<n;i++){
        m++;
        fmc += mp[temp[i]] *m;
        if(mp[temp[i]]==0)m--;
        mp[temp[i]]=0;
    }
    return fmc;
}
void forAllTime(){
    for(int i=0;i<n;i++){
        q[i] = make_pair(arr[i],i);
    }
    sort(q,q+n,cmp);
}
void update(int pos, int val){
    for(p[pos+=n]=val;pos>1;pos>>=1){
        p[pos>>1] = max(p[pos], p[pos^1]);
    }
}
int query(int l, int r){
    int res = 0;
    for(l+=n,r+=n; l<r;l>>=1,r>>=1){
        if(l&1) res = max(res,p[l++]);
        if(r&1) res = max(res,p[--r]);
    }
    return res;
}
vector<vector<int> > giveConnect(vector<int> ids, int k){
    int cc = 1;
    for(int i=1;i<SZ(ids);i++){
        int id = ids[i];
        int l = max(0,id-k);
        int r = max(n-1,id+k);
        if(ids[i-1] > r || ids[i-1] < l)cc++;
    }
    vector<vector<int> > connected;
    connected.resize(cc);
    int cn = -1;
    int prev = -1000000000;
    for(int i=0;i<SZ(ids);i++){
        int id = ids[i];
        int l = max(0,id-k);
        int r = min(n-1,id+k);
        if(prev > r || prev < l){
                cn++;
                connected[cn].push_back(id);
                prev = id;
        }
        else{
            connected[cn].push_back(id);
            prev = id;
        }
    }
    return connected;
}
int fmc(int k){
    while(!qu.empty()){
        qu.pop();
    }
    for(int i=0;i<n;i++){
        qu.push(q[i]);
    }
    fill(p.begin(),p.begin()+(2*n)+10,0);
    while(!qu.empty()){
        ids.clear();
        int cv = qu.front().first;
        while(!qu.empty() && ( qu.front().first == cv)){
            ids.push_back(qu.front().second);
            qu.pop();
        }

        vector<vector<int> > connected = giveConnect(ids,k);
        for(int i=0;i<SZ(connected);i++){
            int val = -10000;
            for(int j=0;j<SZ(connected[i]);j++){
                    int id = connected[i][j];
                    int l = max(0,id-k);
                    int r = min(n-1,id+k);
                    int quer = query(l,r+1);
                    val =   max(val,1+quer);
            }
            for(int j=0;j<SZ(connected[i]);j++){
                int id = connected[i][j];
                update(id,val);
            }
        }
    }
    dbg(k);
    for(int i=n;i<2*n;i++){
        cout << p[i] << " ";
    }
    cout << endl << endl;
    int s = accumulate(p.begin()+n, p.begin()+n+n,0);
    return s;
}
// fmc -> find minimum compression
// invariant : fmc at r > s  && fmc at l <= s
int bsc(int l, int r, int s){
        while(r-l > 1){
            int m = (r-l)/2 + l;
            int at_m_fmc = fmc(m);
            if(at_m_fmc > s){
                r = m;
            }else{
                l = m;
            }
        }
        return (l+1);
}
signed main(){
    freopen("in.txt","r",stdin);
    cin >> tt;
    while(tt--){
        cin >> n >> s;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            temp[i] = arr[i];
        }
        int fmc = findMaxCompress();
        if(s < n){
            puts("0");
        }else if( s>=fmc){
            cout << n+1 << endl;
        }else{
            forAllTime();
            cout << bsc(0,n,s) << endl;
        }
    }
    return 0;
}
