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
const int MX=5002;

 
 
string s;
int pref_hash[MX]; 
int suff_hash[MX]; 
int powp[MX]; 
int n;
const int p=31,m=1e9+9;
int dp[MX][MX];

bool ispalin(int i, int j){
    int h_pref=(pref_hash[j]-(i>0?pref_hash[i-1]:0)+m)%m;
    int h_suff=(suff_hash[i]-suff_hash[j+1]+m)%m;
    int mul1=i,mul2=n-1-j;
    if(mul1<mul2){
        h_pref=(h_pref*powp[mul2-mul1])%m;
    }
    else{
        h_suff=(h_suff*powp[mul1-mul2])%m;

    }
    
    return h_pref==h_suff;
}
// recursive dp
int f(int i,int j){

    if(i>j)
        return
    if(i==j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(ispalin(i,j))
        return dp[i][j]=1+f(i,(i+j-1)/2);
    return 0;
}
void solve(){
  
    cin>>s;
    n=s.length();
    vector<int>ans(n+1,0);
    memset(dp,-1,sizeof(dp));
    pref_hash[0]=s[0]-'a'+1;
    FOR(i,1,n-1)
        pref_hash[i]=(pref_hash[i-1]+(s[i]-'a'+1)*powp[i])%m;

    suff_hash[n-1]=s[n-1]-'a'+1;
    for(int i=n-2;i>=0;i--)
        suff_hash[i]=(suff_hash[i+1]+(s[i]-'a'+1)*powp[n-1-i])%m;

    rep(i,n){
        for(int j=i;j<n;j++){
            int val=f(i,j);
            // cout<<i<<" "<<j<<" "<<val<<'\n';
            ans[val]++;
        }
    }
    
    for(int i=n-1;i>=1;i--)
        ans[i]+=ans[i+1];
    repe(i,n)
        cout<<ans[i]<<" ";
    cout<<'\n';
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    powp[0]=1;
    repe(i,MX-1)
        powp[i]=p*powp[i-1]%m;

    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}