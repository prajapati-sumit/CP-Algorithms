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
const int MX=2e5+2;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
ll phi[MX];
bool flag=true;
 
void init(){
    repe(i,MX-1)
        phi[i]=i;
    for(ll i=2;i<MX;i++){
        if(phi[i]==i){
            for(ll j=i;j<MX;j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    // repe(i,10)
    //     cout<<phi[i]<<" ";
    // cout<<'\n';
    phi[0]=1;
    repe(i,MX-1)
        phi[i]+=phi[i-1];


} 
ll binary(ll n){
    ll l=0,r=MX-1,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(phi[mid]<n){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
} 
void solve(){
  
    ll n;
    cin>>n;
    if(n==0){
        flag=false;
        return;
    }
    ll ind=binary(n);
    n-=phi[ind];
    ind++;
    int denm=ind,num=0;
    repe(i,ind){
        if(n==0)
            break;
        if(__gcd(i,ind)==1){
            n--;
            num=i;
        }   
    }
    cout<<num<<"/"<<denm<<'\n';
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
    
    init();
    while(flag)
        solve();
    
    auto timeend=curtime;
    auto extime=timedif(time0,timeend)*1e-9;
    cerr<<"Execution Time: "<<extime<<" sec\n";
    return 0;
 
}