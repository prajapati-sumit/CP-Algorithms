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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 




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

ll inverted(ll a,ll b,ll m){

    a %= m, b %= m;
    ll k = 1, add = 0, g;
    while ((g = __gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * a / g) % m;
    }

    ll n = sqrt(m) + 1;
    ll an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<ll, ll> vals;
    for (ll q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * a) % m;
    }

    for (ll p = 1, cur = k; p <= n; ++p) {
        cur = (cur * an) % m;
        if (vals.count(cur)) {
            ll ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

ll fn(string &s,ll m,ll cur){
    if(cur<0)
        return 1;
    ll res=bin_power(2,s[cur]-'0',m);
    return (res*bin_power(fn(s,m,cur-1),10,m))%m;
}
void solve(){

    ll x,m,a,b;
    string N;
    cin>>N>>x>>m;
    ll ans,len=N.length();
    if(m == 1){
        cout << 0 << "\n";
        return;
    }
    if(len == 1 && N[0] == '1'){
        if(x == 1) cout << 0 << "\n";
        else cout << -1 << "\n";
        return;
    }
    if(x == 0){
        cout << 1 << '\n';
        return;
    }
    ll mod2n=fn(N,m,len-1);
    cout<<mod2n<<"\n";
    a=(mod2n+m-1)%m;
    ll p=inverted(a,x,m);
    if(p==-1){
        cout<<"-1\n";
        return;
    }
    mod2n=fn(N,MDL,len-1);
    mod2n=(mod2n*bin_power(2,MDL-2,MDL))%MDL;
    cout<<mod2n<<"\n";
    ans=bin_power(2,p,MDL);
    ans=(ans+MDL-1)%MDL;
    ans=(ans*mod2n)%MDL;
    cout<<ans<<'\n';
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    
    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}