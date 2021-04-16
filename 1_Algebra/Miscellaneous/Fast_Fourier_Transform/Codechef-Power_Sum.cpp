//CODED BY SUMIT KUMAR PRAJAPATI
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF = 1e9;
const int MX = 1e5 + 5;
const int MD = 1e9 + 7;
const int MDL = 998244353;
auto time0 = curtime;

ll bin_power(ll a, ll b, ll md = MDL) {
    ll res = 1;
    if (a == 0)
        return 0;
    while (b) {
        if (b & 1)
            res = (res * a) % md;
        a = (a * a) % md;
        b >>= 1;
    }
    return res;
}

ll n, s, k;
ll V[101][101];
ll res[101];

void  multiply(ll cur) {
    vector<ll>temp(101,0) ;
    FOR(i, 0, 100) {
        if (i > s)
            break;
        FOR(j, 0, 100) {
            if (i + j > s)
                break;
            if(i!=0 && j!=0 && (res[i]==0 || V[cur][j]==0) )
                continue;
            if((res[i]+V[cur][j])==0)
                continue;
            cout<<i<<" "<<j<<" -> "<<res[i]<<" "<<V[cur][j]<<" ";
            temp[i+j]=(res[i]+V[cur][j])%MDL;
            cout<<temp[i+j]<<"\n";
        }
    }
    FOR(i,0,100){
        // cout<<temp[i]<<" ";
        res[i]=temp[i];
    }
    cout<<"\n";
}
void solve() {

    //TODO - must solve this. You have seen the editorial.
    cin >> n >> s >> k;
    ll ci, vi;
    repe(i, n) cin >> ci >> vi, V[i][ci] = vi;
    FOR(i, 1, n){
        multiply(i);
        FOR(i,0,3)
            cout<<res[i]<<" ";
        cout<<'\n';
    }

    // ll ans = 0;
    // repe(i, s) {
    //     ans=(ans+res[i])%MDL;      
    // }
    // cout<<ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0));
    time0 = curtime;


    solve();


    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;

}