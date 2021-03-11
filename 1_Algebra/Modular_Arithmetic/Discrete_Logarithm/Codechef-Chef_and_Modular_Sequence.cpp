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
const int MD=1e8+7;
const int MDL=99824453;
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
    

    ll n = sqrt(m) + 1;
    ll an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * a) % m;

    unordered_map<ll, ll> vals;
    for (ll q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * a) % m;
    }

    for (ll p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * an) % m;
        if (vals.count(cur)) {
            ll ans = n * p - vals[cur];
            if(ans!=0)
                return ans;
        }
    }
    return -1;
} 
 
 
 
void solve(){

    //NO IDEAS CLICKED.(Neither Satisfied with the editorial)
    repe(a,10){
        vector<pair<ll,ll>>v;
        ll cur=0;
        for(ll b=a;b>=1;b--){
            v.pb({inverted(a,b,MD),b});
        }
        sort(v.begin(),v.end());
        ll prev=INF;
        for(auto x:v){
            //cout<<"{ "<<x.ff<<" "<<x.ss<<" }, ";
            if(x.ff!=-1 && x.ss<prev){
                cur+=x.ss;
                cout<<x.ss<<" ";
                prev=x.ss;
            }
        }
        cout<<": "<<cur<<"\n";
    }      
  
 
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