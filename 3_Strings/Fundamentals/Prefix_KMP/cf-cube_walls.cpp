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
#define SZ(x)               ((int)x.size())
#define set_bits            __builtin_popcountll
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e15 + 2;
const int MX = 1e5 + 5;






vector<int>a, b, gl;
int n, m;

bool compare(int x, int y, int offset) {

    return (x + offset) == y;
}
void solve() {

    //b+'$'+a
    cin >> n >> m;

    rep(i, n) {
        int x;
        cin >> x;
        a.pb(x);
    }
    rep(i, m) {
        int x;
        cin >> x;
        b.pb(x);
    }
    rep(i, m - 1)
    gl.pb(b[i] - b[i + 1]);

    gl.pb(INF);
    rep(i, n - 1)
    gl.pb(a[i] - a[i + 1]);

    int sz = SZ(gl);
    vector<int>pi(sz);
    pi[0] = 0;
    int ans=0;
    // rep(i, sz)
    // cout << gl[i] << " \n"[i == sz - 1];
    // cout << pi[0] << " ";
    for (int i = 1; i < sz; i++) {
        int j = pi[i - 1];

        while (j > 0 && gl[i] != gl[j])
            j = pi[j - 1];
        if (gl[i] == gl[j])
            j++;
        pi[i] = j;
        
        // cout << pi[i] << " \n"[i == sz - 1];
    }
    rep(i,sz)
        ans+=(pi[i]==(m-1));
    cout<<ans<<'\n';




}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    // cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}