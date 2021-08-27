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

 
 
const int MX=105;

int pi[MX];

void calc_pi(const string& s){
    int n=s.length();
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            j++;
        pi[i]=j;
    }
}
 
 
void solve(){
  
           
    string s;
    cin>>s;
    int n=s.length();
    calc_pi(s);
    if(pi[n-1]>0 && n%(n-pi[n-1])==0){
        cout<<n-pi[n-1];
    }
    else
        cout<<n;
    cout<<'\n';
 
} 
 
 
int32_t main() {

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    while(t--){
        // cout<<"Case #"<<tt<<": ";
        solve();
        if(t)
            puts("");
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}