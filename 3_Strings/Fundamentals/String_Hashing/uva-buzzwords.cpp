//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
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

const int m=1e9+9;
const int p=31;
 
string tmp;
 
void solve(){
    
    string s;
    for(auto &el:tmp)
        if(el!=' ')
            s.pb(el);
    int n=s.length();
    vector<map<int,int>>a(n+1);
    rep(i,n){
        int cur_hash=0;
        int p_pow=1;
        FOR(j,i,n-1){
            cur_hash=(cur_hash+(s[j]-'a'+1)*p_pow)%m;
            p_pow=(p_pow*p)%m;
            a[j-i+1][cur_hash]++;
        }
    }
    repe(i,n){
        int max_el=0;
        for(auto &el:a[i])
            max_el=max(max_el,el.ss);
        if (max_el<=1)
            break;
        cout<<max_el<<'\n';
    }

      
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    while(getline(cin,tmp)){
        // cout<<"Case #"<<tt<<": ";
        if(t++>1)
            cout<<'\n';
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}


