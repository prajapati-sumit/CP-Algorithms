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
const int MX=1505;

const int p=101;
int powp[MX]; 
 
 
 
void solve(){
  
    string s;
    cin>>s;
    string isbad;
    cin>>isbad;
    int k;
    cin>>k;
    set<int>st;
    int n=s.length();
    rep(i,n){
        int cur_hash1=0;
        int cur_hash2=0;
        int bad=0;
        for(int j=i;j<n;j++){
            cur_hash1=(cur_hash1+(s[j]-'a'+1)*powp[j-i]);
            bad+=(isbad[s[j]-'a']=='0');
            if(bad<=k){
                st.insert(cur_hash1);
            }

        }
    }
    cout<<(int)st.size()<<'\n';
 
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
        powp[i]=p*powp[i-1];
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}