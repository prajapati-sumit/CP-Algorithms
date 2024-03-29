//~ author      : Sumit Prajapati
//~ mail ID     : sumitprajapati821@gmail.com
//~ codefoces   : sumitprajapati81, codechef: sumit141
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
// #define int              long long
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
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()



auto time0 = curtime;
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<ull> distribution(0, 0xFFFFFFFFFFFFFFFF);

const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;


struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a, int n): FenwickTree(a.size()) {
        for (int i = 1; i <= n; i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (; idx >= 1; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void updateRange(int l,int r,int delta){
        add(l,delta);
        add(r+1,-delta);
    }
    int pointQuery(int ind){
        return sum(ind);
    }
};


void solve() {

    int n, q;
    cin >> n >> q;
    FenwickTree fenw(n);
    repe(i,n)
        fenw.add(i,1);
    int x;
    repe(i,q){
        cin>>x;
        // cout<<x<<'\n';
        int ind=fenw.pointQuery(x);
        cout<<ind-1<<' ';
        fenw.updateRange(1,x-1,1);
        fenw.updateRange(x,x,1-ind);
    }
    cout<<'\n';

}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}