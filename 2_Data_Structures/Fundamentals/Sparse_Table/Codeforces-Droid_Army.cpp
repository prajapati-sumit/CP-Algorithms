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
const int MAXLOG=18;
 
 
 
 
int sparse[5][MX][MAXLOG];
int n,m,k,a[MX][5];
void fill(){
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++)
            sparse[j][i][0]=a[i][j];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            for(int type=0;type<m;type++)
                sparse[type][i][j]=max(sparse[type][i][j-1],sparse[type][i+(1<<(j-1))][j-1]);
        }
    }

} 
 
bool canDo(int x,int y){
   
    int h=(int)log2(y-x+1);
    int sum=0;
    for(int i=0;i<m;i++)
        sum+=max(sparse[i][x][h],sparse[i][y-(1<<h)+1][h]);
    
    return sum<=k;
}
 
 
void solve(){
    
    cin>>n>>m>>k;
    repe(i,n){
        rep(j,m){
            cin>>a[i][j];
        }
    }
    fill();
    int bestLengthSoFar=0,s_range=0,e_range=0;
    repe(i,n){

        int l=i,r=n,mid;
        while(l<=r){
            mid=(l+r)>>1;
            
            if(canDo(i,mid)){
                if(bestLengthSoFar<mid-i+1){
                    bestLengthSoFar=mid-i+1;
                    s_range=i;
                    e_range=mid;
                }
                l=mid+1;
            }
            else r=mid-1;
        }

    }
    int x=s_range,y=e_range;
    int h=(int)log2(y-x+1);
    for(int i=0;i<m;i++){
        int cur=max(sparse[i][x][h],sparse[i][y-(1<<h)+1][h]);
        cout<<cur<<" ";
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