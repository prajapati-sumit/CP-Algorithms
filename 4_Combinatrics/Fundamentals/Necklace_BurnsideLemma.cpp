//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                     unsigned long long
#define ll                      long long
#define int                     long long
#define pii                     pair<int, int>
#define pll                     pair<ll, ll>
#define pb                      push_back
#define mk                      make_pair
#define ff                      first
#define ss                      second
#define SZ(x)                   ((int)x.size())
#define set_bits                __builtin_popcountll
#define all(a)                  a.begin(),a.end()
#define trav(x,v)               for(auto &x:v)
#define rep(i,n)                for(int i=0;i<n;i++)
#define repe(i,n)               for(int i=1;i<=n;i++)
#define FOR(i,a,b)              for(int i=a;i<=b;i++)
#define curtime                 chrono::high_resolution_clock::now()
#define timedif(start,end)      chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define myshuffle(a,n)          FOR(i,1,n-1) swap(a[i], a[rand() % (i + 1)])
#define shuffle(a)              shuffle(a.begin(), a.end(), rng)
#define mtrand(a,b)             uniform_int_distribution<int>(a, b)(rng)


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e5 + 5;




// #warning works on array from 1...n
// with path compression and union by rank.
class DSU{

public:
    vector<int>parent;

    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=-1;
    }
    int find_set(int x){
        return parent[x]<0?x:parent[x]=find_set(parent[x]);
    } 
    void union_set(int a,int b){
        int pa=find_set(a);
        int pb=find_set(b);
        if(pa==pb)
            return;
        if(parent[pa]>parent[pb])
            swap(pa,pb);

        parent[pa]+=parent[pb];
        parent[pb]=pa;
    } 
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }

};
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

void solve() {

    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int d=0;d<n;d++){
        DSU D(n);
        int p=0;
        for(int i=0;i<n;i++)
            D.union_set(i,(i+d)%n);
        for(int i=0;i<n;i++)
            if(D.parent[i]<0)
                p++;
        ans=(ans+bin_power(k,p,MD))%MD;
    }
    ans=(ans*bin_power(n,MD-2,MD))%MD;
    cout<<ans<<"\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        cout<<"Case "<<tt<<": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}