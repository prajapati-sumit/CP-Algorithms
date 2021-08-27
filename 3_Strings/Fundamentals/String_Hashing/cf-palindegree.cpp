//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=5e6+2;

 
 

const int p=79,m=1e9+9;
int n;
bool ispalin(int j,int pref_hash[],int suff_hash[],int powp[]){
    int h_pref=pref_hash[j];
    int h_suff=(suff_hash[0]-(j<n-1?suff_hash[j+1]:0)+m)%m;
    int mul1=0,mul2=n-1-j;
    h_pref=(h_pref*powp[mul2-mul1])%m;
    
    return h_pref==h_suff;
}

void solve(){
  
    string s;
    cin>>s;
    n=s.length();
    int powp[n]; 
    powp[0]=1;
    repe(i,n-1)
        powp[i]=p*powp[i-1]%m;
    int ans=0;
    int pref_hash[n]; 
    int suff_hash[n]; 
    pref_hash[0]=s[0]-'0'+1;
    FOR(i,1,n-1)
        pref_hash[i]=(pref_hash[i-1]+(s[i]-'0'+1)*powp[i])%m;

    suff_hash[n-1]=s[n-1]-'0'+1;
    for(int i=n-2;i>=0;i--)
        suff_hash[i]=(suff_hash[i+1]+(s[i]-'0'+1)*powp[n-1-i])%m;

    int dp[n+1]={0};
    rep(i,n){
        if(i==0)
            dp[i]=1;
        else{
            if(ispalin(i,pref_hash,suff_hash,powp))
                dp[i]=1+dp[(i-1)/2];
        }
        ans+=dp[i];
    }
    
    cout<<ans<<'\n';

} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    

    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}