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
const int MX=1e4+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 1 
const int MAXLOG=16;
 
int sparsemin[MX][MAXLOG];
int a[MX];
int res[MX];
int n;

void fill(){
    for(int i=1;i<=n;i++){
        sparsemin[i][0]=i;
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemin[i][j]=a[sparsemin[i][j-1]]<a[sparsemin[i+(1<<(j-1))][j-1]]?sparsemin[i][j-1]:sparsemin[i+(1<<(j-1))][j-1];
        }
    }
}

int getmin(int x,int y){
    if(x<=0)
        x=1;
    int h=(int)log2(y-x+1);
    return a[sparsemin[x][h]]<a[sparsemin[y-(1<<h)+1][h]]?sparsemin[x][h]:sparsemin[y-(1<<h)+1][h];
} 
 
 
void solve(){
  
    int h,b,e;
    cin>>h>>b>>e;
    repe(i,n)
        cin>>a[i];
    fill();
    vector<int>res(n+1,0);
    for(int i=e;i>=b;i--){
        int x=i-h,y=i;
        int ind=getmin(x,y);
        // cout<<a[i]<<" "<<ind<<"\n";
        res[ind]++;
    }
    FOR(i,b,e)
        cout<<res[i]<<" ";
    cout<<'\n';

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;

    ll t=1;
    while(cin>>n){
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}