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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const ll MX=1e7+5;
const ll MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
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
    return bin_power(x,MD-2,MD);
}

ll ncr(ll n,ll r){
    return ((fact[n]* modInverse(fact[r])) % MD * modInverse(fact[n-r]) % MD) % MD;
}


bool isbeautiful(ll x,ll a,ll b){

    while(x>0){
        ll k=x%10;
        if(k!=a && k!=b)
            return false;
        x/=10;
    }
    return true;
}
 
 
 
 
 
void solve(){

    ll cnt=0;
    ll a,b,n;
    cin>>a>>b>>n;
    if (a<b)
        swap(a,b);
    ll limit=9e6;
    for(ll i=1;i<=limit;i++){
        if( isbeautiful(i,a,b) ){
            ll c=i;
            ll x=(c-b*n);
            ll y=(a*n-c);
            if (x>=0 && y>=0 && x%(a-b)==0 && y%(a-b)==0){
                x/=(a-b);
                y/=(a-b);
                // cout<<i<<" "<<x<<" "<<y<<'\n';
                //cout<<ncr(x+y,x)<<'\n';
                cnt=(cnt+ncr(x+y,x))%MD;
            }
                
        }
    }
                
    cout<<cnt<<'\n'; 
        
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    fact[0]=1;
    repe(i,MX-1)
        fact[i]=(i*fact[i-1])%MD;

   
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}



