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
const int MDL=998244353;
const int INF=1e9;
const int MX=1e5+5;


const int m=1e9+9;
const int m2=1e9+7;
const int p=26;

int powp[MX];
int powp2[MX];
 
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

const int inv_p=bin_power(p,m-2,m);
const int inv_p2=bin_power(p,m2-2,m2);


  
void solve(){

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    set<pii>st;
    int cur_hash=0;
    int cur_hash2=0;
    rep(i,k){
        cur_hash=(cur_hash+(s[i]-'a'+1)*powp[i])%m;
        cur_hash2=(cur_hash2+(s[i]-'a'+1)*powp2[i])%m2;
    }
    st.insert({cur_hash,cur_hash2});
    FOR(i,k,n-1){
        cur_hash=(cur_hash+m-(s[i-k]-'a'+1))%m;
        cur_hash=(cur_hash*inv_p)%m;
        cur_hash=(cur_hash+powp[k-1]*(s[i]-'a'+1))%m;

        cur_hash2=(cur_hash2+m2-(s[i-k]-'a'+1))%m2;
        cur_hash2=(cur_hash2*inv_p2)%m2;
        cur_hash2=(cur_hash2+powp2[k-1]*(s[i]-'a'+1))%m2;
        st.insert({cur_hash,cur_hash2});
    }
    cout<<st.size()<<'\n';
    

}
        
  
 

 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    powp[0]=1;
    repe(i,MX-1)
        powp[i]=p*powp[i-1]%m;
    powp2[0]=1;
    repe(i,MX-1)
        powp2[i]=p*powp2[i-1]%m2;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}