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
const int MD = 100123456789 ;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e6 + 2;




int p=7;
int powp[MX];
int nc2(int n){
    return (n*(n-1))/2;
}
void solve() {

    int n, m;
    cin >> n >> m;
    powp[0]=1;
    repe(i,n)
        powp[i]=p*powp[i-1];
    vector<int>v(n + 1, 0);
    map<int,int>mp;
    int ans=0;
    vector<pii>edges;
    repe(i, m) {
        int x, y;
        cin >> x >> y;
        edges.pb({x,y});
        v[x]=(v[x]+powp[y]);
        v[y]=(v[y]+powp[x]);
    }
    repe(i,n){
        mp[v[i]]++;
    }
    for(auto &el:mp)
        ans+=nc2(el.ss);

    for(auto &el:edges){
        int x=el.ff,y=el.ss;
        int xseq=(v[x]-powp[y]);
        int yseq=(v[y]-powp[x]);
        ans+=(xseq==yseq);
    }
    cout<<ans<<'\n';


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    // cin>>t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}