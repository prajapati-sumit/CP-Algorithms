//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e6+5;

 
const int p=26;
const int m=1e9+9; 
const int m2=1e9+7;

int powp1[MX];
int powp2[MX];

pii compute_hash(string const& s) {
    long long hash_value1 = 0;
    long long hash_value2 = 0;
    int i=0;
    for (char c : s) {
        hash_value1 = (hash_value1 + (c - 'a' + 1) * powp1[i]) % m;
        hash_value2 = (hash_value2 + (c - 'a' + 1) * powp2[i]) % m2;
        i++;
    }
    return {hash_value1,hash_value2};
} 
void solve(){
    
    // Aho-Corasick Algorithm -Yet to learn
    int n,k;
    cin>>n>>k;
    string s; 
    cin>>s;
    map<int,int>mp;
    map<int,int>mp2;
    int g;
    cin>>g;
    repe(i,g){
        string tm;
        cin>>tm;
        pii tmp=compute_hash(tm);
        mp[tmp.ff]=i;
        mp2[tmp.ss]=i;
    }
    vector<int>v;
    rep(i,n){
        int cur_hash1=0;
        int cur_hash2=0;
        rep(j,k){
            cur_hash1 = (cur_hash1 + powp1[j]*(s[k*i+j]-'a'+1))%m;
            cur_hash2 = (cur_hash2 + powp2[j]*(s[k*i+j]-'a'+1))%m2;
        }
        int x1=mp[cur_hash1];
        int x2=mp[cur_hash2];
        // if(!x1 || !x2 || x1!=x2){
        //     cout<<"NO\n";
        //     return;
        // }
        // else
            v.pb(x1);
    }
    cout<<"YES\n";
    for(auto &el:v)
        cout<<el<<" "; 
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    powp1[0]=1;
    powp2[0]=1;
    repe(i,MX-1)
        powp1[i]=p*powp1[i-1]%m;
    repe(i,MX-1)
        powp2[i]=p*powp2[i-1]%m2;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}