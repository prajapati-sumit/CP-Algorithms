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
const int MX = 2e6 + 2;


class Combination{

    int N;
    int* fact;
    int* ifact;
    int md;

public:
    Combination(int n,int M=1e9+7){
        N=n;
        fact=new int[N+1];
        ifact=new int[N+1];
        md=M;
        init();
    }
    int local_power(int a,int b,int md){
        int res=1;
        while (b){
            if (b&1)
                res=(res*1LL*a)%md;
            a=(a*1LL*a)%md;
            b>>=1;
        }
        return res;
    }
    void init(){
        fact[0]=1;
        ifact[0]=1;
        for(int i = 1; i <=N; ++i){
            fact[i] = i*fact[i-1]%md;
            ifact[i] = local_power(fact[i],md-2,md);
        }
    }
    int ncr(int n,int r){
        if(r>n)
            return 0;
        return (fact[n]*ifact[n-r]%md)*ifact[r]%md;
    }

};

Combination NCR(MX,MD);


void solve() {

    int n,k;
    cin>>n>>k;

    int ans=(2*NCR.ncr(n+k+1,k+2)-n+MD)%MD;
    cout<<ans<<"\n";


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto time0 = curtime;
    int t = 1;
    cin >> t;
    repe(tt, t) {
        // cout<<"Case #"<<tt<<": ";
        solve();
    }

    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}