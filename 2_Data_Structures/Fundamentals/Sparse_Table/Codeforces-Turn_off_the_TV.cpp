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
const int MX=8e5+5;
const int MD=1e9+7;
const int MDL=998244353;
auto time0 = curtime;
#define TESTCASES 0 
const int MAXLOG=19;
 
int a[MX], sparsemin[MX][MAXLOG];
pair<int,int> ranges[MX];
int cnt=0;
void fill(){
   
    for(int i=1;i<=cnt;i++){
        sparsemin[i][0]=a[i];
    }
    for(int j=1;j<=MAXLOG;j++){
        for(int i=1;(i+(1<<j)-1)<=cnt && i<=cnt;i++){
            sparsemin[i][j]=min(sparsemin[i][j-1],sparsemin[i+(1<<(j-1))][j-1]);
        }
    }
}

int getmin(int x,int y){
    if(x>y)
        return -INF;
    int h=(int)log2(y-x+1);
    return min(sparsemin[x][h],sparsemin[y-(1<<h)+1][h]);
} 
 
 
void solve(){
    
    int n;
    cin>>n;    
    map<int,vector<pii> >mp;
    int l,r;
    repe(i,n){
        cin>>l>>r;
        mp[l].pb({i,0});
        mp[r].pb({i,1});
    }
    int prev=0;
    for(auto cur:mp){
        // cout<<cur.ff<<" "<<prev<<" \n";
        cnt++;
        if(cur.ff-prev>=2)
            cnt++;
        prev=cur.ff;
        trav(cur.ss){
            if(el.ss==0){
                ranges[el.ff].ff=cnt;
                a[cnt]+=1;
            }
            else{
                ranges[el.ff].ss=cnt;
                a[cnt+1]-=1;
            }
        }   
        
    }
    
    repe(i,MX-1)
            a[i]+=a[i-1];
    fill();
    // repe(i,10)
    //     cout<<a[i]<<" \n"[i==10];


    repe(i,n){
        // cout<<ranges[i].ff<<" "<<ranges[i].ss<<"\n";
        if(getmin(ranges[i].ff,ranges[i].ss)>1){
            cout<<i;
            return;
        }
    }
    cout<<"-1";
    return;


 
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