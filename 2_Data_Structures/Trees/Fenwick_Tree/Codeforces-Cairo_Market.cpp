// AUTHOR: Sumit Prajapati      
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define debug(x)            cerr<<#x<<" = "<<x<<'\n'
#define llrand()            distribution(generator)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0,0xFFFFFFFFFFFFFFFF);

const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=1e3+5;

 
int bit[1005][1005];
int n=1003;


int query(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret =max(ret, bit[i][j]);
    return ret;
}

void update(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < n; j = j | (j + 1))
            bit[i][j] = max(bit[i][j],delta);
}


void solve(){

    int q;
    cin>>q;
    // USE FENWICK TREE FOR 2D
    vector<pii>v(q);
    rep(i,q)
        cin>>v[i].ff>>v[i].ss;
    int x,y;
    int ans=0;
    for(int i=0;i<q;i++){
        x=v[i].ff;
        y=v[i].ss;

        int cur=1+query(x,y);
        // cout<<x<<" "<<y<<"-> "<<cur<<'\n';
        
        update(x,y,cur);
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    int t=1;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();

    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}