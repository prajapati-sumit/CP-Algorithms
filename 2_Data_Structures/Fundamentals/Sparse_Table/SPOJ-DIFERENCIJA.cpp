// AUTHOR: SUMIT PRAJAPATI      
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long pdsfll;
typedef long long ull;
typedef pair<ull, ull>  pii;
typedef pair<ull, ull>  pl;

#define PI 3.1415926535897932384626
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define trav(v) for(auto &el:v)
#define watch(x) cerr<<#x<<" = "<<x<<'\n'
#define rep(i,n) for(ull i=0;i<n;i++)
#define repe(i,n) for(ull i=1;i<=n;i++)
#define FOR(i,a,b) for(ull i=a;i<=b;i++)
#define printar(a,s,e) FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime chrono::high_resolution_clock::now()
#define timedif(start,end) chrono::duration_cast<chrono::nanoseconds>(end - start).count()


const ull INF=1e9;
const ull MX=3e5+5;
const ull MD=1e9+7;
const ull MDL=998244353;
auto time0 = curtime;
#define TESTCASES 0 
const ull MAXLOG=19;

ull sparsemin[MX][MAXLOG];
ull sparsemax[MX][MAXLOG];
ull n,a[MX],LOGS[MX];

void fill(){
    for(ull i=1;i<=n;i++){
        sparsemin[i][0]=a[i];
    }
    for(ull j=1;j<=MAXLOG;j++){
        for(ull i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemin[i][j]=min(sparsemin[i][j-1],sparsemin[i+(1<<(j-1))][j-1]);
        }
    }
    for(ull i=1;i<=n;i++){
        sparsemax[i][0]=a[i];
    }
    for(ull j=1;j<=MAXLOG;j++){
        for(ull i=1;(i+(1<<j)-1)<=n && i<=n;i++){
            sparsemax[i][j]=max(sparsemax[i][j-1],sparsemax[i+(1<<(j-1))][j-1]);
        }
    }
}

ull getmin(ull x,ull y){
    if(x>y)
        return INF;
    ull h=LOGS[(y-x+1)];
    return min(sparsemin[x][h],sparsemin[y-(1<<h)+1][h]);
}

ull getmax(ull x,ull y){
    if(x>y)
        return 0;
    ull h=LOGS[(y-x+1)];
    return max(sparsemax[x][h],sparsemax[y-(1<<h)+1][h]);
} 
 
 
void solve(){
  
    cin>>n;
    repe(i,n)
        cin>>a[i];
    fill();
    ull ans=0;
    repe(i,n){
        ull ilmax=i,irmax=i,ilmin=i,irmin=i;
        ull l=1,r=i,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(getmax(mid,i)==a[i]){
                ilmax=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        l=i;r=n;
        while(l<=r){
            mid=(l+r)>>1;
            if(getmax(i+1,mid)<a[i]){
                irmax=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        l=1;r=i;
        while(l<=r){
            mid=(l+r)>>1;
            if(getmin(mid,i)==a[i]){
                ilmin=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        l=i;r=n;
        while(l<=r){
            mid=(l+r)>>1;
            if(getmin(i+1,mid)>a[i]){
                irmin=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        ull n_max=(i-ilmax+1)*(irmax-i+1),n_min=(i-ilmin+1)*(irmin-i+1);
        // cout<<n_max<<" "<<n_min<<" "<<a[i]<<"\n";
        ans+=(ull)n_max*a[i]-n_min*a[i];


    }
    cout<<ans<<'\n';

  
 
} 
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    srand(time(0)); 
    time0 = curtime;
    LOGS[1]=0;
    FOR(i,2,MX-1)
        LOGS[i]=LOGS[i/2]+1;

    ull t=1;
    if(TESTCASES)cin>>t;
    repe(tt,t){
        //cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    //cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}