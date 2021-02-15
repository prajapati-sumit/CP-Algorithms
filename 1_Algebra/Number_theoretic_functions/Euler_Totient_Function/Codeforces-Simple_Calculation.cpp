#include <bits/stdc++.h>
using namespace std;
 
//CODED BY SUMIT KUMAR PRAJAPATI
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;

#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
ll bin_power(ll a, ll b,ll md){
    if(b==0)
        return 1;
    a%=md;
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%md;
        a=(a*a)%md;
        b>>=1;
    }
    return res;
} 
ll phi(ll x){
    ll res=x;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            while(x%i==0)
                x/=i;
            res-=res/i;
        }
    }
    if(x>1)
        res-=res/x;
    return res;
}
 
void solve(){
    

    ll n,k;
    cin>>n>>k;
    ll ans;
    if(k&1){
        ans=(bin_power(2,bin_power(2,n,phi(k)),k)+1)%k;
        cout<<ans;
        return;
    }
    if(n<=20){
        ans=(bin_power(2,1<<n,k)+1)%k;
        cout<<ans;
        return;
    }
    ll temp=k,cnt=0;
    while(temp%2==0){
        cnt+=1;
        temp>>=1;
    }
    //cout<<temp<<" "<<cnt<<"\n";
    ll p=phi(temp);
    ans=(((1<<cnt)%k)*bin_power(2,((bin_power(2,n,p)-cnt)%p+p)%p,temp))%k;
    ans=(ans+1)%k;
    cout<<ans;
    
 
} 
 
 
int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    #endif

    srand(time(0)); 

    time0 = curtime;
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}