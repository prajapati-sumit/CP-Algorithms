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
auto time0 = curtime;
const int MAXLOG=18;
 
 
 
 
int n,q;
int a[MX];

int sparsemin[MX][MAXLOG];
int sparsemax[MX][MAXLOG];

void fill(){
    for(int i=1;i<=n;i++){
        sparsemin[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemin[i][j]=min(sparsemin[i][j-1],sparsemin[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        sparsemax[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemax[i][j]=max(sparsemax[i][j-1],sparsemax[i+(1<<(j-1))][j-1]);
        }
    }
}

int getmin(int x,int y){
    if(x>y)
        return INF;
    int h=(int)log2(y-x+1);
    return min(sparsemin[x][h],sparsemin[y-(1<<h)+1][h]);
}

int getmax(int x,int y){
    if(x>y)
        return -INF;
    int h=(int)log2(y-x+1);
    return max(sparsemax[x][h],sparsemax[y-(1<<h)+1][h]);
}

void solve(){
  
    cin>>n;
    repe(i,n)
        cin>>a[i];

    fill();
    

    int x,y;
    cin>>q;
    repe(i,q){
        double ans=0;
        cin>>x>>y;
        x++,y++;
        ans=getmin(x,y);
        int sec=getmax(x,y);
        int fir=max(getmax(1,x-1),getmax(y+1,n));
        ans+=max((double)fir,(sec-ans)/2.0);

        printf("%0.1f\n",ans);
        
    }
  
 
} 

 
// ans=min(l,r)+max(rest ai,in range (ai-mn)/2)
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