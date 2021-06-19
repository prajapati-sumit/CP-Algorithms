//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
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
const int MX=1e5+5;

 
 
 
 
void solve(){
  
    int n,q;
    cin>>n>>q;
    int a[n+1];
    int jumps[n+1];
    int last[n+1];
    repe(i,n)
        cin>>a[i];
    for(int i=n;i>=1;i--){
        jumps[i]=(i+a[i])>n?1:1+jumps[i+a[i]];
        last[i]=(i+a[i])>n?i:last[i+a[i]];
    }       
    int t,x,y;
    repe(i,q){
        cin>>t>>x;
        if(t==0){
            cin>>y;
            a[x]=y;
            jumps[x]=(x+a[x])>n?1:1+jumps[x+a[x]];
            last[x]=(x+a[x])>n?x:last[x+a[x]];
        }
        else{
            cout<<last[x]<<" "<<jumps[x]<<'\n';
        }
    }
    repe(i,n)
        cout<<jumps[i]<<" \n"[i==n];
    repe(i,n)
        cout<<last[i]<<" \n"[i==n];

  
 
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