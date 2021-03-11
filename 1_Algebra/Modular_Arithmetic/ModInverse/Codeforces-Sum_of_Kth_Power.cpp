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
const ll MX=1e6+5;
const ll MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
ll P[MX],fact[MX]; 
 

ll bin_power(ll a,ll b){
    ll res=1;
    while (b){
        if (b&1)
            res=(res*a)%MD;
        a=(a*a)%MD;
        b>>=1;
    }
    return res;
}

ll modInverse(ll x){
    
    return bin_power(x,MD-2);
}



 
 
void solve(){
    

    // ll x=100,y=-20;
    // ll d=(x*modInverse(y%MD))
    // return;
    ll n,k;
    cin>>n>>k;
    ll ans=0,numproduct=1;
    repe(i,k+2){
        numproduct=((n-i)*numproduct)%MD;
        P[i]=(P[i-1]+bin_power(i,k))%MD;
        
    }
    if(n<=(k+2)){
        cout<<P[n];
        return;
    }
    ll denm;
    repe(i,k+2){
        ll cur=(numproduct*modInverse(n-i))%MD;
        //cout<<cur<<" ";
        cur=(P[i]*cur)%MD;
        //cout<<cur<<" ";
        if((k+2-i)&1){
            denm=(fact[i-1]*fact[k+2-i])%MD;
            cur=(cur*modInverse(denm))%MD;
            ans=(ans+MD-cur)%MD;
        }
        else{
            denm=((fact[i-1]*fact[k+2-i])%MD)%MD;
            cur=(cur*modInverse(denm))%MD;
            ans=(ans+cur)%MD;
        }
        //cout<<denm<<" -> "<<cur<<": "<<ans<<'\n';
    }
    cout<<ans;
} 
 
 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    fact[0]=1;
    repe(i,MX-1)
        fact[i]=(i*fact[i-1])%MD;
    solve();
  
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";

    return 0;
 
}