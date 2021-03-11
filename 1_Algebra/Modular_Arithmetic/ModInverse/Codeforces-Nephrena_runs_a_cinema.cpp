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
const int MDL=99824453;
auto time0 = curtime;
 
 
ll n,p,l,r; 

ll fact[MX]; 
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

ll modInverse(ll x){

    return bin_power(x,p-2,p);
}

ll ncr(ll n,ll r){
    return ((fact[n]* modInverse(fact[r])) % p * modInverse(fact[n-r]) % p) % p;
}
 
void solve(){
  

    //Can't do since is P is not necessarily prime.
    if(p==1){
        cout<<"0";
        return;
    }
    
    ll A,B,C,ans;
    FOR(x,l,r){
        A=0;
        B=A+l;
        C=n-(A+B)
        while(A+B<=n){
            ans=(ans+fn(A,B,C))%p;
            A++;
            B++;
            C=n-(A+B);
        }
    }
  
    cout<<ans<<'\n';
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    cin>>n>>p>>l>>r;
    fact[0]=1;
    repe(i,MX-1)
        fact[i]=(i*fact[i-1])%p;
    solve();
    
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}