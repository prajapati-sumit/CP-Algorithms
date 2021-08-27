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
const int MD = 1e9 + 7;
const int MDL = 998244353;
const int INF = 1e9;
const int MX = 1e3 + 2;

const int p = 26;
const int m = 1e9 + 9;


ll bin_power(ll a, ll b, ll md) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % md;
        a = (a * a) % md;
        b >>= 1;
    }
    return res;
}

string s;
int powp[MX];
int hashes[MX][MX];
int inv[MX];
bool isrepeating(int l, int r, int d) {
    
    int len = r - l + 1;
    int repunit = hashes[l][l+d-1];
    int whole = hashes[l][r];
    // cout<<repunit<<" "<<whole<<'\n';
    repunit = (repunit * (powp[len] - 1 + m)) % m;
    repunit = (repunit*inv[d]) % m;
    return (repunit == whole);
}
void solve() {


    cin >> s;
    int n = s.length();
    int X[n + 1] = {0};
    rep(i, n) {
        int cur_hash = 0;
        FOR(j, i, n - 1) {
            cur_hash=(cur_hash+powp[j-i]*(s[j]-'a'+1))%m;
            hashes[i][j]=cur_hash;
            int len = j - i + 1;
            for (int d = 1; d * d <= len; d++) {
                if (len % d == 0) {
                    if(isrepeating(i,j,d))
                        X[len/d]=max(X[len/d],len);
                    if(d*d!=len){
                        if(isrepeating(i,j,len/d)){

                            X[d]=max(X[d],len);
                        }

                    }
                }
            }

        }
    }
    repe(i,n)
        cout<<X[i]<<" \n"[i==n];


}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t = 1;
    cin >> t;
    powp[0] = 1;
    repe(i, MX - 1)
        powp[i] = p * powp[i - 1] % m;
    repe(i,MX-1)
        inv[i]=bin_power(powp[i]-1+m,m-2,m);
    repe(tt, t) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}