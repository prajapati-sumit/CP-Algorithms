//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
// #define int                 long long           
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pb                  push_back
#define mk                  make_pair
#define ff                  first
#define ss                  second
#define all(a)              a.begin(),a.end()
#define trav(x,v)           for(auto &x:v)
#define rep(i,n)            for(int i=0;i<n;i++)
#define repe(i,n)           for(int i=1;i<=n;i++)
#define read(a,n)           rep(i,n)cin>>a[i]
#define reade(a,n)          repe(i,n)cin>>a[i]
#define FOR(i,a,b)          for(int i=a;i<=b;i++)
#define printar(a,s,e)      FOR(i,s,e)cout<<a[i]<<" ";cout<<'\n'
#define curtime             chrono::high_resolution_clock::now()
#define timedif(start,end)  chrono::duration_cast<chrono::nanoseconds>(end - start).count()




auto time0 = curtime;
const int MD=1e9+7;
const int MDL=998244353;
const int INF=1e9;
const int MX=2e5+5;

 
int segm[4*MX];
int a[MX];
int n,m;
void merge(int &A,int &B,int &res){
    res=max(A,B);
}
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur]=a[start];
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

}

void update(int cur,int start,int end,int ind,int val){
    if(start==ind && start==end){
        //DO UPDATE
        segm[cur]=a[start];
        return;
    }
    if(start>ind|| end<ind)
        return;          //OUT OF RANGE 
    int mid=(start+end)>>1;
    update(cur<<1,start,mid,ind,val);
    update((cur<<1)^1,mid+1,end,ind,val);
    //MERGING STEP
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);

} 
int query(int cur,int start,int end,int x){
        
    if(segm[cur]<x)
        return 0;
    while(start<end){
        int mid=(start+end)>>1;
        if(segm[2*cur]>=x){
            cur=2*cur;
            end=mid;
        }
        else{
            cur=2*cur+1;
            start=mid+1;
        }
    }
    assert(a[start]>=x);
    a[start]-=x;
    update(1,1,n,start,a[start]);
    return start;
}
 
void solve(){
  
    
    cin>>n>>m;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    repe(i,m){
        int x;
        cin>>x;
        cout<<query(1,1,n,x)<<" ";
    }
  
 
} 
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time0 = curtime;
    srand(time(NULL));
    int t=1;
    // cin>>t;
    repe(tt,t){
        // cout<<"Case #"<<tt<<": ";
        solve();
    }
    
    // cerr<<"Execution Time: "<<timedif(time0,curtime)*1e-9<<" sec\n";
    return 0;
 
}