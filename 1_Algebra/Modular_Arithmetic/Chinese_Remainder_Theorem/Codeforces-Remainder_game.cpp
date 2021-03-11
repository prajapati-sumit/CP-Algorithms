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
const int MX=1e6+5;
ll MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
ll a[MX],LPF[MX];

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
ll lcm(ll n){
    map<ll,ll>mp;
    repe(i,n){
        
        ll cur=a[i],curf=LPF[cur],cnt=0;
        
        while(cur>1){
            
            cur/=LPF[cur];
            cnt++;
            if(LPF[cur]!=curf){
                mp[curf]=max(mp[curf],cnt);
                curf=LPF[cur];
                cnt=0;
            }
        }
       
    }
    ll ans=1;
    for(auto x:mp)
        ans=(ans*bin_power(x.ff,x.ss,MD))%MD;
    return ans;
} 
 
 
void solve(){
    ll n,k;
    cin>>n>>k;
    if(k==1){
        cout<<"Yes";
        return;
    }
    bool flag=false;
    repe(i,n)
        cin>>a[i];
      
    MD=k;
    ll L=lcm(n);
    if(L!=0)cout<<"No";
    else cout<<"Yes";


        
  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;


    repe(i,MX-1)
        LPF[i]=i;
    FOR(i,2,MX-1){
        if(LPF[i]==i){
            for(int j=2*i;j<MX;j+=i)
                if(LPF[j]==j)
                    LPF[j]=i;
        }
    }
    solve();
    
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}