//CODED BY SUMIT KUMAR PRAJAPATI
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
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=100;
const int MX=3e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
int a[20][20];
int n,m;
vector<int>v[20];
int dp[MX];
bool iscomplete(int bits){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((1<<i)&bits && (1<<j)&bits &&a[i+1][j+1]==0)
                return false;
        }
    }
    return true;
}

int f(int cur){
    if(dp[cur]!=-1)
        return dp[cur];
    //cout<<bitset<5>(cur)<<" -> "<<iscomplete(cur)<<'\n';
    if(iscomplete(cur))
        return dp[cur]=1;
    int ans=INF;
    for(int s=(cur-1)&cur;s;s=(s-1)&cur){

        ans=min(ans,f(s)+f(s^cur));
        
    }
    return dp[cur]=ans;
}

void solve(){
    
    cin>>n>>m;
    int x,y;
    repe(i,m){
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
        v[x].pb(y);
        v[y].pb(x);
    }
    int cur=(1<<n)-1;
    memset(dp,-1,sizeof(dp));
    //cout<<cur;
    cout<<f(cur);
    //cout<<iscomplete(11);
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    //cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}