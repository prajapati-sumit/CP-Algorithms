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
 
 
 
pair<int,int> dp[1001][1001],dp2[1001][1001]; 
 
void solve(){
    
    //2D SPARSE TABLE.....!!
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    repe(i,n){
        repe(j,m){
        
            cin>>a[i][j];
            if(a[i][j]==1){
                dp[i][j].ff=1;
                if(i>1 && j>1)
                    dp[i][j].ff+=min({dp[i-1][j-1].ff,dp[i][j-1].ff,dp[i-1][j].ff});
            }
            dp[i][j].ss=max({dp[i][j].ff,dp[i][j-1].ss,dp[i-1][j].ss});
            

        }
    }
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            if(a[i][j]==1){
                dp2[i][j].ff=1;
                if(i<n && j<m)
                    dp2[i][j].ff+=min({dp2[i+1][j+1].ff,dp2[i][j+1].ff,dp2[i+1][j].ff});
                
            }
            dp2[i][j].ss=max({dp2[i][j].ff,dp2[i][j+1].ss,dp2[i+1][j].ss});
        }
    }
    // repe(i,n)
    // {
    //     repe(j,m)
    //         cout<<dp[i][j].ss<<" ";
    //     cout<<'\n';
    // }
    // return;
    int q;
    cin>>q;
    int x1,y1,x2,y2;
    repe(i,q){
        cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2].ss<<" "<<dp2[x1][y1].ss<<"-> ";
        cout<<min({n,m,dp[x2][y2].ss,dp2[x1][y1].ss})<<'\n';
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