// AUTHOR: SUMIT PRAJAPATI      
#include <bits/stdc++.h>
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
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 0 
 
 
 
 
 
void solve(){
  
    string s;
    cin>>s;
    int n=s.length();
    int a[n+1],dp[n+1]={0};;

    repe(i,n)
        a[i]=(s[i-1]=='(');
    repe(i,n){
        if(a[i]==0 && i>1){
            if(a[i-1]==1)
                dp[i]=(2+dp[i-2]);
            
            else if(a[i]!=a[i-dp[i-1]-1])
                    dp[i]=dp[i-1]+2+dp[i-dp[i-1]-2];

            
        }
    }  
    map<int,int>mp;
    // repe(i,n)
    //     cout<<a[i]<<" \n"[i==n];

    repe(i,n){
        mp[dp[i]]++;
        // cout<<dp[i]<<" ";
    }
    int len=0,count=1;
    for(auto el:mp){
        if(el.ff>len)
            len=el.ff,count=el.ss;
    }
    cout<<len<<" "<<count;

  //()(())()
 
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