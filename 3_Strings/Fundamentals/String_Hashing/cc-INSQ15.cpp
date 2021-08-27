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
const int m=1e9+9;
const int p=26;
 
 
string s;
int powp[MX];
int pref_hash[MX],n;

bool isEqual(int i1,int j1,int i2,int j2){

    if(j1>i1 && j2>i2)
        return true;
    assert(j1-i1==j2-i2);
    if(i1>j1){
        swap(i1,i2);
        swap(j1,j2);
    }
    int hash1=(pref_hash[j1]-(i1>0?pref_hash[i1-1]:0)+m)%m;
    int hash2=(pref_hash[j2]-(i2>0?pref_hash[i2-1]:0)+m)%m;

    hash1=(hash1*powp[i2-i1])%m;

    return hash1==hash2;
}
void solve(){
    

    // Internal System Error on Codechef.
    // https://www.codechef.com/problems/INSQ15_A
    powp[0]=1;
    repe(i,MX-1)
        powp[i]=p*powp[i-1]%m;
    cin>>s;
    n=s.length();
    pref_hash[0]=s[0]-'a'+1;
    repe(i,n-1)
        pref_hash[i]=(pref_hash[i-1]+powp[i]*(s[i]-'a'+1))%m;
    int q;
    cin>>q;
    while(q--){
        int p;
        cin>>p;
        int l=0,r=min(p,n-p),ans=0,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(isEqual(0,mid-1,p,p+mid-1))
                l=mid+1,ans=mid;
            else
                r=mid-1;
        }
        cout<<ans<<'\n';
    }
 
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