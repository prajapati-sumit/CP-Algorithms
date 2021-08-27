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

 
// const int MX=1e5+5;

// int pi[MX];

// void calc_pi(const string& s){
//     int n=s.length();
//     for(int i=1;i<n;i++){
//         int j=pi[i-1];
//         while(j>0 && s[i]!=s[j])
//             j=pi[j-1];
//         if(s[i]==s[j])
//             j++;
//         pi[i]=j;
//     }
// }

 
 
void solve(){
  
    // Can't DO.
    string s;
    cin>>s;
    
    int n=s.length();
    int dp[n+2];

    dp[n+1]=0;

    for(int i=n;i>=1;i--){
        
        vector<int>pi;
        pi.pb(0);
        int res=0,len=0;
        for(int ii=1;ii+i<n;ii++){
            int j=pi[ii-1];
            while(j>0 && s[i+ii-1]!=s[i+j])
                j=pi[j-1];
            if(s[i+ii-1]==s[i+j])
                j++;
            pi.pb(j);
            int len=1+ii;
            int rep_unit=len-j;
            int terms=0;
            if(len%rep_unit==0){
                terms=len/rep_unit;
            }
            else
                terms=1;
            if(terms>res)
                res=terms,len=1+ii;
            
        }
        if(i==8){
            // cout<<pi[ii]<<" ";
            cout<<res<<" "<<len<<'\n';
        }
        if(res==0){
            dp[i]=min(2+dp[i+1],1+(n-i+1));
            cerr<<i<<" ->"<<dp[i]<<"\n";

            continue;
        }

        string tmp=to_string(len/res);
        dp[i]=tmp.length()+res;
        dp[i]+=(i+len<=n+1?dp[i+len]:0);
        cerr<<i<<" ->"<<dp[i]<<"\n";
    }
    cout<<dp[1]<<'\n';
  
 
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