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
 
 
 
int n,m;
int a[MX],dif[MX]; 
int sparsemax[MX][MAXLOG];

void fill(){
   
    for(int i=1;i<=n;i++){
        sparsemax[i][0]=dif[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemax[i][j]=max(sparsemax[i][j-1],sparsemax[i+(1<<(j-1))][j-1]);
        }
    }
}

int getmax(int x,int y){
    int h=(int)log2(y-x+1);
    return max(sparsemax[x][h],sparsemax[y-(1<<h)+1][h]);
}

int binary(int targ){
    int l=1,r=n,mid;

    int ans=1;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]<=targ){
            ans=mid;
            l=mid+1;
        }
        else
            r=mid-1;
    }
    return ans;
}
void solve(){
  
    cin>>n;
    repe(i,n)cin>>a[i];
    repe(i,n-1)dif[i]=a[i+1]-a[i];
    dif[n]=0;
    fill();
    int q;
    cin>>q;
    while(q--){
        int t,d;
        cin>>t>>d;
        int ind=binary(t);
        int l=1,r=ind,mid,ans=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(mid==ind){
                ans=mid;
                break;
            }
            // cout<<mid<<" "<<ind<<" "<<getmax(mid,ind)<<'\n';
            if(getmax(mid,ind-1)<=d){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        // assert(ans!=-1);
        cout<<ans<<'\n';
    }
 
} 
 
/*
5
1 2 3 10 50
7 8 9 16 56
1 1 7 40 0
*/
 
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