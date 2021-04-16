//CODED BY SUMIT KUMAR PRAJAPATI
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

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
const int MAXLOG=18;
 
 
 
 
int sparse[MX][MAXLOG];
int n,q,a[MX];
void fill(){
    for(int i=1;i<=n;i++){
        sparse[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparse[i][j]=__gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }

}
int getGCD(int x,int y){
    if(y>n)
        return 0;
    int h=(int)log2(y-x+1);
    return  __gcd(sparse[x][h],sparse[y-(1<<h)+1][h]);
}
void solve(){
    
    map<int,ll>mp;
    cin>>n;
    repe(i,n)
        cin>>a[i];
    fill();

    repe(i,n){
        int cur_gcd=a[i],ind=i;
        while(ind<=n){
            int l=ind,r=n+1,mid,ans=n+1;
            while(l<=r){
                mid=(l+r)>>1;
                if(getGCD(i,mid)!=cur_gcd){
                    ans=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            
            mp[cur_gcd]+=(ans-ind);
            cur_gcd=getGCD(i,ans);
            ind=ans;
        }
    }

    cin>>q;
    int x;
    repe(i,q){
        cin>>x;
        cout<<mp[x]<<"\n";
    }
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