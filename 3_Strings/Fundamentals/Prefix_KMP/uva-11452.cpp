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

 
const int MX=2e3+5;

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
    int ind=-1;
    // rep(i,n)
    //     cout<<pi[i]<<"\n "[i<n-1];
    for(int i=n-1;i>=0;i--){
        int k=(i+1)-pi[i];
        if((i+1)==2*k){
            ind=i;
            break;
        }
    }
    assert(ind!=-1);
    ind/=2;
    int rem=(n-ind-1);
    string tmp=s.substr(0,ind+1);
    string res;
    rep(i,10)
        for(auto &el:tmp)
            res.pb(el);
    int sz=res.size();
    int cnt=0;
    FOR(i,rem,sz-1){
        if(cnt==8)
            break;
        cout<<res[i];
        cnt++;
    }
    cout<<"...";
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    cin>>t;
    while(t--){
        // cout<<"Case #"<<tt<<": ";
        solve();
        if(t)
            cout<<'\n';
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}