//~ author      : Sumit Prajapati
#include <bits/stdc++.h>
using namespace std;


#define ull                 unsigned long long
#define ll                  long long
#define int                 long long           
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
const int MX=3e5+5;

 

int n;
int a[MX];
vector<int> segm[4*MX];
void merge(vector<int>& A,vector<int>& B,vector<int>& to){
    int szA=A.size(),szB=B.size(),i=0,j=0;
    while(i<szA && j<szB)
        (A[i]<B[j])?to.pb(A[i++]):to.pb(B[j++]);
    while(i<szA)
        to.pb(A[i++]);
    while(j<szB)
        to.pb(B[j++]);

}
void buildtree(int cur,int start,int end){
    if(start==end){
       //BASE CASE
        segm[cur].pb(a[start]);
        return;
    }
    int mid=(start+end)>>1;
    buildtree(cur<<1,start,mid);
    buildtree((cur<<1)+1,mid+1,end);
    merge(segm[2*cur],segm[2*cur+1],segm[cur]);
    //MERGING STEP


}
int query(int cur,int start,int end,int qs,int qe,int val){
    if(start>=qs && end<=qe){
        int res=upper_bound(all(segm[cur]),val)-segm[cur].begin();
        res=max(0LL,(int)segm[cur].size()-res);
        return res;
    }
    if(start>qe || end<qs)
        return 0;          //INVALID RETURN 
    int mid=(start+end)>>1;
    int A=query(2*cur,start,mid,qs,qe,val);
    int B=query(2*cur+1,mid+1,end,qs,qe,val);
    //MERGING STEP
    int res= A+B; 

    return res;
}

 
 
void solve(){
  
    cin>>n;
    repe(i,n)
        cin>>a[i];
    buildtree(1,1,n);
    int q;
    cin>>q;
    int l,r,k;
    while(q--){
        cin>>l>>r>>k;
        int ans=query(1,1,n,l,r,k);
        cout<<ans<<'\n';
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