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

const int INF=1e9;
const int MX=1e5+5;
const int MD=1e9+7;
const int MDL=99824453;
auto time0 = curtime;
 
 
 
 
int G(int x){
    return x^(x>>1);
} 
 
void solve(){
  
    
    int n,m;
    cin>>n>>m;
    int limit=(1<<(n+m));
    vector<int>Gray;
    rep(i,limit)
        Gray.pb(G(i));
         
    
    
    n=(1<<n);
    m=(1<<m);
    int a[n][m];
    int ind=0;
    if(n<=m){
        rep(i,m){
            rep(j,n){
                if(i&1)
                    a[n-j-1][i]=Gray[ind++];
                
                else
                    a[j][i]=Gray[ind++];
            }
        }
    }
    else{
        rep(i,n){
            rep(j,m){
                if(i&1)
                    a[i][m-j-1]=Gray[ind++];
                
                else
                    a[i][j]=Gray[ind++];
            }
        }

    }
    rep(i,n){
        rep(j,m)
            cout<<a[i][j]<<" ";
        cout<<'\n';
    }
  
 
} 
 
 
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}