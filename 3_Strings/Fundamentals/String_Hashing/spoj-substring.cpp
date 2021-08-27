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
const int MX=1e5+5;
const int p = 53;
const int m = 1e9 + 9;

int powp[MX];
ll bin_power(ll a,ll b,ll md){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
}
const int inv_p=bin_power(p,m-2,m);

long long compute_hash(string const& s) {
    
    long long hash_value = 0;
    long long p_pow = 1;
    int i=0;
    for (char c : s) {
        hash_value = (hash_value + (c - 'A' + 1) * powp[i]) % m;
        i++;
    }
    return hash_value;
} 
 

void solve(){
  
    string s;
    cin>>s;
    int N=s.length();
    int n;
    cin>>n;
    string P[n+1];
    map<int,set<pii>>mp;
    repe(i,n){
        cin>>P[i];
        mp[P[i].length()].insert({compute_hash(P[i]),i});
    }
    char res[n+1];
    repe(i,n)
        res[i]='N';

    for(auto &el:mp){
        int len=el.ff;
        int cur_hash=0;
        rep(i,len)
            cur_hash=(cur_hash+powp[i]*(s[i]-'A'+1))%m;
        auto it=el.ss.upper_bound({cur_hash,0});
        if(it!=el.ss.end() && it->ff==cur_hash){
            bool ok=true;
            rep(i,len){
                if(s[i]!=P[it->ss][i]){
                    ok=false;
                    break;
                }
            }
            if(ok){
                res[it->ss]='Y';
                el.ss.erase(it);
            }
        }
        // cout<<cur_hash<<"\n";
        for(int i=len;i<N;i++){
            cur_hash=(cur_hash+m-(s[i-len]-'A'+1))%m;
            cur_hash=(cur_hash*inv_p)%m;
            cur_hash=(cur_hash+powp[len-1]*(s[i]-'A'+1))%m;
            
            it=el.ss.upper_bound({cur_hash,0});
            if(it!=el.ss.end() && it->ff==cur_hash){
                bool ok=true;
                FOR(j,i-len+1,i){
                    if(s[j]!=P[it->ss][j-(i-len+1)]){
                        ok=false;
                        break;
                    }
                }
                if(ok){
                    res[it->ss]='Y';
                    el.ss.erase(it);
                }
            }
            
            // cout<<cur_hash<<"\n";

        }

    }
    
    repe(i,n)
        cout<<res[i]<<"\n";
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    powp[0]=1;
    repe(i,MX-1)
        powp[i]=p*powp[i-1]%m;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}