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
const int MD=998244352;
const int MDL=998244353;
const int k_max=102;
auto time0 = curtime;
 
ll A[k_max][k_max],k;
ll I[k_max][k_max];
 
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
void multiply(bool isI){
  
    
    ll res[k+1][k+1];
    repe(i,k)
        repe(j,k)
            res[i][j]=0;
    repe(i,k){
        repe(j,k){
            repe(l,k){
                if(isI)
                    res[i][j]=(res[i][j]+I[i][l]*A[l][j])%MD;
                else
                    res[i][j]=(res[i][j]+A[i][l]*A[l][j])%MD;
            }
        }
    }
  
    repe(i,k)
        repe(j,k)
            if(isI)
                I[i][j]=res[i][j];
            else
                A[i][j]=res[i][j];
}

void execute(ll exp){

    while(exp){
        if(exp&1)
            multiply(1);
        exp>>=1;
        multiply(0);
    }
}
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
void solve(){
  
    //NICE QUESTION.....!!
    //DON'T FORGET ABOUT TRANSITION MATRIX FOR RECURRANCE
    cin>>k;
    ll b[k+1];
    repe(i,k){
        cin>>b[i];
        A[1][i]=b[i];
    }
    ll n,m;
    cin>>n>>m;
    FOR(i,1,k)
        I[i][i]=1;
    FOR(i,2,k)
        A[i][i-1]=1;

    
    execute(n-k);
    // repe(i,k){
    //     repe(j,k){
    //         cout<<I[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    ll p=I[1][1],base=bin_power(3,p,MDL);
    ll q=inverted(base,m,MDL);
    if(q==-1){
        cout<<"-1";
        return;
    }
    ll x=bin_power(3,q,MDL);
    cout<<x;


 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}