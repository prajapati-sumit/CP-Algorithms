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
const int MAXLOG=18;
 
int sparsemax[MX][MAXLOG];
vector<ll> dp(MX,0);
int n;
int a[MX];
void fill(){
   
    for(int i=1;i<=n;i++){
        sparsemax[i][0]=i;
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemax[i][j]=a[sparsemax[i][j-1]]>a[sparsemax[i+(1<<(j-1))][j-1]]?sparsemax[i][j-1]:sparsemax[i+(1<<(j-1))][j-1];
        }
    }
}

int getmax(int x,int y){
    int h=(int)log2(y-x+1);
    return a[sparsemax[x][h]]>a[sparsemax[y-(1<<h)+1][h]]?sparsemax[x][h]:sparsemax[y-(1<<h)+1][h];
} 
 
 
void solve(){
  
    //FINALLLY DP...!!!
    cin>>n;
    
    repe(i,n-1)
        cin>>a[i];
    a[n]=n;
    ll ans=0;
    fill();
    

    for(int i=n-1;i>=1;i--){
        int ind=getmax(i,a[i]);
        // cout<<i<<" "<<a[i]<<"-> "<<ind<<'\n';
        dp[i]=(n-i)+dp[ind]-(a[i]-ind);
        ans+=dp[i];
    }
    // repe(i,n)
    //     cout<<dp[i]<<" ";
    // cout<<'\n';

    cout<<ans<<'\n';
 
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