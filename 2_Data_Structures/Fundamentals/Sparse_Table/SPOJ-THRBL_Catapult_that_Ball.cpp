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
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ll i=0;i<n;i++)
#define repe(i,n) for(ll i=1;i<=n;i++)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
const int MAXLOG=18;
auto time0 = curtime;
 
 
 
 
 
int n,q;
int a[MX];
int sparse[MX][MAXLOG];
void fill(){
    for(int i=1;i<=n;i++){
        sparse[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }

}
void solve(){
  
    cin>>n;
    cin>>q;
    repe(i,n)
        cin>>a[i];

    fill();
    

    int x,y;
    int ans=0;
    repe(i,q){
        cin>>x>>y;
        if(x==y || (x==(y-1))){
            ans++;
            continue;
        }
        x++,y--;
        int h=(int)log2(y-x+1);
        int here=max(sparse[x][h],sparse[y-(1<<h)+1][h]);
        ans+=(here<a[x-1]);
    }
    cout<<ans<<'\n';
  
 
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
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}