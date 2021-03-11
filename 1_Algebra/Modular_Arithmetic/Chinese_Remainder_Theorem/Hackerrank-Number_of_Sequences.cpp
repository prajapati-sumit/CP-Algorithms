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
 
 
 
ll a[MX],cnt,freq[MX],LPF[MX]; 
bool isvalid(int n){
    repe(k,n){
        for(int m=2*k;m<=n;m+=k)
            if(a[m]!=-1 && a[k]!=-1 && abs(a[k]-a[m])%k!=0)
                return false;
    }
    return true;

}
void permute(int cur,int n){
    if(cur>n){
        if(isvalid(n)){
            cnt++;
            repe(i,n){
                cout<<a[i]<<" ";
                freq[i]+=(a[i]==0);
            }
            cout<<'\n';
        }
        return;

    }

    int l=0,r=cur-1;
    FOR(x,l,r){
        a[cur]=x;
        permute(cur+1,n);
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

ll lcm(ll n){
    map<ll,ll>mp;
    repe(i,n){
        if(a[i]==-1)
            continue;
        ll cur=i,curf=LPF[cur],cnt=0;
        
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
  
    
    // cnt=0;     
    // permute(1,6);
    // cout<<6<<"-> "<<cnt<<"\n";
    // repe(i,6)
    //     cout<<freq[i]<<" ";
    // cout<<'\n';
    ll n;
    cin>>n;
    ll ans=lcm(n);
    repe(i,n)
        cin>>a[i];
    if(!flag){
        cout<<"0";
        return;
    }
    ll divid=lcm(n);
    ans=(ans*bin_power(divid,MD-2,MD))%MD;
    cout<<ans<<'\n';
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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