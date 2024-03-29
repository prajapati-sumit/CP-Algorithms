// AUTHOR: SUMIT PRAJAPATI      
#include "bits/stdc++.h"
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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()
#define TESTCASES 0

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
 
 
 
 
 
 
void solve(){
  
    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    rep(i,n)
        cin>>v[i];    
    if(k==1){
        int ans=*min_element(v.begin(),v.end());
        cout<<ans;
    }
    else if(k==2){
        int best=v[0];
        int pref[n],suf[n];
        rep(i,n)
            pref[i]=(i==0)?v[0]:min(v[i],pref[i-1]);
        for(int i=n-1;i>=0;i--)
            suf[i]=(i==n-1)?v[n-1]:min(v[i],suf[i+1]);

        rep(i,n-1){
            int t=max(pref[i],suf[i+1]);
            if(t>best)
                best=t;
        }
        cout<<best;
    }
    else{
        int ans=*max_element(v.begin(),v.end());
        cout<<ans;
    }
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}